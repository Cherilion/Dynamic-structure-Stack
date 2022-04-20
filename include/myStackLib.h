#ifndef LAB3_MYSTACKLIB_H
#define LAB3_MYSTACKLIB_H


#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pr_t;

template< typename T>
struct Node {
    T value;
    int index;
    Node<T>* next;

    Node(T _value) : value(_value), next(nullptr) {}
};


template<typename T>
class myStack {
private:
    Node<T>* first;
    Node<T>* last;
    int _size;

    void remove_first();
    void remove_last();
    Node<T>* at(const int);

public:
    myStack() : first(nullptr), last(nullptr), _size(0) {}

    bool empty();
    void push_back(const T);
    void remove(const int);
    int find(T);
    int size();
    void sort();
    void print();

    T operator[] (const int _index) {
        if (this->empty()){
            throw "Error! Stack is empty!h";
        }

        Node<T>* _pointer = first;
        for (int i = 0; i < _index; i++) {
            _pointer = _pointer->next;
            /*
            if (_pointer == nullptr) {
                throw "Error element index!h";
            }*/
        }
        return _pointer->value;
    }
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
        _pointer->index = 0;
        this->_size = 1;
        return;
    }
    if(this->size() == 1){
        last = _pointer;
        first->next = last;
        _pointer->index = first->index + 1;
    }
    else {
        last->next = _pointer;
        _pointer->index = last->index + 1;
        last = _pointer;
    }

    this->_size += 1;
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

template<typename T>
void myStack<T>::remove_first() {
    if (this->empty()) return;
    Node<T>* _pointer = first;
    first = _pointer->next;
    delete _pointer;
}

template<typename T>
void myStack<T>::remove_last() {
    if (this->empty()) return;
    if (first == last) {
        remove_first();
        return;
    }
    Node<T>* _pointer = first;
    while (_pointer->next != last) {
        _pointer = _pointer->next;
    }
    _pointer->next = nullptr;
    delete last;
    last = _pointer;
}

template<typename T>
void myStack<T>::remove(const int _index) {
    if (this->empty()) return;
    if (first->index == _index) {
        remove_first();
        return;
    }
    else if (last->index == _index) {
        remove_last();
        return;
    }
    Node<T>* slow = first;
    Node<T>* fast = first->next;
    while (fast && fast->index != _index) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        throw "Error! This element does not exist!";
        return;
    }
    slow->next = fast->next;
    delete fast;
}

template<typename T>
int myStack<T>::find(T _value) {
    Node<T>* p = first;
    while (p && p->val != _value){
        p = p->next;
    }
    return (p && p->val == _value) ? p->index : nullptr;
}

template<typename T>
int myStack<T>::size(){
    return this->_size;
}

template<typename T>
Node<T>* myStack<T>::at(const int _index) {
    if (this->empty()){
        throw "Error! Stack is empty!";
    }
    Node<T> *_pointer = first;
    for (int i = 0; i < _index; i++) {
        _pointer = _pointer->next;
        if (!_pointer){
            throw "Error element index!";
        }
    }
    return _pointer;
}

template<typename T>
void myStack<T>::sort(){
    myStack<T>& _stack = *this;
    int min;
    for (int i = 0; i < this->_size; i++)
    {
        min = i;
        for (int j = i + 1; j < this->_size; j++)
        {
            if (_stack[j] <= _stack[min])
                min = j;
        }
        //swap(_stack[min], _stack[i]);
        Node<T>* tempNext;
        if(min != 0 && i != 0){
            tempNext = this->at( min- 1)->next;
            this->at(min -  1)->next = this->at(i);
            this->at(i -  1)->next = tempNext;
        }
        else if(min == 0 && i != 0){
            tempNext = this->at(i - 1)->next;
            first = this->at(i);
            this->at(i -  1)->next = tempNext;
        }
        else if(min != 0 && i == 0){
            tempNext = this->at(min - 1)->next;
            first = this->at(min)->next;
            this->at(min -  1)->next = tempNext;
        }
    }
}

#endif //LAB3_MYSTACKLIB_H
