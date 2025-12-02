#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input = "DataStructure";
    stack<char> s;

    // Push  character on the stack
    for (char c : input) {
        s.push(c);
    }

    // Pop characters from the stack to reverse the string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Original string: " << input << endl;
    cout << "Reversed string: " << reversed << endl;

    return 0;
}