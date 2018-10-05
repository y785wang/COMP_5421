// Lecture 12, Wed. Aug 1

/* complier automatically convert lambda expression
to a class*/
int x = 10;
auto f = [x](double a) { /* do something */ }
class lambda {
    int x;
  public:
    lambda(int x) : x(x) {}
    void operator()(double a) { /* do something */ }
}

// NOTE: never use dtor explicitly

/**************************************************
 
 virtual table
    every class has a cirtual table
    every obejct has a pointer points to the VT
 
 **************************************************/
class B {
  public:
    virtual ~B();
    virtual void f1();
    virtual char f2(int);
    virtual void f3();
    void f4();
};
class D : public B {
  public:
    virtual void f1();
    virtual void g();
    virtual void f3();
}
/* b table   d table
   B::f1  |  D::f1
   B::f2  |  B::f2
   B::f3  |  D::g
   B::f4  |  D::f3
 
 /**************************************************
 
 shared_ptr
 
 **************************************************/
{
    int *p = new int(10);
    shared_ptr<int> sp1(p);
    shared_ptr<int> sp2(p);
}
// error, double delete p when sp2 out of scope

class Rectangle {
  public:
    int getH();
    int getW();
    int area();
}
class Rectland : Rectangle {
    double cost_m2;
  public:
    double getCost() {
        return area() * cost_m2;
        // do not write getH() * getW() * cost_m2;
        // re-use all avaliable functions
    }
}


/* Final
 A3, A4, A5 + lectures after midterm
 multiple choice
    inheritance
        ctor, dtor
        polymorphism (virtual function, table, calls)
        friends
    overloading
        container, stl algorithm, iterator
    code tracing

 20% programming
 5% exception
 5% smart pointer







