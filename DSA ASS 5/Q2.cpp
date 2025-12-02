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

int countAndDelete(Node*& head, int key) {
    int count = 0;
    
    // Count occurrences
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Delete all occurrences
    while (head != nullptr && head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    if (head == nullptr) {
        return count;
    }

    temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }

    return count;
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
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Original Linked List: ";
    display(head);

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = countAndDelete(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}