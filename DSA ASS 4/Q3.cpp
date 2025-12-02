#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }

    int half = q.size() / 2;
    stack<int> s;

    // Push first half into stack
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Pop from stack and enqueue (reverses first half)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements (must be even): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "Original queue: ";
    queue<int> temp = q;
    printQueue(temp);

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    printQueue(q);

    return 0;
}