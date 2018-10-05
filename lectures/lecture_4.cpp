// Lecture 4, Wed. May 23

/**************************************************
 
 I/O processing
 
 **************************************************/

/*
 IOS
    istream
        ifstream
        istringstream
    ostream
        ofstream
        ostringstream
 
 IOS FLAGS
    failbit: set on input missmatch
    eofbit: CTRL+Z for windows, CTRL+d for unix
    badbit: serious problem
    goodbit: non of the other is set
*/

bool fail();
bool eof();
bool bad();
bool good();

char ch;
int count;
while (cin.get(ch)) ++count;
// sample input: `ABC` `enter` `CTRL D`
cout << count << endl; // count is 4

int x;
while (cin >> x) cout << x << endl;
cin >> x; // does not work
// sample input: `123  45` `enter` `97` `enter` `82 -10` `enter` `CTRL Z` `99` `enter`
/* output is
 123
 45
 97
 82
 -10
 */

char ch;
while (cin >> ch) cout << ch;
// sample input `A  B C` `enter` `   D` `enter`
// output is ABCD， `>>` cannot read space




/**********************

 input manipulators

 *********************
 
 dec decimal
 act octal
 hex hex 16
 set(n), set width to n
 ws, skip to front non-whitespace
 skipws, always skip ws
 noskipws, do not skip ws
 */
int x, y, z;
cin >> ct >> x; // 10
    >> dec >> y; // 12
    >> hex >> z; // 160
// sample input, 12 12 A0
cin >> ws;
cin >> noskipws >> ...
cin >> noskipwd;

cin.get();
cin.get(ch);
cin.getline(str, n=1; t='\n'); // str is a char array
// avoid this, instead use
getline(cin,  str); // str is c++ string object

cin.ignore(n=1, t=); // t is defaults EOF
cin.peak();
cin.putback(c);
cin.unget();




/**********************
 
 input manipulators
 
 *********************
 
 left, right, internal
 */
 cout << setw(5) << left << "ABC" << setw(7) << right << "XYZ";
// output is "ABC      XYZ"
cout << oct << 10; // 012
cout << hex << 165; // 0xA5

/*
 uppercase, nouppercase
 boolalpha, noalpha
 showbase, noshowbase (0xA5, A5)
 showpoint, noshowpoint
 showpos, noshowpos (+1, 1)
 */
cout << 1.0; // 1
cout << showpoint << 1.0; // 1.0

// setw, setfill(ch), setprecision(n)
cout << fixed << setprecision(2);
double x = 1.2345;
cout << x; // 1.23

// endl, flash (flash empty the cout buffer)
cout << endl; // same as cout << flash << '\n';

// can use cerr for error message, it immediately call flash




/***********************************
 
 extract all words from a text file
 
 ***********************************/
 
string filename;
cout << "Enter filename : " << endl;
cin >> filename;
ifstream fin(filename.c_str()); // may not need to be cstring, depends on compilers
ifstream fin;
fin.open(filename);
if (! fin) {
    cout << "Could not open " << filename << endl;
    exit(1); // may always need it, may want to continue sometimes
}
string word;
while (fin >> word) cout << word << endl;

string line;
int lineNumber = 0;
while (getline(fin, line)) {
    istringstream iss(line);
    string word;
    ++n;
    while (iss >> word) cout << word << " " << n >> endl;
}




/***********************************
 
 STL containers classes
 
 ***********************************/

/*
 sequential:
    list, vector, array, forward list, deque,
 association:
 map, set, multimap, multiset, ...
 */

#include <array>
array<int, 12> months = {...}
month[0] = 31;
for (int i = 0; i < months.size(); ++i) {
    ...
}

#include <vector>
vector<int> v;




/***********************************
 
 ITERATORS
 
 ***********************************/

int a[10] = {...};
for (int *p = a; p != a+10; ++p) { .... }

vector<int> v(a, a+10);
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) { ... }
// v.begin() equals begin(v), v.end() equals end(v) in c++11

array<int, 10> = { ... }
for (array<int, 10>::iterator it = a.begin(); it != a.end(); ++it) { ... }

list<int> il;
list<double> dl1, dl2;
dl1 = dl2;

vector<int> first; // empty vector of ints, ctor is called or not?
vector<int> first(); // frist is a function, takes no parameter, return vector<int>






/* TODO: for assignment 1
 1) ostream& operator << (ostream &out, const WordList &wl) {
        wl.print(out);
        return out;
    }
 2)





















