#include <iostream>
#include <cstdlib>

using namespace std;

// Doubly Linked List Node
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

// Circular Linked List Node
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

    void insertAtBeginning(int value) {
        DLLNode* newNode = new DLLNode;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
        cout << "Node " << value << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int value) {
        DLLNode* newNode = new DLLNode;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            cout << "Node " << value << " inserted at the end." << endl;
            return;
        }

        DLLNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Node " << value << " inserted at the end." << endl;
    }

    void insertAfter(int value, int key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        DLLNode* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << key << " not found!" << endl;
            return;
        }

        DLLNode* newNode = new DLLNode;
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        cout << "Node " << value << " inserted after " << key << "." << endl;
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

        DLLNode* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << key << " not found!" << endl;
            return;
        }

        DLLNode* newNode = new DLLNode;
        newNode->data = value;
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << "Node " << value << " inserted before " << key << "." << endl;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        DLLNode* temp = head;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << value << " not found!" << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        cout << "Node " << value << " deleted." << endl;
        delete temp;
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        DLLNode* temp = head;
        int position = 1;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
            position++;
        }

        if (temp == nullptr) {
            cout << "Node " << value << " not found!" << endl;
        } else {
            cout << "Node " << value << " found at position " << position << "." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        DLLNode* temp = head;
        cout << "Doubly Linked List: ";
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

    void insertAtBeginning(int value) {
        CLLNode* newNode = new CLLNode;
        newNode->data = value;

        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "Node " << value << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int value) {
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
        cout << "Node " << value << " inserted at the end." << endl;
    }

    void insertAfter(int value, int key) {
        if (last == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        CLLNode* temp = last->next;
        do {
            if (temp->data == key) {
                CLLNode* newNode = new CLLNode;
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;

                if (temp == last) {
                    last = newNode;
                }

                cout << "Node " << value << " inserted after " << key << "." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node " << key << " not found!" << endl;
    }

    void insertBefore(int value, int key) {
        if (last == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (last->next->data == key) {
            insertAtBeginning(value);
            return;
        }

        CLLNode* temp = last->next;
        CLLNode* prev = last;

        do {
            if (temp->data == key) {
                CLLNode* newNode = new CLLNode;
                newNode->data = value;
                newNode->next = temp;
                prev->next = newNode;

                cout << "Node " << value << " inserted before " << key << "." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node " << key << " not found!" << endl;
    }

    void deleteNode(int value) {
        if (last == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }

        CLLNode* temp = last->next;
        CLLNode* prev = last;

        do {
            if (temp->data == value) {
                prev->next = temp->next;

                if (temp == last) {
                    last = prev;
                }

                if (temp == last && last->next == last) {
                    last = nullptr;
                }

                cout << "Node " << value << " deleted." << endl;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node " << value << " not found!" << endl;
    }

    void search(int value) {
        if (last == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        CLLNode* temp = last->next;
        int position = 1;

        do {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << position << "." << endl;
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != last->next);

        cout << "Node " << value << " not found!" << endl;
    }

    void display() {
        if (last == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        CLLNode* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data;
            if (temp->next != last->next) {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, value, key;

    while (true) {
        cout << "\n========= DLL and CLL Operations =========" << endl;
        cout << "1. Doubly Linked List Operations" << endl;
        cout << "2. Circular Linked List Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Select list type: ";
        cin >> listType;

        if (listType == 3) {
            cout << "Exiting..." << endl;
            exit(0);
        }

        if (listType != 1 && listType != 2) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "\n1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert after a specific node" << endl;
        cout << "4. Insert before a specific node" << endl;
        cout << "5. Delete a specific node" << endl;
        cout << "6. Search for a node" << endl;
        cout << "7. Display" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                if (listType == 1) dll.insertAtBeginning(value);
                else cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                if (listType == 1) dll.insertAtEnd(value);
                else cll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter key (insert after): ";
                cin >> key;
                if (listType == 1) dll.insertAfter(value, key);
                else cll.insertAfter(value, key);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter key (insert before): ";
                cin >> key;
                if (listType == 1) dll.insertBefore(value, key);
                else cll.insertBefore(value, key);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                if (listType == 1) dll.deleteNode(value);
                else cll.deleteNode(value);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                if (listType == 1) dll.search(value);
                else cll.search(value);
                break;
            case 7:
                if (listType == 1) dll.display();
                else cll.display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}