#include "stack.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    cout << "Enter an expression with delimiters: ";
    string expr;
    getline(cin, expr);

    Stack<char> s;
    s.delimiters(expr);

    if (s.flag) {
        cout << "It is balanced\n";
    } 
    return 0;
}
