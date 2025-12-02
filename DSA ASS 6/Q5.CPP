#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true; // Loop detected
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    // Check if it's a circular list (last node points to head)
    if (fast == nullptr || fast->next == nullptr) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->next == head;
    }

    return false;
}

void makeCircular(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < 20) { // Prevent infinite loop display
        cout << temp->data;
        if (temp->next != nullptr && count < 19) {
            cout << " -> ";
        }
        temp = temp->next;
        count++;
    }
    if (count == 20 && temp != nullptr) {
        cout << " ... (circular)";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "\nMake it circular? (1 for yes, 0 for no): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        makeCircular(head);
        cout << "Made the list circular." << endl;
    }

    cout << "\nLinked List: ";
    display(head);

    if (isCircular(head)) {
        cout << "\nResult: True - The linked list is circular!" << endl;
    } else {
        cout << "\nResult: False - The linked list is not circular." << endl;
    }

    return 0;
}