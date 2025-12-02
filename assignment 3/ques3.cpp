#include <iostream>
#include <stack>
using namespace std;

// Function to check for balanced parentheses
bool isBalanced(string expr) {
    stack<char> s;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return s.empty(); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Expression has balanced parentheses.\n";
    else
        cout << "Expression does NOT have balanced parentheses.\n";

    return 0;
}