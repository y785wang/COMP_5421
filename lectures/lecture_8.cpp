// Lecture 8, Wed. July 4

// AVOID: using local static variables in a function
// e.g., if we want 0, 1, 2, 3, 4, 8, f(k) = f(k-1) + f(k-2)
int fib() { // bad example, do not use static
    static int fkm1 = 0; // f(k-1)
    static int fkm2 = 1;
    int sum = fkm1 + fkm2;
    fkm2 = fkm1;
    fkm1 = sum;
    return sum;
}

for (int i = 0; i <= 5; ++i) {
//    cout << fib() << endl;
}

class Fib {
  private:
    int fkm1, fkm2;
  public:
    Fib() = default;
    int operator()() {
        int sum = fkm2 + fkm1;
        fkm2 = fkm1;
        fkm1 = sum;
        return sum;
    }
};
cout << f1() << endl;
cout << f1() << endl;
cout << f2() << endl;


/**************************************************
 
 UML
 
 **************************************************/
// class A uses/depends-on class B, dash-arrow points from A to B
class A {
    void f() {
        B b;
    }
    void g(B b) {}
};

// class A has class B as data member, arrow points from A to B
class A {
    B b;
};

// solid-dimond-arrow points from FACULTY to DEPARTMENT, called composition
// empty-dimond-arrow points from FACULTY to PROFESSOR, called aggregation

class B {
  public:
    B() { cout << "B" << endl; }
    ~B() { cout << "~B" << endl; }
};

class D : public B {
  public:
    D() { cout << "D" << endl; }
    ~D() { cout << "~D" << endl; }
}

{
    B b1; // B
    D d1; // B D
    {
        D d2; //B D
    } // ~D ~B
} // ~D ~B ~B

B b;
D d;
d = b; // error, D part is un-defined
b = d; // no error

/**************************************************
 
 Dynamic polymorphism
    pointer or reference
    virtual
    hirerachy
 
 **************************************************/
// compile-time binding
// runtime binding
class B { void f() };
class D1 public B { void f() };
class D2 public D1 { void f()};
B *pd = new D; // B D
delete pb; // ~B
// in other to also delete D part, make dtor of B virtual
class b {
    virtual ~B() {};
}
delete pd; // ~D ~B

// if the base class dtor is virtual, then the direved calss is
// automatically be virtual, but suggest write it as well for
// subclass

class Shape {
  public:
    virtual double area() = 0; // if =0 is add, then it becomes pure virtual
    // NOTE: if there is one pure virtual member function found, then whole class is
    // abstract. If a subclass does not implemente this pure virtual class, then the
    // subclass become abstract
};
class Rectangle : public Shape {
  public:
    // override make sure there is a same method
    // in base class, it won't complied otherwise
    virtual double area(int) override; // error, no area(int) found in base class
    virtual double area() override; // ok
};

Shape *ps;
int k = rand() / /2;
if (0 == k) {
    ps = new Rectangle;
} else {
    ps = new Cycle;
}
ps->area(); // polymorphic call
/* static type of ps is shape, dynamic type is Rectangle or Cycle.
 if area is virtual, then ps will use the static type, dynamic type
 otherwise */

void printArea(Shape &s) { // 1)
    cout << s.area() << endl;
}
void printArea(Shape *ps) { // 2)
    cout << ps->area() << endl;
}
Shape sh; // if Shape is abstract, this becomes error
Rectangle r;
Cycle c;
printArea(r); // call 1)
printArea(&c); // call 2)

class B {
  public:
    B();
    B(double);
};
class D : public B {
  public:
    D() : B() {}
    D(double) : B(d){}
    // instead writing all parent's ctors, write the following
    using B::B;
}

class B {
  public:
    B() = defaule;
    B(int) = delete;
    B(double);
}
B b1(10); // error
B b2(11.9); //
B b3;
b3 = 10; // error




















