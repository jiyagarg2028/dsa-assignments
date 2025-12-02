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

int getLength(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Align both pointers
    Node* ptrA = headA;
    Node* ptrB = headB;

    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) {
            ptrA = ptrA->next;
        }
    } else {
        for (int i = 0; i < lenB - lenA; i++) {
            ptrB = ptrB->next;
        }
    }

    // Move both pointers until they meet
    while (ptrA != ptrB && ptrA != nullptr && ptrB != nullptr) {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return ptrA;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* listA = nullptr;
    Node* listB = nullptr;
    int n, m, value;

    cout << "Enter number of nodes in listA: ";
    cin >> n;
    cout << "Enter listA values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(listA, value);
    }

    cout << "Enter number of nodes in listB: ";
    cin >> m;
    cout << "Enter listB values: ";
    for (int i = 0; i < m; i++) {
        cin >> value;
        insertEnd(listB, value);
    }

    cout << "\nListA: ";
    display(listA);
    cout << "ListB: ";
    display(listB);

    Node* intersection = getIntersectionNode(listA, listB);

    if (intersection != nullptr) {
        cout << "\nIntersection found at node with value: " << intersection->data << endl;
    } else {
        cout << "\nNo intersection found (null)" << endl;
    }

    

    return 0;
}