#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int x) {
        
        q.push(x);

        // Rotate queue to make the new element at front
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        queue<int> temp = q;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, item;

    while (true) {
        cout << "\n Stack using One Queue =" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> item;
                s.push(item);
                break;
            case 2:
                item = s.pop();
                if (item != -1)
                    cout << item << " popped successfully." << endl;
                break;
            case 3:
                item = s.top();
                if (item != -1)
                    cout << "Top element: " << item << endl;
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}