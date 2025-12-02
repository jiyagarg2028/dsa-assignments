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

void detectAndRemoveLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Detect loop using Floyd's Cycle Detection
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // If no loop exists
    if (slow != fast) {
        cout << "No loop detected." << endl;
        return;
    }

    cout << "Loop detected!" << endl;

    // Find the start of the loop
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the loop
    fast->next = nullptr;
    cout << "Loop removed." << endl;
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

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < 20) { 
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
        count++;
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

    // Optionally create a loop for testing
    cout << "\nCreate a loop? (1 for yes, 0 for no): ";
    int createLoop;
    cin >> createLoop;

    if (createLoop && head != nullptr) {
        
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        // Create loop to second node (or head)
        Node* loopStart = head;
        for (int i = 0; i < 2 && i < n; i++) {
            loopStart = loopStart->next;
        }
        last->next = (loopStart != nullptr) ? loopStart : head;
        cout << "Loop created." << endl;
    }

    cout << "\nBefore loop removal: ";
    display(head);

    detectAndRemoveLoop(head);

    cout << "After loop removal: ";
    display(head);

    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}