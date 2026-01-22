#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};
template <typename T>
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void push_front(T val);
    void push_back(T val);
    void create_from_array(T arr[], int n);
    void display_forward();
    void display_backward();
    bool search(T val, int& position);
    void insert_at_position(T val, int pos);
    bool delete_value(T val);
    void delete_at_position(int pos);
    void delete_front();
    void delete_back();
    bool modify_value(T oldVal, T newVal);
    void reverse();
    bool is_empty();
    int get_size();
    ~DoublyLinkedList();
};
template <typename T>
void DoublyLinkedList<T>::push_front(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
template <typename T>
void DoublyLinkedList<T>::push_back(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
template <typename T>
void DoublyLinkedList<T>::create_from_array(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        push_back(arr[i]);
    }
}
template <typename T>
bool DoublyLinkedList<T>::is_empty() {
    return head == nullptr;
}
template <typename T>
int DoublyLinkedList<T>::get_size() {
    int count = 0;
    Node<T>* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
template <typename T>
void DoublyLinkedList<T>::display_forward() {
    Node<T>* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
template <typename T>
void DoublyLinkedList<T>::display_backward() {
    Node<T>* temp = tail;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
template <typename T>
bool DoublyLinkedList<T>::search(T val, int& position) {
    Node<T>* temp = head;
    position = 0;
    while (temp) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
        position++;
    }
    position = -1;
    return false;
}
template <typename T>
void DoublyLinkedList<T>::insert_at_position(T val, int pos) {
    if (pos < 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 0) {
        push_front(val);
        return;
    }
    Node<T>* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    if (temp->next == nullptr) {
        push_back(val);
        return;
    }
    Node<T>* newNode = new Node<T>(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
template <typename T>
bool DoublyLinkedList<T>::modify_value(T oldVal, T newVal) {
    Node<T>* temp = head;
    while (temp) {
        if (temp->data == oldVal) {
            temp->data = newVal;
            return true;
        }
        temp = temp->next;
    }
    return false;
}
template <typename T>
bool DoublyLinkedList<T>::delete_value(T val) {
    Node<T>* temp = head;
    while (temp) {
        if (temp->data == val) {
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            else tail = temp->prev;
            delete temp;
            return true;
        }
        temp = temp->next;
    }
    return false;
}
template <typename T>
void DoublyLinkedList<T>::delete_at_position(int pos) {
    if (pos < 0 || is_empty()) {
        cout << "Invalid position or list is empty!" << endl;
        return;
    }
    if (pos == 0) {
        delete_front();
        return;
    }
    Node<T>* temp = head;
    for (int i = 0; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    else tail = temp->prev;
    delete temp;
}
template <typename T>
void DoublyLinkedList<T>::delete_front() {
    if (is_empty()) {
        cout << "List is empty!" << endl;
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
}
template <typename T>
void DoublyLinkedList<T>::delete_back() {
    if (is_empty()) {
        cout << "List is empty!" << endl;
        return;
    }
    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
}
template <typename T>
void DoublyLinkedList<T>::reverse() {
    if (is_empty() || head == tail) {
        return;
    }
    Node<T>* current = head;
    Node<T>* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* temp = head;
    while (temp) {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
    }
}