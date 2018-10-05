// Lecture 10, Wed. July 18

Stack<int, 10> s1; // one instansheation
Stack<int, 20> s2; // two
Stack<double, 30> s3; // three
Stack<int, 10> s4; // already done before

/**************************************************
 
 Iterator (check out the c++reference iterator page)
    http://www.cplusplus.com/reference/iterator/
    intput, output, forward, bidirectional, random access
 
 **************************************************/
list<int> l = {1, 2, 3};
list<int>::iterator it = l.begin();
list<int>::iterator it2(it);
auto it3 = it;
++it;
// NOTE: iterator is not pointer, perform let it

/*
STL Container Classes
    linear
        vector<T>
        array<T, int>, push_back/pop_back
        forward_list<t>
        list<T>, insert anywhere
        deque<t>, push_back/push_frunt
    associative (based on hash tables)
        (multiple) map, multiple map allows dulplicate element
        (multiple) set,
*/

class Foo {
  public:
    class Iterator;
    using FooIterator = Iterator;
};
Foo::FooIterator fit;

vector<int> v = {1, 2, 3};
vector<int>::size_type i= 1; // proper usage
v[i] = 100;
auto it = v.begin();

using lit = list<int>::iterator; // c++11
typedef list<int>::iterator lit; // c++98

// never use <, <=, >, >= to compare iterator, sometimes can compare address???
auto it = l.begin();
while(it != l.end()) { ++it; }
// range: [l.begin(), l.end()

list<int> l = {1, 2, 3, 4, 5};
vector<int> v = (l.begin()+1, l.end()-1);
// templete cannot be translated between different type, double -> int is not allowed

vector<int> v2(10); // 10 zeros
vector<Foo> v3(10); // 10 default Foos
vector<int> v4(5, 99); // {99, 99, 99, 99, 99}
v4.resize(7, 77); // {99, 99, 99, 99, 99， 77， 77}
v4.resize(3); // {99, 99, 99}
deque<string> d  {"Hi", "Hello"};
d.insert(d.end(), "Bye"); // insert before iterator, equals d.push_back("Bye");

vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// Remove elements that divisiable by 3
auto it = vec.begin();
while(it != vec.end()) {
    if (0 == *it % 3) {
        it = vec.erase(it); // .erase() return point to the following one
    } else {
        ++it;
    }
}

list<int> l = (vec.begin(), vec.ed());
// remove elements divisiable by 5, else insert twice the element
auto it = l.begin();
while(it != l.end()) {
    if (0 == *it % 5) {
        it = l.erase(it);
    } else {
        l.insert(it, *it * 2);
        it += 2;
    }
}

forward_list<int> flist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// remove elements divisible by 3
auto prev = flist.before_begin();
auto curr = flist.begin();
while (curr != flist.end()) {
    if (0 == curr % 3) {
        curr = flist.erase_after(prev);
    } else {
        prev = curr;
        ++curr;
    }
}

// NOTE: iterator binds ALGORITHMs and CONTAINERS

// UnaryPredicate: callable that takes one parameter

// For A4
vector<vector<char>> cells;
vector<char> & operator[](int i) { // return i'th
    return cells[i];
}
class Base {
  public:
    Base(const Base &b) {}
    Base & operator=(const Base &b){}
}
class D public Base() {
  public:
    D(const D &d) : Base(d) {} // assignment op
    D & operator=(const D &d) {
        Base::operator=(d);
    }
}

class Base {
    virtual void f();
    virtal int g();
    char h();
}
class D : public Base {
    void f() override;
}
// one Virtual Table per class
// one Virtual Ptr per object























