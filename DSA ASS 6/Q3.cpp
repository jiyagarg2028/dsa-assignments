#include <iostream>

using namespace std;

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

struct CLLNode {
    int data;
    CLLNode* next;
};

class DoublyLinkedList {
private:
    DLLNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int value) {
        DLLNode* newNode = new DLLNode;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        DLLNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        DLLNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        DLLNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <=> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
private:
    CLLNode* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertEnd(int value) {
        CLLNode* newNode = new CLLNode;
        newNode->data = value;

        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    int getSize() {
        if (last == nullptr) {
            return 0;
        }

        int count = 0;
        CLLNode* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);

        return count;
    }

    void display() {
        if (last == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        CLLNode* temp = last->next;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != last->next) {
                cout << " -> ";
            }
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int n, value;

    cout << "Enter number of nodes for DLL: ";
    cin >> n;
    cout << "Enter " << n << " values for DLL: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        dll.insertEnd(value);
    }

    cout << "\nDoubly Linked List: ";
    dll.display();
    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;

    cout << "\nEnter number of nodes for CLL: ";
    cin >> n;
    cout << "Enter " << n << " values for CLL: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        cll.insertEnd(value);
    }

    cout << "\nCircular Linked List: ";
    cll.display();
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}