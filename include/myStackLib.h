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
    void selectionSort();
    int partition(pr_t);
    void quickSort(pr_t);

public:
    myStack() : first(nullptr), last(nullptr), _size(0) {}

    bool empty();
    void push_back(const T);
    void remove(const int);
    int find(T);
    int size();
    void sort(string);
    void print();

    T operator[] (const int _index) {
        if (this->empty()){
            throw "Error! Stack is empty!";
        }

        Node<T>* _pointer = first;
        for (int i = 0; i < _index; i++) {
            _pointer = _pointer->next;
            if (_pointer == nullptr) {
                throw "Error element index!";
            }
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

    Node<T>* _tempPointer = first;
    while(_tempPointer != nullptr){
        _tempPointer->index--;
        _tempPointer = _tempPointer->next;
    }
    this->_size -= 1;

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
    this->_size -= 1;
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
    }
    slow->next = fast->next;
    slow = fast->next;
    while(slow) {
        slow->index -= 1;
        slow = slow->next;
    }
    this->_size -= 1;
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
void myStack<T>::selectionSort(){
    int min;
    for (int i = 0; i < this->_size; i++)
    {
        min = i;
        for (int j = i + 1; j < this->_size; j++)
        {
            if (this->at(j)->value <= this->at(min)->value)
                min = j;
        }
        swap(this->at(min)->value, this->at(i)->value);

    }
}


template<typename T>
int myStack<T>::partition(pr_t _limits)
{

    int pivot = _limits.first;

    int count = 0;
    for (int i = _limits.first + 1; i <= _limits.second; i++) {
        if (this->at(i)->value <= this->at(pivot)->value)
            count++;
    }


    int _pivotIndex = _limits.first + count;
    swap(this->at(_pivotIndex)->value, this->at(_limits.first)->value);


    int i = _limits.first, j = _limits.second;

    while (i < _pivotIndex && j > _pivotIndex) {

        while (this->at(i)->value <= this->at(_pivotIndex)->value) {
            i++;
        }

        while (this->at(j)->value > this->at(_pivotIndex)->value) {
            j--;
        }

        if (i < _pivotIndex && j > _pivotIndex) {
            swap(this->at(i++)->value, this->at(j--)->value);
        }
    }

    return _pivotIndex;
}

template<typename T>
void myStack<T>::quickSort(pr_t _limits)
{

    if (_limits.first >= _limits.second)
        return;

    int pivotIndex = partition(_limits);

    if(_limits.first < pivotIndex)
        quickSort(make_pair(_limits.first, pivotIndex - 1));

    if(_limits.second > pivotIndex)
        quickSort(make_pair(pivotIndex + 1, _limits.second));
}

template<typename T>
void myStack<T>::sort(string _method){
    if(_method == "selectionSort"){
        this->selectionSort();
    }
    else if(_method == "quickSort"){
        this->quickSort(make_pair(0, this->size() - 1));
    }
    else
        return;
}


#endif //LAB3_MYSTACKLIB_H
