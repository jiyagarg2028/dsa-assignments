#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertEnd(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if (head == nullptr) {
            return true;
        }

        Node* front = head;
        Node* rear = head;

        // Move rear to last node
        while (rear->next != nullptr) {
            rear = rear->next;
        }

        while (front != rear && front->prev != rear) {
            if (front->data != rear->data) {
                return false;
            }
            front = front->next;
            rear = rear->prev;
        }

        return true;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
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

int main() {
    DoublyLinkedList dll;
    string input;

    cout << "Enter a string to check if it's palindrome: ";
    cin >> input;

    for (char c : input) {
        dll.insertEnd(c);
    }

    cout << "\nDoubly Linked List: ";
    dll.display();

    if (dll.isPalindrome()) {
        cout << "Result: True - The list is a palindrome!" << endl;
    } else {
        cout << "Result: False - The list is not a palindrome." << endl;
    }

    return 0;
}