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

int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

bool isEvenParity(int num) {
    int ones = countOnes(num);
    return (ones % 2 == 0);
}

// Doubly Linked List Operations
void removeEvenParityFromDLL(DLLNode*& head) {
    while (head != nullptr && isEvenParity(head->data)) {
        DLLNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    DLLNode* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (isEvenParity(current->next->data)) {
            DLLNode* temp = current->next;
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            delete temp;
        } else {
            current = current->next;
        }
    }
}

// Circular Linked List Operations
void removeEvenParityFromCLL(CLLNode*& last) {
    if (last == nullptr) {
        return;
    }

    CLLNode* current = last->next;
    CLLNode* prev = last;

    do {
        if (isEvenParity(current->data)) {
            prev->next = current->next;

            if (current == last) {
                last = prev;
            }

            if (current == last && last->next == current) {
                last = nullptr;
                delete current;
                return;
            }

            CLLNode* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    } while (current != last->next && last != nullptr);
}

void displayDLL(DLLNode* head) {
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

void displayCLL(CLLNode* last) {
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

DLLNode* createDLLNode(int data) {
    DLLNode* newNode = new DLLNode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertDLLEnd(DLLNode*& head, int data) {
    DLLNode* newNode = createDLLNode(data);

    if (head == nullptr) {
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

CLLNode* createCLLNode(int data) {
    CLLNode* newNode = new CLLNode;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertCLLEnd(CLLNode*& last, int data) {
    CLLNode* newNode = createCLLNode(data);

    if (last == nullptr) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

int main() {
    DLLNode* dllHead = nullptr;
    CLLNode* cllLast = nullptr;

    int n, value;

    // Doubly Linked List
    cout << "Enter number of nodes for DLL: ";
    cin >> n;
    cout << "Enter " << n << " values for DLL: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertDLLEnd(dllHead, value);
    }

    cout << "\nOriginal DLL: ";
    displayDLL(dllHead);

    cout << "\nParity of each node: ";
    DLLNode* temp = dllHead;
    while (temp != nullptr) {
        int ones = countOnes(temp->data);
        cout << temp->data << "(" << ones << (ones % 2 == 0 ? "=even" : "=odd") << ") ";
        temp = temp->next;
    }
    cout << endl;

    removeEvenParityFromDLL(dllHead);

    cout << "\nAfter removing even parity nodes: ";
    displayDLL(dllHead);

    // Circular Linked List
    cout << "\n\nEnter number of nodes for CLL: ";
    cin >> n;
    cout << "Enter " << n << " values for CLL: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertCLLEnd(cllLast, value);
    }

    cout << "\nOriginal CLL: ";
    displayCLL(cllLast);

    cout << "\nParity of each node: ";
    CLLNode* temp2 = cllLast->next;
    do {
        int ones = countOnes(temp2->data);
        cout << temp2->data << "(" << ones << (ones % 2 == 0 ? "=even" : "=odd") << ") ";
        temp2 = temp2->next;
    } while (temp2 != cllLast->next);
    cout << endl;

    removeEvenParityFromCLL(cllLast);

    cout << "\nAfter removing even parity nodes: ";
    displayCLL(cllLast);

    return 0;
}