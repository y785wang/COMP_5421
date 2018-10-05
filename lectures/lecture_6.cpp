// Lecture 6, Wed. June 6




// NOTE: const obejct can call const emthods
// ?: only ternary operator
// = does not always mean assignment operator, for assignment operator works,
//      both side of it should have already existed
//      Vec temp = *this, Vec temp(*this) are copy ctors

// overload operator<< as member
class Foo {
  private:
    int x = 10;
  public:
    friend ostream& operator<< (ostream& out) { // out is rhs
        out << x;
        return out;
    }
}
Foo f;
f.operator<<(cout); // equals f << cout;

Class clock {
    int sec;
    int num;
    int hours;
}
Clock c(10, 20, 14);
// can overload operater[] to imply c[0] = 12 equals c.setSec(12)
// doable, but not suggested
int& operator[] (int k) {
    k = k % 3; // k = 0, 1, 2
    if (0 == k) {
        return sec;
    } else if (1 == k) {
        return num;
    } else {
        return hours;
    }
}


Vec f(Vec v){
    return c;
}
Vec a{1, 2, 3};
Vec b = f(a);


{
    Vec a{1, 2, 3};
    Vec b = a;
    {
        Vec c(a);
    }
}
/* sequence as LIFO
 normal ctor for a
 copy ctor for b
 copy ctor for c
 dtor for c
 dtor for b
 dtor for a
 */

/**************************************************
 
 ...
 
 **************************************************/


/*
 const:
    var
    function
    parameter
 calling function passing args by
    value
    reference
    paramter
 Arrays + paramters
 */
 
 a[k] equals *(a+k)
 a[i][j] equals *(a[i]+j) equals *(*(a+i)+j)
 int a[5];
 int *p = a+3;
 int *p = &a[3];
 *p++ equals *(p++)
 *(++p) equals *(++p) // *(copy of *p)??

int x = 10;
int *q = &x;
int *q = new int[3];
int **q = &q;
int **q = new int*[3];
int* r[3] = new int*[3];// error
int* r[3] = { new int, new int, new int(20) }
r[0] = new int(10);
r[1] = new int(20);
// stack: x, q, p, r
// heap: r[0], r[1];


// delete first node of a nodelist example
int main() {
    if (nullptr == first) { // no node case
        cout << "ERROR" << endl;
        exit(1);
    } else if (nullptr == first->next) { // single node case
        delete first;
        first = last = nullptr;
    } else { // more tha one node case
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}




















/*
 for midterm: book c++ how to program
 1) read chapter 8, 9, 10
 2) explicit: to avoid `Foo = int`
 
