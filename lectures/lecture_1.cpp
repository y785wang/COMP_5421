/*

 Lecture 1, Wed. May 2

 Type: values, integers, characters
 Datatype: Type + operations,
 e.g.: integers +, -, /, *, %

 Built-in types
    char (at least 8 bits)
    short, int (at least 16 bits)
    long (32), longlong (64)
    double (32), float (32)

    signed or unsigned is based on implementation
 */

// sample.cpp
int main() {
    return 0;
}

/*
  sample.cpp -> PREPROCESSOR -> COMPILER -> sample.obj -> LINKER -> a.out
 */

#include<iostream>
int main() {
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;
    std::cout << "Enter another integer: ";
    int y;
    std::cin >> y;
    std::cout << x << " times " << y << " equals " << x*y << std::endl;
    return 0;
}

/*
 :: is scope resolution operator
 << output (insertion) operator
 >> input (extraction) operator

 In order to avoid 'std::'
    write 'using namespace std;' after includes

 'cout << x' returns another 'cout'
 Similarly, we can write 'cin >> x >> y'

 "equals" is called c-string (any sequence of characters)
 "A" = 'A', '\0'
 'A' = 'A'
 '\0' if null character right after c-string, counted as 1 bite
 */

#include "string.h"         // c-string is an array of characters
strlen();                   // determind c-string length, length of "ABC" is 3
strcpy(string_1, string_2); // copy string_2 to string_1
strcmp(string_1, string_2); // return 0, negative or positive integers
strcat(string_1, string_2); // string_1 = string_1 appends string_2
char a[] = "ABC";           // a points to A, B, C, \0
char b[] = {'A', 'B', 'C', 'D', 'E'}; // b points to 'A', 'B', 'C', 'D', 'E'
char c[4];
c[0] = 'A';

//4 ways to initialize an integer
    //c++03
        int x = 0;
        int x(0);
    //c++11
        int x{0}; // prefered
        int x = {0};

#include<iostream>
int main() {
    int x, num{0}, count{0};
    while (cin >> x) { // issue EOF to make cin fail (return false), `ctrl + d` for linux
        num += x;
        ++count;
    }
    std::cout << x << " times " << y << " equals " << x*y << std::endl;
    return 0;
}

bool ok;
ok = true;
ok = false;
ok = 11;        // any non-zero value is treated as true

int k = 10.25;  // .25 will be automatically be throw away, as result, k equals 10
int k{10.25};   // ERROR

int k = static_cast<int>(10.25); // one prefer cast way in c++

/*
 compound type
    reference
    pointer

 NOTE: reference or pointer's type must match
 NOTE: java pointer is c++ reference
 */

int x = 10;
int &y = x;     // & here is reference operator
int &z = x;     // all x, y, and z points to same storage
int &w;         // ERROR, reference no where

int x = 10;
int *p = &x;    // & here is address operator
                // *p is another name of x, *p = 20 equals x = 20

int a[5] = {10, 12, 6, 17, 22};     // array name (a) is always a pointer
a[0] = 20;
*a = 20;
a[1] = 18;
*(a+1) = 18;
++a;            // ERROR
int *p = a+3;   // p points to 17
const int size = 5;
int a[size] = {..., ..., };
// NOTE: these arrays are called dumb array, you cannot know the size of it

void doSomething(int &);            // declare method function
void doSomething(int &x) {
    ++x;
}
void modify(int* p) {
    ++ *p;
}
int main() {
    int y = 10;
    doSomething(y);                 // passing by reference
    modify(&y);                     // passing by pointer
}
int a = 10;
int *p1 = &a;
int **p2 = &p1;
// TODO: pass array to function, then call ++a[k], change the original value? YES!
// NOTE: in jave, everything is passed by value! (result is kind like passing by reference in c++)

/*
 nested scopes
    within the file, its global scope
    inner scope cannot access outer scope variable, but it can access golbal variable
 */

double a = 2.5;
int main() {
    int a = 3;
    while () { // within this scope, the line above"a = 3;" can never be reached as long as
               // there is a same variable name defined in within this scope
        char a = 'A';
        cout << ::a << a;           // output 2.5, then output A, :: means check the GLOBAL scope
    }
}

int a[5];                           // static array
int *c = new int;                   //
int *b = new int[5];                // dynamic array, need to be delete manually
delete c;
delete []b;

// sample input: 123x4.59ab
int x;
char ch;
double d;
char ch2;
cin >> x >> ch >> d >> ch2;

const int * p;                      // p is a pointer points to int constant
++p;
*p = 10;                            // ERROR

int x = 3;
int * const q = &x;                      // q is a constant pointer points to int
*q = 10;
++q;                                // ERROR, q is constant
const int * const t;                // T is a constant pointer points to int constant


//#include "string.h"
//#include<iostream>
//using namespace std;
//int main() {
//    char a[] = "ABC";
//    char b[] = {'A', 'B', 'C'};
//    cout << strcmp(a, b) << " " << strlen(a) << " " << strlen(b) << endl;
//    return 0;
//}































