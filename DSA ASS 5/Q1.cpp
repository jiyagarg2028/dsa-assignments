#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Node " << value << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Node " << value << " inserted at the end." << endl;
    }

    void insertBefore(int value, int key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == key) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node " << key << " not found!" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node " << value << " inserted before " << key << "." << endl;
    }

    void insertAfter(int value, int key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << key << " not found!" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node " << value << " inserted after " << key << "." << endl;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Node " << temp->data << " deleted from the beginning." << endl;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            cout << "Node " << head->data << " deleted from the end." << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        cout << "Node " << temp->next->data << " deleted from the end." << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int value) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node " << value << " not found!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Node " << value << " deleted." << endl;
        delete nodeToDelete;
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        int position = 1;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
            position++;
        }

        if (temp == nullptr) {
            cout << "Node " << value << " not found!" << endl;
        } else {
            cout << "Node " << value << " found at position " << position << " from head." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, key;

    while (true) {
        cout << "\nSingly Linked List Operations =" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert before a specific node" << endl;
        cout << "4. Insert after a specific node" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete a specific node" << endl;
        cout << "8. Search for a node" << endl;
        cout << "9. Display all nodes" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter key (insert before): ";
                cin >> key;
                list.insertBefore(value, key);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter key (insert after): ";
                cin >> key;
                list.insertAfter(value, key);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteSpecific(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}