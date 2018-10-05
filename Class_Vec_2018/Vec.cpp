#include<iostream>
#include<ostream>
#include <stdexcept>
#include <utility>      // std::rel_ops
using std::out_of_range;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
#include "Vec.h"

// default + conversion constructors
// see prototype for the default value for n.
Vec::Vec(int n) {
    if (n <= 0) throw out_of_range("Vec size cannot be zero or negative");
    sz = n;
    store = new int[n];
}

// normal constructor
// initializes this Vec of n elements to val
Vec::Vec(int n, const int &val) {
    if (n <= 0) throw out_of_range("Vec size cannot be zero or negative");
    sz = n;
    store = new int[n];
    for (int i = 0; i < n; ++i) {
        store[i] = val;
    }
}

// conversion constructor
// initializes this Vec of n elements to the supplied initializer_list<int>
Vec::Vec(std::initializer_list<int> initial_list)
{
    sz = initial_list.size();
    store = new int[sz];
    int count = 0;
    for (int x : initial_list) {
        store[count] = x;
        count++;
    }
}

// Normal constructor
// initializes this Vec of n elements to the elements of a raw C-array
Vec::Vec(const int A[], int n) {
    if (n <= 0) throw out_of_range("Vec size cannot be zero or negative");
    sz = n;
    store = new int[n];
    for (int i = 0; i < n; ++i) {
        store[i] = A[i];
    }
}

// The Big Three, a rule of thumb in C++: If a class defines at least one of copy constructor,
// assignment operator, and destructor, it should probably explicitly define all three.
// Copy constructor
Vec::Vec(const Vec &source) {
    sz = source.size();
    store = new int[source.size()];
    for (int i = 0; i < source.size(); ++i)
    {
        // since we have overloaded operator[] we might as well use it.
        (*this)[i] = source[i]; // ot         this->store[i] = source.store[i];
        // note that the parentheses in (*this)[i] are mandatory because
        // precedence of operator [] is higher than precedence of operator *,
        // so *this[i] is interpreted as *(this[i]), where this[i] makes no sense.

        // this is how we expressed the same thing in class
        //this->store[i] = A.store[i]; // same as above but without operator[]
        // note that the operators () [] -> and . have equal precedence and operate from left to right
    }
}

// assignment operator overload
Vec& Vec::operator=(const Vec &rhs) {
    if (this != &rhs) {
       // no storage allocation if lhs and rhs Vecs each have the same size
        if (size() != rhs.size()) {
            delete[] store;
            sz = rhs.size();
            store = new int[rhs.size()];
        }
        for (int i = 0; i < rhs.size(); ++i)
            store[i] = rhs[i];
    }
    return *this;
}

// destructor
Vec::~Vec() {
    delete[] store;
}

// Since C++11: 
// The Big Five = The Big Three + move ctor + move assignment operator
// The move constructor + move assignment make C++ faster and more efficient.

// move constructor
// note that source is not const (why?)
// steals all resources in source
Vec::Vec(Vec &&source) noexcept : store(source.store), sz(source.sz)
{
    // leave source in a state in which it is safe to run the destructor
    source.store = nullptr;
    source.sz = 0;
}

// move assignment
Vec & Vec::operator=(Vec &&rhs) noexcept // note that rhs is not const (why?)
{
    if (this != &rhs) // direct check for self-assignment
    {
        delete[] store; // free existing storage
        this->store = rhs.store;  // steal storage from rhs
        sz = rhs.sz;

        // leave rhs in a state in which it is safe to run the destructor
        rhs.store = nullptr;
        rhs.sz = 0;
    }
    return *this;
}

// subscript operator overload: read and write.
int& Vec::operator[](int i) {
   if (i < 0 || i >= size())
   {
      throw out_of_range("Vec index is out of range");
   }
   return store[i];
}

// subscript operator overload: read only.
const int& Vec::operator[](int i) const {
   if (i < 0 || i >= size())
   {
      throw out_of_range("Vec index is out of range");
   }
   return store[i];
}

Vec & Vec::operator+=(const Vec & rhs)
{
    if (this->size() != rhs.size())
    {
        throw std::invalid_argument("cannot add two Vecs of different sizes");
        // where the class std::invalid_argument comes from <stdexcept>
        // invalid_argument --> logic_error --> exception
    }
    for (int i = 0; i < rhs.size(); ++i) { store[i] += rhs[i]; }
    return *this;
}

Vec & Vec::operator-=(const Vec & rhs)
{
    if (this->size() != rhs.size())
    {
        throw std::invalid_argument("cannot add/subtract two Vecs of different sizes");
    }
    for (int i = 0; i < rhs.size(); ++i) { store[i] -= rhs[i]; }
    return *this;
}

// Adds val to every element in this Vec
Vec & Vec::operator+=(const int & val)
{
    for (int i = 0; i < this->size(); ++i) { store[i] += val; }
    return *this;
}

// Substracts val from every element in this Vec
Vec & Vec::operator-=(const int & val)
{
    for (int i = 0; i < this->size(); ++i) { store[i] -= val; }
    return *this;
}

Vec & Vec::operator*=(const int & val)
{
    for (int i = 0; i < this->size(); ++i) { store[i] *= val; }
    return *this;
}

Vec & Vec::operator/=(const int & val)
{
    for (int i = 0; i < this->size(); ++i) { store[i] /= val; }
    return *this;
}

Vec & Vec::operator%=(const int & val)
{
    for (int i = 0; i < this->size(); ++i) { store[i] %= val; }
    return *this;
}

// returns lhs + rhs
Vec operator+(const Vec & lhs, const Vec & rhs)
{
    Vec temp(lhs);
    temp += rhs;
    return temp;
}

// returns lhs - rhs
Vec operator-(const Vec & lhs, const Vec & rhs)
{
    Vec temp(lhs);
    temp -= rhs;
    return temp;
}

// returns Vec + int
Vec operator+(const Vec & lhs, const int & val)
{
    Vec temp(lhs);
    temp += val;
    return temp;
}

Vec operator-(const Vec & lhs, const int & val)
{
    Vec temp(lhs);
    temp -= val;
    return temp;
}

Vec operator*(const Vec & lhs, const int & val)
{
    Vec temp(lhs);
    temp *= val;
    return temp;
}

Vec operator/(const Vec & lhs, const int & val)
{
    Vec temp(lhs);
    temp /= val;
    return temp;
}

Vec operator%(const Vec & lhs, const int & val)
{
    Vec temp(lhs);
    temp %= val;
    return temp;
}

Vec operator+(const int & val, const Vec & rhs)
{
    return rhs + val;
}

// return int + Vec
Vec operator-(const int & val, const Vec & rhs)
{
    return rhs - val;
}

Vec operator*(const int & val, const Vec & rhs)
{
    return rhs * val;
}

Vec operator/(const int & val, const Vec & rhs)
{
    return rhs / val;
}

Vec operator%(const int & val, const Vec & rhs)
{
    return rhs % val;
}

// Unary Operator Overloads
Vec Vec::operator+() const
{
   return *this;
}

Vec Vec::operator-() const
{
   for (int i = 0; i < this->size(); ++i) { store[i] = -store[i]; }
   return *this;
}

Vec& Vec::operator++()
{
   *this += 1;
   return *this;
}

Vec& Vec::operator--()
{
   return (*this -= 1);
}

Vec Vec::operator++(int)
{
   Vec temp(*this);
   *this += 1;
   return temp;
}

Vec Vec::operator--(int)
{
   Vec temp(*this);
   *this -= 1;
   return temp;
}




// here we consider two Vecs equal  if they have the same
// lengths and the equal corresponding elements
bool operator==(const Vec & lhs, const Vec & rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }

    for (int i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i]) // using operator[]
        {
            return false;
        }
    }
    return true;
}

// For the purpose of demonstration, we will use the same 'relational' 
// rules as those used when c-strings are compared.
bool operator<(const Vec & lhs, const Vec & rhs)
{
    // compute length of the smaller Vec
    int min_length = lhs.size() < rhs.size() ? lhs.size() : rhs.size();

    // compare existing elements for 'less than' and 'greater than' notions
    for (int i = 0; i < min_length; ++i)
    {
        if (lhs[i] < rhs[i]) // using operator[]
        {
            return true;
        }
        else if (lhs[i] > rhs[i])
        {
            return false;
        }
    }
    // all elements are equal, so their lengths will decide the outcome
    return lhs.size() < rhs.size();
}

// the remaining operators !=, <=, >, >= are now defined in terms of the two == and < above
bool operator>(const Vec & lhs, const Vec & rhs)
{
    return  rhs < lhs;
}

bool operator!=(const Vec & lhs, const Vec & rhs)
{
    return !(lhs == rhs);
}

bool operator<=(const Vec & lhs, const Vec & rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const Vec & lhs, const Vec & rhs)
{
    return !(lhs < rhs);
}


// insertion operator overload for Vec objects
ostream& operator<<(ostream &sout, const Vec &source) {
   sout << '(' << source[0];
   for (int i = 1; i < source.size(); ++i)
      sout << ", " << source[i];
   sout << ')';
   return sout;
}

// extraction operator for Vec objects
// note that the supplied target object must be non-const (why?)
istream& operator>>(istream &sin, Vec &target) {
   cout << "Enter values for all " << target.size() 
        << " vector elements (integers)" << endl;
   for (int i = 0; i < target.size(); ++i)
   {
      std::cout << '?';
      sin >> target[i];
   }
   return sin;
}

// Returns the size of this Vec
int Vec::size() const { return sz; }

// reverse the elements of this Vec
Vec Vec::reverse() const
{
   Vec temp(*this); // make a temp copy of *this
                    // now reverse temp
   int left = 0;
   int right = temp.size() - 1;
   while (left < right)
   {
      int t = temp.store[left];
      temp.store[left] = temp.store[right];
      temp.store[right] = t;
      ++left;
      --right;
   }
   return temp;
}
