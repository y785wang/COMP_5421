#include "t.h"

#include <iostream>
#include "string.h"
#include <iomanip>
#include <array>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::ostream;




/************************************
 
 self_review_1_3
 
 ***********************************/
Node::Node(int x, Node *l = nullptr, Node *r = nullptr) : key(x), left(l), right(r) {}

int i_1 = 4;

void modify(int* array) {
    ++ *(array + 1);
}

int& f_1(int &x) {
    return x;
}

void f_2(int &x) {
    return;
}

int (*f_3)(int);

int f_4(int x) {
    return 2 * x;
}

Foo::Foo() {
    cout << "ctor" << endl;
}
Foo::Foo(int x) {
    cout << "ctor " << x << endl;
}
Foo::Foo(char *s) {
    cout << "ctor " << s << endl;
}
Foo::Foo(const Foo &f) {
    cout << "copy ctor " << endl;
}
Foo& Foo::operator=(const Foo &f) {
    if (this == &f) return *this;
    cout << "assignment operator " << endl;
    return *this;
}
Foo& Foo::operator=(const int x) {
    cout << "assignment operator o " << x << endl;
    return *this;
}

void self_review_1_3() {
    char s1[] = "a";
    char s2[] = "c";
    cout << strlen(s1) << endl; // a is two position before c, return -2
    
    int *m = new int(5);
    cout << *m << endl;
    delete m;
    
    int *array[3] = {new int(10), new int, new int(5)};
    cout << **(array + 1) << " " << *array[1] << " " << *(*array + 1) << endl;
    delete[] *array;
    
    int *a_2 = new int[3];
    a_2[0] = 10;
    delete[] a_2;
    
    int **n = new int* [3];
    *n = new int(3);
    cout << **n << " " << *n[0] << endl;
    delete[] n;
    
    bool ok = -1;
    if (-1) { cout << "here_1" << endl; }
    
    int i = 2;
    float f = 3.25;
    i = f;
    cout << i << " " << (int)f << " " << int(f) << " " << static_cast<int>(f) << endl;
    
    int a_1[4] = {10, 3, 5};
    modify(a_1);
    cout << a_1[3] << " " << a_1[1] << endl;
    
    int i_1 = 2;
    for (int i = 0; i < 1; ++i) {
        int i_1 = 3; // if this line is not define, the line above would be print
        cout << i_1 << " " << ::i_1 << endl;
    }
    
    const int *p = new int(5);
    delete p;
    p = new const int(5);
    delete p;
    const int i_4 = 6;
    p = &i_4;
    ++p;
    const int *i_2 = p;
    cout << * --i_2 << endl;
    
    int * const q = &i_1;
    *q = 11;
    cout << ++ *q << endl;
    
    int a_3[2] = {3, 4};
    int *i_5 = a_3;
    cout << *i_5 << endl;
    
    const int &ra = 10;
    cout << ra << endl;
    //    int &rb = 10; // error
    
    int i_6 = 3;
    f_2(i_6);
    //    f_2(3); // error
    
    int i_7 = 1;
    int i_8 = 2;
    int i_9 = 3;
    int i_10 = i_7 = i_9 = i_8; // equals (i_10 = (i_7 = (i_9 = i_8)))
    cout << i_10 << endl; // 2
    cout << (i_10 = 20) << endl; // 20
    
    int *a_4[2];
    a_4[0] = new int(1);
    delete[] *a_4;
    
    int **a_5[2];
    a_5[1] = new int*[2];
    a_5[1][1] = new int(1);
    cout << **(*(a_5+1)+1) << " " << *a_5[1][1] << endl;
    delete a_5[1][1];
    delete[] a_5[1];
    
    f_3 = f_4;
    cout << f_3(3) << endl;
    
    char c_1[] = "Hello";
    Foo foo_1, foo_2; // ctor, ctor
    foo_1 = 10; // assignment operator
    foo_2 = c_1; // ctor + assignment operator
    foo_1 = foo_2; // assignment operator
    Foo foo_3 = foo_2; // copy ctor
    Foo foo_4(foo_3); // copy ctor
    
    return;
}




/************************************
 
 self_review_4
 
 ***********************************/
void self_review_4() {
    char c;
    int count = 0;
//    while (cin.get(c)) {
//        cout << "- " << c << endl;
//        ++count;
//    }
    cout << count << endl; // 4
    
    int h;
//    cin >> std::hex >> h; // intput is hex, like A0
    cout << h << endl; // output is dec, like 160
    
    cout << std::setw(5) << std::left << "123" << "!" << endl;
    
    array<int, 4> arr = {1, 2, 3, 4};
    for (array<int, 4>::iterator it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    array<int, 4>::iterator begin = arr.begin();
    array<int, 4>::iterator end = arr.end();
    cout << *begin << " " << *(end-1) << endl;

    return;
}




/************************************
 
 self_review_5
 
 ***********************************/


//enum class Month { Jan };
//enum class Name { Jan };
void self_review_5() {
//    Name m = Jan;
    
    int i = 2;
    while (i--) cout << "here" << endl;
    
    int *r[3];
    
    return;
}



int main() {
//    self_review_1_3();
//    self_review_4();
    self_review_5();
    return 0;
}

