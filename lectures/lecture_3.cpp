// Lecture 3, Wed. May 16

/**************************************************
 
 pointer, reference, const
 
 **************************************************/

// the following function change nothing, pass by value
void swap(int x, int y) {
    int t = x;
    x = y;
    y = t;
}
swap(a, b);

void swap(int *p, int *q) {
    int t = *p;
    *p = *q;
    *q = t;
}
swap(&a, &b);

void swap(int &x, int &y) {
    int t = x'
    x = y;
    y = t;
}
swap(a, b);

int& f(int &x) {
    return x;
}
f(x) = 10; // equals to "x = 10;"

// never return local variable as reference, because
// it will go out of the scope
int &g() {
    int y = 10;
    return y;
} // error

// paramter is also local variable, don't return
// it as reference
int& h(int y) {
    return y;
} // error

class Foo{}
void operator<<(ostream &out, const Foo &f) {
    // return type also could be "ostream &"
    return;
}
cout << f << 10; // does not work
// if want mutiple assignment works, has to return "ostream &"

int a = 10;
int &ra = a; // ok

const int b = 20;
int &rb = b; // error
const int &rc = b; // ok

int &rd = 10; // error
const int &re = 10; // ok

void h(int &x);
h(10); // error
int y = 20;
h(y); // ok

void h(const int &x);
h(10); // ok
const int y = 20;
h(y); // ok

Foo& operator=(const Foo &rhs) {
    if (this == &rhs) return *this;
    ...
    return *this;
}
Foo f, g;
f = g; // equals to "f.operator=(g);"

// for strcpy, one way
char* copy(char *dest, const char *source) {
    int i;
    for (i = 0; source[i] != '\0'; ++i) {
        dest[i] = source[i];
    }
    dest[k] = '\0';
    return dest;
}

// for strcpy, better way
char* copy(char *dest, const char *source) {
    char *start = dest;
    while (*dest++ = *source++); // equals (*(dset++) = *(source++))
    return start;
}

// NOTE:
a = 20; // "a = 20;" returns 20

// how to read the following
int a[10]; // start from a, go right, then left
           // a is an array of 10, int
int *pa[10]; // pa is an array of 10, pointers to int
int **pa[10]; // pa, is a pointer to an array of 10, int*

int (*f)(int); // f is a pointer to a function that takes an
               // int as parameter, and return an int
int triple(int x) {
    return 3 * x;
}
f = triple;
cout << f(2);

int* f(int); // f is a function that takes an int, returns a int *

const int a; // error, need to be initialize
int &b; // error
// NOTE: const and reference must be initialize by ctor

class Foo {
    int x;
    const int y;
    int &y;
    string name;
  public:
    Foo(int xx, int yy, int &zz, string name) : x(xx), y(yy), z(zz), name(name) {
        cout << "ctor: " << name << endl;
    }
    ~Foo() { cout <<< "dtor: " << endl; }
    Foo(const Foo &) = default; // default copy ctor
}

{ // suppose in a scope
    int a = 10, b = 20, c = 30;
    string name{"Joe"};
    Foo f(a, b, c, name); // ctor: Joe
    Foo g(a, b, c, "Jane"); // ctor : Jane
    {
        Foo h(a, b, c, "Bob"); // ctor : Bob
    } // Dtor: Bob
    Foo *pf = new Foo(a, b, c, "Marry"); // ctor: Marry
    delete pf; // dtor Marry
} // dtor: Jane; dtor: Joe

class Bar {
  private:
    int x;
  public:
    Bar(int x = 20) : x(x);
    int get() const { return x; } // this const make sure that get() does
                                  // not modify this object
    ostream &operator<<(ostream &out, const Bar &b) {
        out << b.get() << endl;
        return out;
    }
    void set(int x) {
        this->x = x;
    }
    Bar something();
    const Bar somethingElse();
}

Bar b1;
const Bar b2(40);
cout << b1.get();
cout << b2.get();
cout << b1 << b2;
b1.something().set(16); // ok, b1.something() returns tempory object
b1.somethingElse.set(16); // error

// conversion
class FooBar {
  public:
    FooBar(int);
    FooBar(char *);
};
FooBar f1, f2;
// below 2 line works if ctor take exactly argument like the rhs
f1 = 10; // equals f1 = FooBar(10);
f2 = "Hello"; // equals f2 = FooBar("Hello");
// also, the above two lines call ctor first, than call assignment operation,
// its not copy ctor because f1 is already constructed

// if don't want above functionality happened, then use "explicet" at the
// beginning of the ctor like "explicit FooBar(int);"



/* TODO: for assignment 1
 1) change copy loop
 2) change method to const as more as possible
 3) remember to delete all "new" stuf
 















