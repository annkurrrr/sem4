#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
    T arr[100];
    int front, rear, size;
public:
    Queue();
    void enqueue(T value);
    T dequeue();
    bool isEmpty();
    int getSize();
};
template <typename T>
Queue<T>::Queue() {
    front = 0;
    rear = -1;
    size = 0;
}
template <typename T>
void Queue<T>::enqueue(T value) {
    if (size == 100) {
        cout << "Queue overflow!" << endl;
        return;
    }
    rear = (rear + 1) % 100;
    arr[rear] = value;
    size++;
}
template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow!" << endl;
        return T();
    }
    T val = arr[front];
    front = (front + 1) % 100;
    size--;
    return val;
}
template <typename T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
template <typename T>
int Queue<T>::getSize() {
    return size;
}
char toLowerManual(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch + 32;
    return ch;
}
bool isPalindrome(string str) {
    Queue<char> q;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            q.enqueue(toLowerManual(ch));
    }
    string normal = "", reversed = "";
    while (!q.isEmpty()) {
        char ch = q.dequeue();
        normal += ch;
        reversed = ch + reversed;
    }
    return normal == reversed;
}
#endif