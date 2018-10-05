// Lecture 2, Wed. May 9

/**************************************************
 
 array
 
 **************************************************/

class Array {}
Array a1; // initial capacity = 10
Array a2(100); // capacity = 100

/*
 the following are copy ctor (constroctor)
 its shallow copy
*/
Array a3 = a2;
Array a4(a2);
Array a5{a5};

// shallow copy
int a[10] = {...};
int *p = a;

a1 = a2; // assignment operator

// Array.h
#ifndef ARRAY_H // header guard
#define ARRRAY_H

/*
 for class, default members and bases are private
 for struct, the default is public
 suggestion: always write private, public...
 */
class Array {
  private:
    int *store; // call "data member"
    int length;
  public:
    Array();
    Array(int);
    Array(int = 10); // variable does not matter
    explicit Array(const Array &);
    ~Array();
    void @operator=(const Array &);
    int get(int);
    int set(int, int);
    // friend below allow it access private, or protect field
    friend ostream& operator<<(ostream& out, const Array &);
}

#endif

// Array.cpp
#include <iostream>
#include <string>
#include "Array.h"

using namespace std; // better not use it in .h file

Array::Array(int len) { // initialization type one
    store = new int[len];
    length = len;
}

Array::Array(int len) : store(new int[len]), length(len) {}

Array::Array(const Array &arr) { // copy ctor
    length = arr.length;
    store = new int[length];
    for (int i = 0; i < length, ++i) {
        store[i] = arr.store[i];
    }
}

inline Array::~Array() { // ???
    delete[] store;
}

void Array::operator=(const Array &arr) {
    if (this == &arr) return; // in case self-assignment
    delete[] store;
    // below three line have same functionality
    length = arr.length;
    (*this).length = arr.length;
    this->length = array.length;
    store = new int[length];
    for (int i = 0; i < length; ++i) {
        store[i] = arr.store[i];
    }
}

int Array::get(int index) {
    assert(0 <= index && index < length);
    return store[index];
}

void Array::set(int index, int value) {
    assert(0 <= index && index < length);
    store[index] = value;
}

ostream& operator<< (ostream& out, const Array& arr) {
    for (int i = 0; i < arr.length; ++i) {
        out << arr.store[k] << endl;
    }
    return out;
}


/***************************************************
 
 Stack, linked-list
 
 **************************************************/

// Stack.h
#ifndef STACK_H
#define STACK_H
class Stack {
  private:
    struct Node {
        int data;
        Node *next;
        Node(int data, Node *next = nullptr) : data(data), next(next) {}
    }
    
    Node* head;
    int size;
    
  public:
    Stack();
    ~Stack();
    void push(int val);
    void pop();
    int top();
    bool isEmpty();
    Stack(const Stack &);
    void operator=(const Stack&);
}
#endif

// Stack.app
#include <cassert>
#include "Stack.h"
Stack::Stack() : head{nullptr}, size(0) {} // use nullptr instead NULL

bool Stack::isEmpty() {
    return size == 0;
}

void Stack::push(int val) {
    Node *temp = newNode(val, head);
    head = temp;
    ++size;
}

int Stack::top() {
    assert(!isEmpty());
    return temp.data;
}

void Stack::pop() {
    assert(!isEmpty());
    Node *temp = head;
    head = head->next;
    delete temp;
    --size;
}

Stack::Stack(const Stack &s) : head(nullptr), size(0) {
    if (s.isEmpty()) return;
    size = s.size();
    head = new Node(s.head->data);
    Node *temp = head;
    Node *temp2 = s.head;
    while (temp2->next != nullptr) {
        temp2 = temp2->next;
        temp->next = new Node(s.head->data);
    }
    temp = temp2->next;
}

Stack::~Stack() {
    // first way to do it
    while (!isEmpty) {
        pop()
    }
    // second way to do it
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}





/* TODO: for assignment 1
 1) NULL -> nulptr
 2) change ctor, set default nulptr value
 3) move ctor impementation to .cpp file
 





















