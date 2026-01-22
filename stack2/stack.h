#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
template <typename T>
class StackAddition {
private:
    stack<int> intPart1, intPart2, fracPart1, fracPart2, result;
    int carry;
    int precision;
    bool isFloatType;
    void pushDigits(long long number, stack<int>& target);
    void reverseStack(stack<int>& src, stack<int>& dest);
    void addStacksIntOnly();
    void addStacksFloat();
    void splitAndPush(T n1, T n2);
public:
    StackAddition();
    StackAddition(T n1, T n2, int prec = 0);
    void addAndDisplay();
};
template <typename T>
StackAddition<T>::StackAddition() {
    carry = 0;
    precision = 0;
    isFloatType = false;
}
template <typename T>
StackAddition<T>::StackAddition(T n1, T n2, int prec) {
    carry = 0;
    precision = prec;
    isFloatType = std::is_floating_point<T>::value;
    splitAndPush(n1, n2);
}
template <typename T>
void StackAddition<T>::pushDigits(long long number, stack<int>& target) {
    if (number == 0)
        target.push(0);
    else {
        stack<int> temp;
        while (number > 0) {
            temp.push(number % 10);
            number /= 10;
        }
        while (!temp.empty()) {
            target.push(temp.top());
            temp.pop();
        }
    }
}
template <typename T>
void StackAddition<T>::reverseStack(stack<int>& src, stack<int>& dest) {
    while (!src.empty()) {
        dest.push(src.top());
        src.pop();
    }
}
template <typename T>
void StackAddition<T>::splitAndPush(T n1, T n2) {
    if (!isFloatType) {
        pushDigits(static_cast<long long>(n1), intPart1);
        pushDigits(static_cast<long long>(n2), intPart2);
    } else {
        long long int1 = static_cast<long long>(floor(n1));
        long long int2 = static_cast<long long>(floor(n2));
        double frac1 = fabs(n1 - int1);
        double frac2 = fabs(n2 - int2);
        long long fracInt1 = static_cast<long long>(round(frac1 * pow(10, precision)));
        long long fracInt2 = static_cast<long long>(round(frac2 * pow(10, precision)));
        pushDigits(int1, intPart1);
        pushDigits(int2, intPart2);
        pushDigits(fracInt1, fracPart1);
        pushDigits(fracInt2, fracPart2);
    }
}
template <typename T>
void StackAddition<T>::addStacksIntOnly() {
    stack<int> s1, s2;
    reverseStack(intPart1, s1);
    reverseStack(intPart2, s2);
    while (!s1.empty() || !s2.empty() || carry != 0) {
        int d1 = 0, d2 = 0;
        if (!s1.empty()) { d1 = s1.top(); s1.pop(); }
        if (!s2.empty()) { d2 = s2.top(); s2.pop(); }
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        result.push(sum % 10);
    }
}
template <typename T>
void StackAddition<T>::addStacksFloat() {
    stack<int> f1, f2;
    reverseStack(fracPart1, f1);
    reverseStack(fracPart2, f2);
    int fracCarry = 0;
    stack<int> fracRes;
    while (!f1.empty() || !f2.empty()) {
        int d1 = 0, d2 = 0;
        if (!f1.empty()) { d1 = f1.top(); f1.pop(); }
        if (!f2.empty()) { d2 = f2.top(); f2.pop(); }
        int sum = d1 + d2 + fracCarry;
        fracCarry = sum / 10;
        fracRes.push(sum % 10);
    }
    while ((int)fracRes.size() > precision) fracRes.pop();
    carry = fracCarry;
    addStacksIntOnly();
    cout << "Sum = ";
    stack<int> tempRes = result;
    while (!tempRes.empty()) {
        cout << tempRes.top();
        tempRes.pop();
    }
    cout << ".";
    stack<int> tempFrac;
    while (!fracRes.empty()) {
        tempFrac.push(fracRes.top());
        fracRes.pop();
    }
    while (!tempFrac.empty()) {
        cout << tempFrac.top();
        tempFrac.pop();
    }
    cout << endl;
}
template <typename T>
void StackAddition<T>::addAndDisplay() {
    if (isFloatType)
        addStacksFloat();
    else {
        addStacksIntOnly();
        cout << "Sum = ";
        while (!result.empty()) {
            cout << result.top();
            result.pop();
        }
        cout << endl;
    }
}
#endif
