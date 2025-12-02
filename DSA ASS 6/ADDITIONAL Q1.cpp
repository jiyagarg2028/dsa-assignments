#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitCircularList(Node* head, Node*& list1, Node*& list2) {
    if (head == nullptr || head->next == head) {
        list1 = head;
        list2 = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // First list
    list1 = head;
    Node* list1Tail = slow;

    // Second list
    list2 = slow->next;

    // Make first list circular
    list1Tail->next = list1;

    // Make second list circular
    Node* temp = list2;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = list2;
}

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& last, int data) {
    Node* newNode = createNode(data);

    if (last == nullptr) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void displayCircular(Node* last) {
    if (last == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = last->next;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != last->next) {
            cout << " -> ";
        }
    } while (temp != last->next);
    cout << endl;
}

int main() {
    Node* last = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(last, value);
    }

    cout << "\nOriginal Circular List: ";
    displayCircular(last);

    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Node* list1last = nullptr;
    Node* list2last = nullptr;

    if (last != nullptr) {
        Node* head = last->next;
        splitCircularList(head, list1, list2);

        // Find last nodes for display
        if (list1 != nullptr) {
            Node* temp = list1;
            while (temp->next != list1) {
                temp = temp->next;
            }
            list1last = temp;
        }

        if (list2 != nullptr) {
            Node* temp = list2;
            while (temp->next != list2) {
                temp = temp->next;
            }
            list2last = temp;
        }
    }

    cout << "\nFirst Half: ";
    displayCircular(list1last);

    cout << "Second Half: ";
    displayCircular(list2last);

    return 0;
}