#ifndef FINALREVIEW_H
#define FINALREVIEW_H

#include <iostream>
#include <initializer_list>

using std::ostream;
using std::istream;

//template <class T>
//class SmartPtr {
//  private:
//    T *ptr;
//  public:
//    SmartPtr(T *p = nullptr) { ptr = p; }
//    ~SmartPtr() { delete }
//};

class V {
  private:
    int size;
    int *elements;
  public:
    // ctors
    V(int = 5);
    V(int, const int &);
    V(std::initializer_list<int>);
    V(int, const int *);
    
    V(const V &); // copy ctor
    V & operator=(const V &); // assignment op
    ~V(); // dtor
    
    V(V &&v) noexcept; // move ctor
    V & operator=(V &&v) noexcept;
    
    int getSize() const;
    
    const int& operator[](int) const;
    int& operator[](int);
    
    friend ostream & operator<<(ostream &, V &);
    friend istream & operator>>(istream *, V &);
    
    V & operator+=(const V &);
    friend V operator+(const V &, const V &);
    
    V & operator+=(const int &);
    friend V operator+(const V &, const int &);
    friend V operator+(const int &, const V &);
    
    friend bool operator==(V &, V &);
    friend bool operator<(V &, V &);
    
    V operator-() const;
    V & operator++();
    V operator++(int);
    
};

#endif








