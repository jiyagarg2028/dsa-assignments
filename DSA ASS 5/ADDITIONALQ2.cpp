#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data) {
    if (head == nullptr) {
        head = createNode(data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = createNode(data);
}

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }

    // Check if there are k nodes remaining
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == nullptr) {
            return head; 
        }
        temp = temp->next;
    }

    
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    for (int i = 0; i < k; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Recursively reverse next k groups
    head->next = reverseKGroup(current, k);

    return prev;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Enter k (group size): ";
    cin >> k;

    cout << "\nOriginal Linked List: ";
    display(head);

    head = reverseKGroup(head, k);

    cout << "Result: ";
    display(head);

    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}