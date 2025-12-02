#include <iostream>
#include <cstdlib>
#define MAX_SIZE 100

using namespace std;

class CircularQueue {
private:
    int front, rear;
    int queue[MAX_SIZE];

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        cout << item << " enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << queue[front] << " dequeued successfully." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << queue[front] << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, item;

    while (true) {
        cout << "\nCircular Queue Operations =" << endl;
        cout << "1. Enqueue (Add element)" << endl;
        cout << "2. Dequeue (Remove element)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek (Front element)" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 6:
                if (q.isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}