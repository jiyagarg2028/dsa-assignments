#include <iostream>
#include <stack>
using namespace std;

int main() {
    string expr;
    cout << "Enter postfix expression (e.g. 53+2*): ";
    cin >> expr;

    stack<int> s;

    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0');  // Convert char digit to int
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            int result;
            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;

            s.push(result);
        }
    }

    cout << "Result: " << s.top() << endl;

    return 0;
}