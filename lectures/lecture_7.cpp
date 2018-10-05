// Lecture 7, Wed. June 27

/**************************************************
 
 Function objects
 
 **************************************************/
class Foo {
    vector<int> vec {11, 22, 33};
  public:
    int get(int k) {
        return vec[k];
    }
    int operator()(int k) {
        return vec[k];
    }
    double operator()(int j, int k) {
        return (vec[j] + vec[k]) / 2.0;
    }
}

int main() {
    Foo f;
    int x = f.get(1);
    int y = f(1);
    double avg = f(1, 2);
}

void doSomething(int x) { // old c style, don't use it
    static int count = 0; // only initialize once at the first time
    ++count;
}

/**************************************************
 
 auto
 
 **************************************************/
std::map<std::string, vector<int>> m;
std::map<std::string, vector<int>>::iterator it;
auto m1 = m;

int x = 10;
int y = 10; &z = x, *p = &x;
auto y = 10; &z = x, *p = &x;
int a{1.5}, b = "xxx"; // error
auto a{1.5}, b = "xxx"; // error

// following int can be replaced by auto
int x = 10;
const int y = x;
const int &z = x; // cannot change x through z, safe
int &r = x;
int *p = &x;

const int x = 10;
int y = x;
int &z = x; // error, can change x through z, not safe
const int &w = x;
auto y = x;
const auto &w = x;

void invalid(auto x) {} // invalid
class Bar {
    auto x; // invalid
}
int a[10];
auto b = a; // auto = int(*)[10]
auto &c = a; // auto = int(&)[10]

int fun(int x) { retutn 1;}
auto f = fun; // auto = int(*)(int)
auto &g = fun; // auto = int(&)(int)

// decltype = declared type

auto x = 10;

decltype(2*5) x; // equals int x;

int x = 10;
decltype(x++) y; // x++ does not actually be performed ?
cout << x; // x = 10;

vector<int> a;
decltype(a) b; // decltype(a) = vector<int>
b.push_back(100);
decltype(a)::iterator it;

auto perform (A a, B b) { // auto CANNOT be the return type, neither decltype(a * b)
    return a * b;
}
auto perform(A a, B b) -> decltype(a * b) { // trailing return type
    return a * b;
}

/**************************************************
 
 main oop principles - Inheritance
 
 **************************************************/
/*
 ADT
 Encapsulation
 Information hiding
    public, private, protected
 Polymorphism
    same name of function, overloading
 Inheritance
 
 Code reuse
    Inheritance
    Composition
 */

// in java, super class (base, parent) - sub class(derived, child)
class Base {}
class D1 : public Base {}
// protected <- protected
// public    <- public
class D2 : protected Base {}
// protected <- protected
// protected <- public
class D3 : private Base {}
// private <- protected
// private <- public
// NOTE: private file in base clss cannot be derivated to child class

class Base {
  private:   int x;
  protected: int y;
  public:    int z;
};
D1 d1;
d1.x = 10; // error
d1.y = 10; // error
d1.z = 10;
D2 d2;
d2.x = 10; // error
d2.y = 10; // error
d2.z = 10; // error
D3 d3;
d3.x = 10; // error
d3.y = 10; // error
d3.z = 10; // error

class Person {
  private:
    string name;
  public:
    Person(string name) : name(name) {}
    string getName();
    void setName(string name);
    void printInfo() {
        cout << "Name: " << endl;
    }
};
class Employee : public Person {
  private:
    double salary;
  public:
    Employee(string name, double sal) : Person(name), sal(sal) {}
    // if the Person(name) above is not called, then it will try to call
    // Person default ctor, but there is no default ctor anymore, error
    double getSal();
    void setSal(double sal);
    void printInfo() {
        Person::printInfo();
        cout << "Salary: " << sa; << endl;
    }
};
Employee("Joe", 100000.0);

class B {
  public:
    void f();
    void f(int);
};
class D : public B {
  public:
    void f(string);
    // in c++, name hiding, hide all f funciton in B
    // in java, all three f functions work
}
D d;
d.f(10); // error
d.f(); // error
d.f("Hi");

// Note: ctor is private in c++11
class Foo {
  private:
    Foo(); // perhaps member may want use it
  public:
    Foo(int);
    Foo() = default; // default ctor, c++11
    Foo(const Foo &) = default;
    Foo &operator=(const &Foo) = delete; // in case of defult, remove all default case
};















