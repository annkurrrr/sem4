#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>
#include <iostream>

template <typename pool>
class Stack {
public:
    Stack() {}
    void push(pool val);
    void pop();
    pool top();
    void display();
    bool isempty();
    bool isfull();
    bool delimiters(std::string& expr);
    bool flag = true;

private:
    std::vector<pool> v;
    unsigned long MAX_SIZE = 100;
};

template <typename pool>
void Stack<pool>::push(pool val) {
    if (isfull()) {
        std::cout << "The statement is unbalanced\n";
        std::cout << "There is overflow\n";
        return;
    } else {
        v.push_back(val);
    }
}

template <typename pool>
void Stack<pool>::pop() {
    if (isempty()) {
        std::cout << "The statement is unbalanced\n";
        std::cout << "There is underflow\n";
        flag = false;
    } else {
        v.pop_back();
    }
}

template <typename pool>
pool Stack<pool>::top() {
    if (isempty()) {
        std::cout << "Stack is empty\n";
        return pool();
    }
    return v.back();
}

template <typename pool>
void Stack<pool>::display() {
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

template <typename pool>
bool Stack<pool>::isempty() {
    return v.empty();
}

template <typename pool>
bool Stack<pool>::isfull() {
    return v.size() >= MAX_SIZE;
}

template <typename pool>
bool Stack<pool>:: delimiters(std::string & expr) {
    for (size_t i = 0; i < expr.length(); ++i) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isempty()) {
                std::cout << "The statement is unbalanced\n";
                std::cout << "There is underflow\n";
                flag = false;
                return false;
            } else {
                char t = top();
                bool match = (t == '(' && ch == ')') ||
                             (t == '{' && ch == '}') ||
                             (t == '[' && ch == ']');
                if (!match) {
                    std::cout << "The statement is unbalanced\n";
                    std::cout << "Mismatched delimiters\n";
                    flag = false;
                    return false;
                }
                pop();
            }
        }
    }
    if (!isempty()) {
        std::cout << "The statement is unbalanced\n";
        std::cout << "There is overflow\n";
        flag = false;
        return false;
    }
    return true;
}

#endif
