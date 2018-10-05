// Lecture 11, Wed. July 25

// For assignment 4
class Shape {
    static int idCount;
    int id;
  public:
    Shape(const string, const shppe &) {
        ++idCound;
        this->id = idCount;
    }
}
int Shape::idCount = 0;

/**************************************************
 
 how to create iterator for own container
 check ArrayWithIterator2018.pdf
 
 **************************************************/

vector<int> vec{1, 2, 3};
vector<int>:: iterator it;
sequence<int>::iterator it;
for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
//    cout << *itr; // need to be overloaded
}

/**************************************************
 
 associate container
    map, set, ...
 
 **************************************************/
// Note: for op map[key], if key does not exist, (key, empty) is added
// Note: std::pair

class Person {
  public:
    Person(const std::string &fname, const std::string & lname);
    void showPerson();
    friend bool operator<(const Person &, const Person &);
};
map<Person, std::string> phonebook;
phonebook.insert(std::make_pair(Person("Joe", "Jones"), "123-456-7890"));
phonebook[Person("Joe", "Jones")] = "123-456-7890"; //  check whether it works
auto entry = std::make_pair(Person("Joe", "Jones"), "123-456-7890");
personbook.insert(entry);

Person p("Joe", "Jones");
auto iter = phonebook.find(p);
if (iter == phonebook.end()) {
//    cout << "not found";
} else {
//    cout << "found";
}

std::Set<int> s = {1, 9, 212, -6};
std::multiset<int> s2 {1, 1, 9, 12, 12, 12, -6}; // [lower bound, uppper bound)

vector<int> vec {14, 19, -4, 6, 5};
std::multiset<int> s3(vec.begin(), vec.end());
std::copy(s3.begin(), s3.end(), /*soure container*/ vec.begin()/*destination*/);

/*given a vector*/ vector<int> v4, to copy v4 to an empty list
list<int> l;
std::copy(v4.begin(), v4.end(); std::back_inserter(l));

back_inserter(l);
back_insert_iterator<list<int>>(l);
front_inserter(l);
front_insert_iterator<list<int>>(l);
insert_inserter<list<int>>(l, l.begin()++/*starting insertion point*/);

void f(int a, char b, double d, string s, bool b); // assume b, s and d are fixed
void g(int a, double d) { f(a, "x", d, "ABC", true); } // old version
auto g = std::bind(f, _1, "x", _2, "ABC", true); // _1, _2 is actual arguments
g(10, 10.25);

FUNCTOR equals FUNCTION OBJECT

/**************************************************
 
 i/ostream iterator
 
 **************************************************/
double value1, value2;
std::istream_iterator<double> eos;              // end-of-stream iterator
std::istream_iterator<double> iit (std::cin);   // stdin iterator
if (iit!=eos) value1=*iit; // equals cin >> value1
++iit;
if (iit!=eos) value2=*iit; // equals cin >> value2

auto start = istream_iterator<int>(cin);
auto finish = istream_iterator<int>();
copy(start, finish, [](int x) { cout << x << endl; }); // does not work?
// above line equals while (cin >> x) { cout << x <, endl; }

std::vector<int> myvector;
for (int i=1; i<10; ++i) myvector.push_back(i*10); // 10, 20, ..., 90
std::ostream_iterator<int> out_it (std::cout,", ");
std::copy ( myvector.begin(), myvector.end(), out_it );
// output: 10, 20, 30, 40, 50, 60, 70, 80, 90,

// c_style cast
int(1.5);
(int)1.5;

// c++ static_cast
static_cast<double>(1.6);
orange = static_static<Apple>(orange);
class Foo {
  public:
    Foo(orange o);
};

// const_cast
const char *pch;
char *qch = const_cast<char *>(pch);

// reinterpret_cast
reinterpret_case<double>(12);

// dynamic_cast
class vehicle{};
class Bus : public vehicle {};
class Car :public vehicle {};
// RTTI (run time type identification)
void doSome(vehicle &v) {
    try {
        Car &c = dynamic_cast<Car&>(v); //  to check if v is a car
        // ...
    } catch (std::bad_cast &bc) {
        
    }
}
void doSome(vehicle *pr) {
    if (car *pc = dynamic_cast<Car *>(pv)) {
        
    } else {
        
    }
}

void h() {
    int *p = new int(10);
    int y = 1/0; // error, through exception
    delete [;]
}
void g(int) {
    h();
}
void f() {
    int x = 10;
    g(x);
}
int main() {
    f();
}
    










// for assignment 5
using namespace std::placeholders; // adds visibility of _1, _2, ...
double my_divide(double x, double y) { return x/y; }
auto fn_half = std::bind(my_divide, _1, 2);

// for final exam
// 5% for exception
// use `negate` and `transform` to negate all elements in a container
transform (v.begin(), v.end(), back_inserter(l), negate<int>()); // () for negate means it's an object
    // if dest is empty, front_inserter(l) is also ok as long as the dest is not vecter
    // use back_inserter(l) to avoid that the dest size is smaller than source
// know remove, remove_copy, remove_copy_if, remove_if
// know replace, replace_copy, replace_copy_if, replace_if









