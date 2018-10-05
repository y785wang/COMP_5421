#include "NumList.h"




/**************************************************
 
 NumList():
 Constructor
 
 **************************************************/
NumList::NumList() : size(0), capacity(1) {
    elements = new int[1];
}




/**************************************************
 
 ~NumList():
 Destructor
 
 **************************************************/
NumList::~NumList() {
    delete [] elements;
}




/**************************************************
 
 NumList():
 Copy contructor
 
 **************************************************/
NumList::NumList(const NumList &nl) {
    size = nl.size;
    capacity = nl.capacity;
    elements = new int[capacity];
    int *dest = elements;
    int *source = nl.elements;
    int counter = 0;
    while (counter++ < size) {
        *dest++ = *source++;
    }
}




/**************************************************
 
 operator=:
 Copy assignment operator
 
 **************************************************/
void NumList::operator=(const NumList &nl) {
    if (this == &nl) return;
    delete [] elements;
    size = nl.size;
    capacity = nl.capacity;
    elements = new int[capacity];
    int *dest = elements;
    int *source = nl.elements;
    int counter = 0;
    while (counter++ < size) {
        *dest++ = *source++;
    }
}




/**************************************************
 
 resize:
 Double the capacity of its internal array storage
 copy the original array to an new resized array
 
 **************************************************/
void NumList::resize() {
    capacity *= 2;
    int *newElements = new int[capacity];
    int *dest = newElements;
    int *source = elements;
    int counter = 0;
    while (counter++ < size) {
        *dest++ = *source++;
    }
    delete[] elements;
    elements = newElements;
}




/**************************************************
 
 isEmpty:
 Determine whether the internal array storage is
 empty or not
 
 **************************************************/
bool NumList::isEmpty() const {
    if (0 == size) {
        return true;
    } else {
        return false;
    }
}




/**************************************************
 
 checkExist:
 Determine whether a given element esixts in the
 internal array storage
 
 **************************************************/
bool NumList::checkExist(int element) const{
    for (int i = 0; i < size; ++i) {
        if (element == elements[i]) {
            return true;
        }
    }
    return false;
}




/**************************************************
 
 append:
 Append an element to the end of the internal
 array storage
 
 **************************************************/
void NumList::append(int element) {
    if (size == capacity) {
        resize();
    }
    elements[size] = element;
    ++size;
}




/**************************************************
 
 getElementAt:
 Get an element at a specified position
 
 **************************************************/
int NumList::getElementAt(int position) const {
    return elements[position];
}




/**************************************************
 
 setElementAt:
 Set an element at a specified position
 
 **************************************************/
void NumList::setElementAt(int position, int element) {
    elements[position] = element;
}




/**************************************************
 
 getSize:
 Get the number of elements currently stored
 the internal array storage
 
 **************************************************/
int NumList::getSize() const {
    return size;
}




/**************************************************
 
 getCapacity:
 Get the number of elements for which memory has
 been allocated
 
 **************************************************/
int NumList::getCapacity() const {
    return capacity;
}




/**************************************************
 
 getElements:
 Get a read-only pointer to the internal array
 storage
 
 **************************************************/
const int* NumList::getElements() const {
    return elements;
}
