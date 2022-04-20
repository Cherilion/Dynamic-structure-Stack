#ifndef LAB3_MYSTACKLIB_H
#define LAB3_MYSTACKLIB_H


#include <bits/stdc++.h>

using namespace std;


template< typename T>
struct Node {
    T value;
    Node* next;

    Node(T _value) : value(_value), next(nullptr) {}
};


template<typename T>
class myStack {
private:
    Node<T>* first;
    Node<T>* last;
public:
    myStack() : first(nullptr), last(nullptr) {}

    bool empty();
    void push_back(const T);
    void print();
};

template<typename T>
bool myStack<T>::empty() {
    return first == nullptr;
}

template<typename T>
void myStack<T>::push_back(const T _value) {
    Node<T>* _pointer = new Node(_value);
    if (this->empty()) {
        first = _pointer;
        last = _pointer;
        return;
    }
    last->next = _pointer;
    last = _pointer;
}

template<typename T>
void myStack<T>::print() {
    if (this->empty()) return;
    Node<T>* _pointer = first;
    while (_pointer) {
        cout << _pointer->value << " ";
        _pointer = _pointer->next;
    }
    cout << endl;
}

#endif //LAB3_MYSTACKLIB_H
