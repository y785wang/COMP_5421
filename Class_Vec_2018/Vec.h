/**
* Class Vec models a container object that uses an array to store 
* the integer data elements.
* The purpose of this class is to demonstrate operator overloading in C++.
*
* @author  S. Ghaderpanah
* @version 1.0
* @since   June 4, 2018
*/
#ifndef Vec_H
#define Vec_H

#include <iostream>
#include<initializer_list>

class Vec {
private:
    int *store;// pointer to storage for elements of this Vec
    int sz; // size of this Vec
public:
    // 2 constructors: default + conversion
    explicit Vec(int = 5);

    // normal constructor
    // initializes this Vec of n elements to val
    Vec(int n, const int &val);

    // conversion constructor
    // initializes this Vec of n elements to the supplied initializer_list<int>
    Vec(std::initializer_list<int> initial_list);

    // Normal constructor
    // initializes this Vec of n elements to the elements of a raw C-array
    Vec(const int A[], int n);

    /* 
    The Big Three, a rule of thumb in C++: If a class defines at least one
    of copy constructor, assignment operator, and destructor, it should
    probably explicitly define all three.
    */

    // copy constructor
    Vec(const Vec &source);

    // assignment operator
    Vec & operator=(const Vec &rhs);

    // destructor
    virtual ~Vec();

    // Since C++11: The Big Five = The Big Three + move constructor + move assignment operator
    // move constructor. note: noexcept indicates that the function will not thow exceptions
    Vec(Vec &&source) noexcept;

    // move assignment. note: noexcept indicates that the function will not thow exceptions
    Vec & operator=(Vec &&rhs) noexcept;


    int size() const;    // Returns the size of the Vec
    Vec reverse() const;    // reverses the Vec elements
    const int& operator[](int i) const; // subscript operator overload: read-only

/*    Note: Can the return in the above overload be just int& without the const?
      Yes, the return type can be int&. But that would defeat the const-ness of the function:
      consider this:

      const Vec cv; // that's fine, cv is a const Vec

      Now, if we define the return type as just int& we can do this: 
      
      cv[0] = 10;

      That sounds like a contraciction to me!
      if cv is meant to be a const, why allow  cv[0] = 10; ??

      Hence, the return type const int& in the above const version of the subscript operator.
*/

    // Here is the non-const version:
    // In the following we actually do want to allow  this:
    // Vec v; 
    // v[0] = 10;
    // Hence, the return type:
    int& operator[](int i);  // subscript operator overload: read and write

    friend istream& operator>>(istream &sin, Vec &target); // read from sin into supplied target
    friend ostream& operator<<(ostream &sout, const Vec &source); // write to sout from supplied source

    Vec&          operator+=(const Vec& rhs); // Vec += Vec
    Vec&          operator-=(const Vec& rhs); // Vec -= Vec

    friend Vec    operator+(const Vec& lhs, const Vec& rhs); // Vec + Vec
    friend Vec    operator-(const Vec& lhs, const Vec& rhs); // Vec - Vec;

    friend Vec    operator+(const Vec& lhs, const int& val); // Vec + int
    friend Vec    operator-(const Vec& lhs, const int& val); // Vec - int
    friend Vec    operator*(const Vec& lhs, const int& val); // Vec * int
    friend Vec    operator/(const Vec& lhs, const int& val); // Vec / int
    friend Vec    operator%(const Vec& lhs, const int& val); // Vec % int

    friend Vec    operator+(const int& val, const Vec& rhs); // int + Vec
    friend Vec    operator-(const int& val, const Vec& rhs); // int - Vec
    friend Vec    operator*(const int& val, const Vec& rhs); // int * Vec
    friend Vec    operator/(const int& val, const Vec& rhs); // int / Vec
    friend Vec    operator%(const int& val, const Vec& rhs); // int % Vec

    Vec&          operator+=(const int& val); // Vec += val,  add val to every element
    Vec&          operator-=(const int& val); // Vec -= val,  subtract val from every element
    Vec&          operator*=(const int& val); // Vec *= val,  multiply every element by val
    Vec&          operator/=(const int& val); // Vec /= val,  divide every element by val
    Vec&          operator%=(const int& val); // Vec %= val,  modulus every element by val

    // For the purpose of demostration, we are going to use the same 'relational' rules
    // as those used when c-strings are compared.
    // of the 6 relational operators ,  these two are directly defined
    friend bool     operator==(const Vec& lhs, const Vec& rhs); // Vec == Vec
    friend bool     operator<(const Vec& lhs, const Vec& rhs); // Vec < Vec
// To overload the remaing 4, use the std::rel_ops namespace from <utility> rather than DIY.
// However, we implement them in this presentaion for your reference.
    friend bool     operator>(const Vec& lhs, const Vec& rhs); // Vec > Vec
    friend bool     operator!=(const Vec& lhs, const Vec& rhs); // Vec != Vec
    friend bool     operator<=(const Vec& lhs, const Vec& rhs); // Vec <= Vec
    friend bool     operator>=(const Vec& lhs, const Vec& rhs); // Vec >= Vec

    Vec operator+() const; // unary +
    Vec operator-() const; // unary -

    Vec& operator++(); // unary prefix increment
    Vec& operator--(); // unary prefix decrement

    Vec operator++(int); // unary postfix increment
    Vec operator--(int); // unary postfix decrement
};
#endif



