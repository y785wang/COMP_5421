// Lecture 5, Wed. May 30




struct Node {
    int n;
    NOde *next;
}

// Swap values in the 2nd and 3rd nodes, initial node is h
int temp = h->next->n;
h->next->n = n->next->next->n;
h->next->next->n = temp;


// define a vector, copy the mid three elements
int a = {10, 20, 30, 40, 50}
Vector<int> v(a+1, a+4);

// given vector<int> v = {...}, swap the first two elements
if (v.size() >= 2) {
    int temp = v[0];
    v[0] = v[1];
    v[1] = temp;
}
// or
Vector<int>::iterator it1 = v.begin(), it2 = it1 + 1;
int temp = *it1;
*it1 = *it2;
*it2 - temp;


/**************************************************
 
 Enumeration
 
 **************************************************/
// NOTE, enum variable are all consts
enum { max, min = 1 }; // equals const int max = 0; const nit min = 1;
enum { A = 100; B, C = 60, D, E = 60}; // D will be signed to 61
enum color { RED, YELLOW, GREEM };
color c = RED;
enum traficLight { RED }; // error if it is in the same scope as color defined above

enum class Traffic { RED, YELLOW, GREEN }; // can this be same scope as color?
Traffic t = Traffic::RED;
enum class weekday { MON, TUE, ..., SUN };
enum class longInt:longlong { max = 1233456, ... }
int k = max; // no problem, bad performance, may lead bugs




/**************************************************
 
 Namespace
 
 **************************************************/
// xlib.h
namespace xlib {
    void f(int);
    int max = 100;
};

// ylib.h
namespace ylib {
    void f(int);
    int g();
    int max = 200;
}

// xlib.cpp
#include "xlib.h"
void xlib::f(int x) { cout << x+1; }

//ylib.cpp
#include "ylib.h"
namespace ylib {
    void f(int x) { cout << max + 1; }
    int g() { return 1; }
}

//client code
#include "xlib.h"
#include "ylib.h"
using namespace ylib;
int main () {
    f(10);
    xlib::f(10);
    // within a scope, `using namespace xlib` can be used
}
// in header files, use `using std::cout;`

 
 
 
 /**************************************************
 
 Operator overloading
 
 One argument must be class type
 **************************************************/
Vec v1(5);
Vec v2; // a pair of cordinate
Vec v3(5);
Vec v4 = v1 + v5; // -, v1 * 2, 2 * v1
    v1 = v3;
    v1 += v3; // -=, *=
    ++v1; // --v1; v1++, v1--
    v[0] = 10;
v1 == v3; // !=
v1 <= v3; // >=, <, >
// Except these `::`, `?:`, `.`, `.*`, all other operator can be overloaded
// Cannot introduce new operators
// Cannot change ARITY, binary operator cannot be change to unary

// Vec.h
class Vec {
  private:
    int dim;
    int *v;
  public:
    Vec (int = 2);
    Vec (const Vec&);
    const Vec& operator= (consst Vec&);
    const Vec& operator+= (const Vec&); // v1.operator+=(v3);
    Vec operator+ (const Vec&);
    
    int getDim() const;
}

// vec.cpp
#include "Vec.h"
Vec::Vec(int n) : dim(n), v(new int[n]) {
    for (int i  = 0; i < n; ++i) {
        
    }
}
// since its member function, then *this is rhs, argument is rhs
const Vec& Vec::operator+= (const Vec& rhs) { // return type is for consective assignment
                                              // s.t.: v1 = (v2 += v3)
    assert(dim == rhs.dim);
    for (int i = 0; i < dim; ++k) {
        v[k] += rhs.v[k];
    }
    return *this; // return "*this" not "this"
}
Vec Vec::operator+ (const Vec& rhs) { // i.e.: x+y, return a copy, const or not does not matter
    assert(dim == rhs.dim);
    Vec temp = *this; // copy x to cx, equals Vec temp(*this);
    temp += rhs; // cx+=y
    return temp; // return the copy of x
}

// implement operator as a non-member
// no need "Vec::"
Vec operator- (const Vec& lhs, const Vec& rhs) { ... }

// 5 * v1 overload cannot be member, but v1 * 5 could
Vec operator* (const Vec& lhs, int m) { // v1 * 5
    Vec temp(lhs);
    for (int  i = 0; i < lhs.getDim(); ++i) {
        temp[i] *= m;
    }
    return temp;
}
Vec operator* (int m, const Vec* rhs) { // 5 * v1
    return rhs*m;
}

Vec v(10);
const Vec w(10);
w.getDim(); // error?
// Vec.h
int& operator[] (int index); // Vec v(10); v[0] = 10;
const int& operator[] (int index) const; // const Vec w(10);
// Vec.cpp
int& Vec::operator[] (int index) {
    assert(index >= 0 && index < dim);
    return v[index]; // return a variable!!!
}

Vec& Vec::operator++() { // prefix
    for (int i = 0; i < dim; ++i) {
        v[i] += 1;
    }
    return *this;
}
Vec Vec::operator++(int) { // postfix, add the dumi "int"
    Vec temp(*this);
    ++(*this);
    return temp;
}

/*
 For assignment 2
 iterator::advance
 iterator:prev
 iterator:distance, distance(begin, end)?
    










































