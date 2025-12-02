#include <iostream>
using namespace std;

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push function
void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow!\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed to stack.\n";
    }
}

// Pop function
void pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
    } else {
        cout << stack[top] << " popped from stack.\n";
        top--;
    }
}

// Check if empty
void isEmpty() {
    if (top == -1)
        cout << "Stack is empty.\n";
    else
        cout << "Stack is not empty.\n";
}

// Check if full
void isFull() {
    if (top == SIZE - 1)
        cout << "Stack is full.\n";
    else
        cout << "Stack is not full.\n";
}

// Peek (top element)
void peek() {
    if (top == -1)
        cout << "Stack is empty.\n";
    else
        cout << "Top element is: " << stack[top] << endl;
}

// Display stack
void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            peek();
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}