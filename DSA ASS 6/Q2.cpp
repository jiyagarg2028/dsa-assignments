#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertEnd(int value) {
        Node* newNode = new Node;
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

    void displayWithHead() {
        if (last == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = last->next;
        int headValue = temp->data;

        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != last->next) {
                cout << " -> ";
            }
        } while (temp != last->next);

        // Print head value again at the end
        cout << " " << headValue << endl;
    }

    void display() {
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
};

int main() {
    CircularLinkedList cll;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        cll.insertEnd(value);
    }

    cout << "\nOriginal Circular List: ";
    cll.display();

    cout << "With head repeated at end: ";
    cll.displayWithHead();

    return 0;
}