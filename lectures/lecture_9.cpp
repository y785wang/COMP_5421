// Lecture 9, Wed. July 11
// NOTE: const int &y = 1; // ok, 1 is literally const
//       int &y = 1;       // error

class Foo {
    vector<int> v;
  public:
    Foo() = default;
    Fooo(const Foo &) = default;
    Foo (initializer_list<int> list) {
        for (const auto &x : list) {
            v.puch_back(x);
        }
    }
}
Foo f = {1, 2, 10}; // call initializer_list<int>

class D : B // class Base, private inheritance
struct D : SB // struct SB, public inheritance

class D1 : protected B;
class D2 : private B;

class Stack : protected deque<int> {
    void puch (int x) {
        puch_back(x);
    }
}

void doSome(const Rectangle &r);
doSome(Rectangle(2, 10)); // width, height
doSome(Square(10));       // size

// Shape -> Triangle -> RightTriangle
void Triangle::print(ostream &);
void RightTriangle::print(ostream &);
ostream &operator<<(ostream &out, const Shape &s) { s.print(out); }
int main() {
    Triangle t1;
    RightTriangle t2;
    cout << t1 << endl; // only do shape print
    cout << t2 << endl; // only do shape print
}

vector<int> vec = {1, 2, 9, 8};
transfer(vec.begin(), vec.end()), vec.begin(), twice); // first two arguments, source range
                                                       // third argument, destination start
int twice(int ) { return 2*k; }

/**************************************************
 
 Lambda Expressions (Lambdas)
 
 **************************************************/
// NOTE: must use within the scope
//       cannot have default value for paramater
//       cannot have unnamed paramater
// Callable: function, functin object, lambda
[] (int k) { return 2*k; } // no return type, 2*k is int, then return tpye is int
[] (int x) -> double { if (x < 10) return 1; else return 2.5; }
// [] is called introducer
// compiler translate lambda expression to class, how?

{
    int a, b, c, d;
    [a, b] (int x) { return (a+b)*x; }
    function</*return type*/int(/*paramater type*/int)> f = [a, b] (int x) { return (a+b)*x; };
//    auto f = [a, b] (int x) { return (a+b)*x; }
}

void fun() {
    int x = 10;
    auto f = [x] { return x; }
    x = 100;
    cout << f() << endl; // 10
}

auto g = [&x] { return x; };
x = 200;
cout << g() << endl; // 200

{
    int a, b, c, d;
    double x, y;
    [a, &b, &c, d]
    [&]         // all are passed by reference
    [=]         // all are passed by value
    [&, c]      // all are passed by reference, except c is passed by value
    [=, &x, &a] // all are passed by value, except x and a are passed by reference
}

/**************************************************
 
 Templates
 
 **************************************************/
// NOTE: non-template functions have high priority
bool compare(const int &x, const int &y) { return x < y; }
bool compare (const double &x, const double &y) { return x < y; }

template<typename T1, typename T2>
bool compare (const T1 &x, const T2 &y) { return x < y; }
compare(1, 1.5);

template<typename T>
bool compare (const T &x, const T &y) { return x < y; }
compare(1, 2);
compare<double, double>(1, 2.0); // force the complier to call one with <double, double> types
compare("Hi", "Hello");

template<>
bool compare<char *>(const char* &s, const char* &y) { return strcmp(x, y); }

template<typename T> // one extensiation per parameter type
int compare(const T &x, const T &y) {
    if (x < y) return -1;
    if (y < x) return 1; // minimize operator dependency, use < only
    return 0;
}

/**************************************************
 
 Class Templates
 
 **************************************************/

typedef int T; // c++98
using T = int; // c++11
T x; // equals int x;

template<typename T1, typename T2>
typedef template<int, T2>, intT2; // error

template<typename T1, typename T2>
using intT2 = template<int, T2>; // works for c++11

template<typename T>
// using T = int; // c++11
class Stack{
  private:
    T* store;
    int size;
  public:
    explicit Stack(int n = 10);
    void puch(const T &t);
};
Stack<int> s1;
Stack<double> s2;
Stack<int, 100> s3; // ???

template<typename T, int size = 10> // size is NON-TYPE parameter, must be an integral type
                                    // e.g. ;int, char, long
class Stack{
private:
    T* store;
public:
    explicit Stack() : store(new T[size]) {}
    void puch(const T &t);
};
Stack<int> s4; // stack of 10 ints
Stack<double, 100> s5; // stack of 100 doubles

std::array<std::array<int, 10>, 20> a;
a[2][3] = 1; // 3rd row from top, 4th column from left

class Foo {
    array<int, size>; // error
}

template<int size = 10>
class Foo {
    array<int, size>;
}

// Stack.h
template<typename T, int N = 10>
class Stack {
  private:
    std::array<T, N> store;
    int top = 0;
  public:
    Stack() = default;
    ~Stack() = default;
    Stack(const Stack &) = delete;
    const Stack& operator=(const Stack &) = delete;
    void push(const T &);
    const T& top();
    void pop();
}
#include "Stack.cpp" // works through terminal?

// Stack.cpp
template<typename T, int N = 10>
Stack<T>::push(const T& t) {
    store[top] = t;
}

template<class T, int N = 10> // class is the same as typename, not a real class, just a notation
Stack<T>::pop() {
    if(empty()) throw stack_underflow;
    --top;
}

template<typename T, int N = 10>
Stack<T>::




















