#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>
#include <set>
#include <iterator>
#include <functional>
#include <algorithm>
#include <array>
#include <numeric>

#include "FinalSelfReview.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::multiset;
using std::back_inserter;
using std::back_insert_iterator;
using namespace std::placeholders; // adds visibility of _1, _2, ...
using std::shared_ptr;

V::V(int n) {
    if (n <= 0) throw std::out_of_range("V size cannot <= 0");
    size = n;
    elements = new int[size];
}

V::V(int n, const int &val) {
    if (n <= 0) throw std::out_of_range("V size cannot <= 0");
    size = n;
    elements = new int[size];
    for (int i = 0; i < n; ++i) {
        elements[i] = val;
    }
}

V::V(std::initializer_list<int> il) {
    size = il.size();
    elements = new int[size];
    int count = 0;
    for (const auto &element : il) {
        elements[count] = element;
        ++count;
    }
}

V::V(int n, const int* a) {
    if (n <= 0) throw std::out_of_range("V size cannot <= 0");
    size = n;
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = a[i];
    }
}

V::~V() {
    delete [] elements;
}

int V::getSize() const {
    return size;
}

V::V(const V &v) { // copy ctor
    size = v.getSize();
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = v[i];
    }
}

V::V(V &&v) noexcept : size(v.size), elements(v.elements) { // move ctor
    v.size = 0;
    v.elements = nullptr;
}

V & V::operator=(const V &v) { // assignment op
    if (this != &v) {
        if (v.getSize() != size) {
            delete [] elements;
            size = v.getSize();
            elements = new int[size];
        }
        for (int i = 0; i < size; ++i) {
            elements[i] = v[i];
        }
    }
    return *this;
}

V & V::operator=(V &&v) noexcept { // move assignment op
    if (this != &v) {
        delete [] elements;
        size = v.size;
        elements = v.elements;
        v.size = 0;
        v.elements = nullptr;
    }
    return *this;
}

const int& V::operator[](int index) const {
    if (index < 0 || index > size) {
        throw std::out_of_range("V index out of range");
    }
    return elements[index];
}

int& V::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("V index out of range");
    }
    return elements[index];
}

ostream & operator<<(ostream &out, V &v) {
    for (int i = 0; i < v.getSize(); ++i) {
        out << v[i] << " ";
    }
    out << endl;
    return out;
}

istream & operator>>(istream &in, V &v) {
    cout << "Enter " << v.getSize() << " element(s)\n";
    for (int i = 0; i < v.getSize(); ++i) {
        in >> v[i];
    }
    return in;
}

V & V::operator+=(const V &v) {
    if (size != v.getSize()) {
        throw std::invalid_argument("size not same");
    }
    for (int i = 0; i < size; ++i) {
        elements[i] += v[i];
    }
    return *this;
}

V operator+(const V &v1, const V &v2) {
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("size not same");
    }
    V temp(v1);
    temp += v2;
    return temp;
}

V & V::operator+=(const int &n) {
    for (int i = 0; i < size; ++i) {
        elements[i] += n;
    }
    return *this;
}

V operator+(const V &v, const int &n) {
    V temp(v);
    temp += n;
    return temp;
}

V operator+(const int &n, const V &v) {
    V temp(v);
    temp += n;
    return temp;
}

bool operator==(V & v1, V & v2) {
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("size not same");
    }
    for (int i = 0; i < v1.getSize(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

bool operator<(V & v1, V & v2) {
    int minLength = v1.getSize() < v2.getSize() ? v1.getSize() : v2.getSize();
    for (int i = 0; i < minLength; ++i) {
        if (v1[i] < v2[i]) {
            return true;
        } else if (v1[i] > v2[i]) {
            return false;
        }
    }
    return v1.getSize() < v2.getSize();
}

V V::operator-() const {
    V temp(*this);
    for (int i = 0; i < size; ++i) {
        temp[i] = -temp[i];
    }
    return temp;
}

V & V::operator++() {
    for (int i = 0; i < size; ++i) {
        elements[i] += 1;
    }
    return *this;
}

V V::operator++(int) {
    V temp(*this);
    for (int i = 0; i < size; ++i) {
        elements[i] += 1;
    }
    return *this;
}

int fun(int x) { return 1; }

auto perform(int a, int b) -> decltype(a * b) { // trailing return type
    return a * b;
}

class B {
    int y = 5;
  public:
    B() { cout << "B" << endl; }
    virtual ~B() { cout << "~B" << endl; }
    int x = 10;
    void f(int) {}
    void print() const { cout << "BP" << endl; }
};

class D : public B {
  public:
    D() { cout << "D" << endl; }
//    using B::B;
    ~D() { cout << "~D" << endl; }
    void f(string) {
        cout << x << endl; // ok
        B::f(5);
    }
    void print() const { cout << "DP" << endl; }
};

ostream & operator<<(ostream &out, const B &b) {
    b.print();
    return out;
}



/**************************************************
 
 Lecture 6-8
 
 **************************************************/
void lecture_6_8() {
    int a[] = { 1, 1, 1 };
    V v1(3);
    V v2(3, 1);
    V v3{2, 2, 2};
    V v4(3, a);
    V v5(v2);
    V v6 = v2;
    cout << v1;
    cout << v2;
    cout << v3;
    cout << v4;
    cout << v5;
    cout << v6;
    
    const int x = 10;
    auto &z = x;
    
    int a1[10];
    auto a2 = a1;
    int* a3 = a1;
    
    auto f = fun;
    auto &f1 = fun;
    
    cout << f1(1) << endl;
    
    int y = 10;
//    decltype(y++) u; // no effect of y
    cout << y << endl; // y = 10;
    
    //    B b;
    //    D d;
    ////    d.f(3); // error
    //    cout << d.x << endl;
    
    B *bPtr = new D();
    delete bPtr;
    
    D d1;
    cout << d1; // only BP printed
}




/**************************************************
 
 Lambda Expressions
 
 **************************************************/
void lambdaExpression() {
    std::function<double(int, int)> f1 = [](int x, int y) {
        return x * 1.0 / y;
    };
    
    int x = 10;
    auto f2 = [=, &x](int y = 5) { return x += y; };
    
    cout << f1(3, 2) << endl;
    cout << f2() << endl;
    f2(-10);
    cout << x << endl;
    
}




/**************************************************
 
 Function Templates
 
 **************************************************/
template<typename T1, typename T2> // types that are going to be used
int f1(const T1 &x, const T2 &y) {  return x + y; } // low priority

template<typename T1>
int f1(const T1 &x, const T1 &y) {  return x * y; } // low priority

int f1(const int &x, const int &y) { return x - y; } // high priority

void functionTemplates() {
    cout << f1<int, int>(3, 1) << endl;
    cout << f1<int>(3, 1) << endl; // call *
    cout << f1(3, 1) << endl; // call -
}




/**************************************************
 
 Class Templates
 
 **************************************************/
template<typename T, int n = 10>
class VT {
  public:
    int size;
    T *elements;
    VT() : size(n) {elements = new T[size]; }
    T & operator[](int index) { return elements[index]; }
};

void classTemplates() {
    VT<int, 5> v;
    v[0] = 10;
    cout << v.size << endl;
    cout << v[0] << endl;
}




/**************************************************
 
 Iterators
 
 **************************************************/
ostream & operator<<(ostream &out, vector<int> v) {
    for (int e : v) {
        out << e << " ";
    }
    return out;
}

class compare {
  public:
    bool operator()(const int &x, const int &y) const {
        return x > y;
    }
};

void f(int a, double b, string s) {
    cout << s + " ";
    cout << a/b << endl;
}
void g1(int a) { f(a, 2.0, "divide by 2:"); }
auto g2 = std::bind(f, std::placeholders::_1, 2.0, "divide by 2:");

template<typename T> // template function
int add(const T &x, const T &y) {
    return x + y;
}

class add1 { // function obejct
  public:
    int operator()(const int &x, const int &y) { return x + y; }
};

int add2(const int &x, const int &y) { return x + y; } // function

int (*add3)(const int &x, const int &y) = add2; // function pointer

void iterators() {
    vector<int> v;
    auto it1 = v.begin();
    vector<int>::iterator it2 = v.end();
    
    map<string, int> m;
    m.insert(make_pair("hello", 0));
    m["world"] = 1;
    pair<string, int> p = pair<string, int>("hahaha", 2);
    m.insert(p);
    cout << m.size() << endl;
    
    vector<int> vec {14, 19, -4, 6, 5};
    std::multiset<int, compare> ms(vec.begin(), vec.end());
    vector<int> v1;
    std::copy_if(ms.begin(), ms.end(), std::insert_iterator<vector<int>>(v1, v1.begin()),
         [](int x) { return x > 0; });
    cout << v1 << endl;
    
//    back_inserter(l);
//    back_insert_iterator<list<int>>(l);
//    front_inserter(l);
//    front_insert_iterator<list<int>>(l);
//    insert_inserter<list<int>>(l, l.begin()++/*start insertion point*/);
    
    // binding
    f(3, 2.0, "divide by 2:");
    g1(3);
    g2(3);
    
    vector<int> v2 { 1, 2, 3 };
    vector<int> v3 { 4, 5, 6 };
    vector<int> v4(3);
    vector<int> v5(3);
    vector<int> v6;
    vector<int> v7;
    vector<int> v8(3);
    vector<int> v9(3);
    vector<int> v10(3);
    vector<int> v11(3);
    transform(v2.begin(), v2.end(), v4.begin(), std::negate<int>());   // template class
    transform(v2.begin(), v2.end(), v3.begin(), v5.begin(), add<int>); // template function
    transform(v2.begin(), v2.end(), v3.begin(), back_inserter(v6), add<int>);
    transform(v2.begin(), v2.end(), v3.begin(), back_insert_iterator<vector<int>>(v7), add<int>);
    transform(v2.begin(), v2.end(), v3.begin(), v8.begin(),
              [](const int &x, const int &y) {                         // lambda expression
                  return x + y;
              });
    transform(v2.begin(), v2.end(), v3.begin(), v9.begin(), add1());   // function object
    transform(v2.begin(), v2.end(), v3.begin(), v10.begin(), add2);    // function pointer
    transform(v2.begin(), v2.end(), v3.begin(), v11.begin(), add3);    // function pointer
    cout << v4 << endl;
    cout << v5 << endl;
    cout << v6 << endl;
    cout << v7 << endl;
    cout << v8 << endl;
    cout << v9 << endl;
    cout << v10 << endl;
    cout << v11 << endl;
}




/**************************************************
 
 I/ostream Iterators
 
 **************************************************/
void iostreamIterators() {
    string s;
    std::istream_iterator<char> eof;
    std::istream_iterator<char> start (std::cin);
//    copy(start, eof, std::back_insert_iterator<string>(s));
//    cout << s << endl;
    
    std::ostream_iterator<char> out(std::cout);
    copy(start, eof, out);
}




/**************************************************
 
 Expections
 
 **************************************************/
void h() {
    throw std::exception();
}

void g() {
    try {
        h();
    } catch (std::exception &e) {
        cout << "catch in g" << endl;
    }
    h();
}

void exceptions() {
    int x = 2;
    if (0 == x) {
        throw std::invalid_argument("invalid");
    } else if (1 == x) {
        throw x;
    }
    
    g();
}




/**************************************************
 
 Pointers
 
 **************************************************/
template<typename T>
class SmartPointer {
  private:
    T *p;
  public:
    SmartPointer(T *a) : p(a) {}
    ~SmartPointer() { delete p; }
    T * operator->() const { return p; }
    T & operator*() const { return *p; }
};

void pointers() {
    SmartPointer<int> p(new int(3));
    
    int *p1 = new int(10);
    shared_ptr<int> sp1(p1);
    
    shared_ptr<int> sp2 = std::make_shared<int>(13);
    std::weak_ptr<int> wp(sp2);
//    *wp += 1; // error, use lock()
    cout << *wp.lock() << endl;
}




/**************************************************
 
 Auto
 
 **************************************************/
double f4(int x) { return 1.0 * x; }
double (*f5)(int) = f4;

void autos() {
    int a[10];
    auto &c = a;
    int (&d)[10] = a;
    
    
    int n1 = 12;
    auto && n2 = n1;
}




/**************************************************
 
 Practice
 
 **************************************************/
//using std::array;
//template<typename T, int rows = 1, int cols = 1>
//auto make2DArray(const T &n) {
//    array<array<T, cols>, rows> array2D;
//    array<T, cols> row;
//    row.fill(n);
//    array2D.fill(row);
//    return array2D;
//}

class greaterC {
  public:
    bool operator()(int x, int y) const {
        return x > y;
    }
};

bool greaterF(int x, int y) {
    return x > y;
}

vector<int> sortVector1(vector<int> &v) {
    vector<int> result(v.size());
    
//    multiset<int> ms(v.begin(), v.end()); // compare with default
    
//    multiset<int, greaterC> ms(v.begin(), v.end()); // compare with functor object
    
    multiset<int, bool (*)(int, int)> ms (greaterF); // comapre with function pointer
    copy(v.begin(), v.end(), inserter(ms, ms.begin()));
    
    copy(ms.begin(), ms.end(), result.begin());
    return result;
}

vector<int> sortVector2(vector<int> &v) {
    vector<int> result(v);
    sort(result.begin(), result.end(), greaterC()); // sort with function object
//    sort(result.begin(), result.end(), greaterF); // sort with function pointer
    return result;
}

class alt {
    int n = 0;
  public:
    int operator()(const int &x, const int &y) {
        return 0 == ++n%2 ? x-y : x+y;
    }
};

int AltSum(vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 0,  alt());
}

#include <cstdlib>

template <class OutputIterator, class Size, class Generator>
void generate_n(OutputIterator first, Size n, Generator gen) {
    while (n > 0) {
        *first = gen();
        ++first;
        --n;
    }
}

class Random {
    int x, y;
  public:
    Random(int x, int y) : x(x), y(y) {}
    int operator()() {
        return x > y ? std::rand() % (x-y+1)+y : std::rand() % (y-x+1)+x;
    }
};

int random(int x, int y) {
    return x > y ? std::rand() % (x-y+1)+y : std::rand() % (y-x+1)+x;
}

//auto r = std::bind(random, _1, _2);
auto r = std::bind(random, std::placeholders::_1, 6);

vector<int> makeAndFillVector(int n, int x, int y) {
    auto random = [x, y]()mutable {
        if (y < x) std::swap(x, y);
        return std::rand() % (y-x+1)+x;
    };
    vector<int> v;
    std::generate_n(back_inserter(v), n, random);
    return v;
}

void practice() {
    // for c++14
//    auto a = make2DArray<int>(99);
//    auto b = make2DArray<int, 5>(88);
//    auto c = make2DArray<int, 5, 10>(77);
    
//    std::cin >> std::noskipws;
//    std::istream_iterator<char> start(std::cin), eof;
//    std::ostream_iterator<char> out(std::cout, " ");
//    std::copy(start, eof, out);
    
//    vector<int> v1 = { 1, 4, 2, 8, 5, 7, 1, 4 };
//    auto v2 = sortVector1(v1);
//    auto v2 = sortVector2(v1);
//    cout << v2 << endl;
    
//    vector<int> v3 = { 5, 6, 7, 8, 9 };
//    cout << AltSum(v3) << endl;
    
    cout << makeAndFillVector(5, 1, 10) << endl;
}





/**************************************************
 
 Main
 
 **************************************************/
int main() {

//    lecture_6_8();
//    lambdaExpression();
//    functionTemplates();
//    classTemplates();
//    iterators();
//    iostreamIterators();
//    try {
//        exceptions();
//    } catch (int e) {
//        cout << "catch int: " << e << endl;
//    } catch (std::exception &e) {
//        cout << "catch exception: " << e.what() << endl;
//    }
//    cout << "done" << endl;
//    exceptions();
//    pointers();
//    autos();
    practice();
    
    // TODO:
    // know remove, remove_copy, remove_copy_if, remove_if
    // know replace, replace_copy, replace_copy_if, replace_if
    
    return 0;
}
















