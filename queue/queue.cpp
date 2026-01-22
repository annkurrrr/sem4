#include "queue.h"
int main() {
    string input;
    cout << "Enter a string to check for palindrome: ";
    getline(cin, input);
    if (isPalindrome(input))
        cout << "It is a palindrome" << endl;
    else
        cout << "It is not a palindrome" << endl;
    return 0;
}
