#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include "ctype.h"
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::insert_iterator;
using std::transform;
using std::equal;
using std::advance;
using std::vector;
using std::pair;
using std::count_if;
using std::bind;
using std::placeholders::_1;
using std::map;
using std::cin;
using std::istream_iterator;
using std::make_pair;
using std::multiset;
using std::copy;
using std::inserter;
using std::ostream_iterator;




/**************************************************
 
 Description: (function for problem 1)
 Take an string, determine whether is palindrom or not
 
 Parameters:
 phrase: string that to be determined for palindrom
 
 Returns:
 Return true is the string parameter is palindrom,
 false otherwise
 
 **************************************************/
bool is_palindrom(const string &phrase) {
    string temp;
    insert_iterator<string> iit (temp, temp.begin());
    remove_copy_if(phrase.begin(), phrase.end(), iit, [](char c) { return ' ' == c; });
    transform(temp.begin(), temp.end(), temp.begin(), toupper);
    string::iterator it = temp.begin();
    advance(it, temp.length()/2);
    return equal(temp.begin(), it, temp.rbegin());
}




/**************************************************
 
 Description: (function for problem 1)
 Test function
 
 Parameters:
 None
 
 Returns:
 None
 
 **************************************************/
void test_is_palindrome() {
    string str_i = string("Was it a car or a cat I saw");
    string str_u = string("Was it a car or a cat U saw");
    cout << "the phrase \"" + str_i + "\" is " + (is_palindrom(str_i) ? "" : "not ") + "a palindrom\n";
    cout << "the phrase \"" + str_u + "\" is " + (is_palindrom(str_u) ? "" : "not ") + "a palindrom\n";
}




/**************************************************
 
 Description: (function for problem 2)
 Function template. Take two iterators as range,
 find the second max value
 
 Parameters:
 start: iterator for beginning index
 finish: iterator for endding index
 
 Returns:
 Return a pair<Iterator, bool> for all three return
 case:
    1) If range is empty, return pair<finish, false>
    2) If all equal, return pair<start, false>
    3) At least to distinct, return pair<iter, true>
 
 **************************************************/
template <class Iterator>
pair<Iterator, bool> second_max(Iterator start, Iterator finish) {
    if (start == finish) return make_pair(finish, false);
    if (start+1 == finish) return make_pair(start, false);
    auto temp = start, firstLarge = start, secondLarge = start;
    while (++temp != finish) {
        if (*temp > *firstLarge) {
            secondLarge = firstLarge;
            firstLarge = temp;
        }
    }
    return *firstLarge == *secondLarge ? make_pair(start, false) : make_pair(secondLarge, true);
}




/**************************************************
 
 Description: (function for problem 2)
 Test function
 
 Parameters:
 None
 
 Returns:
 None
 
 **************************************************/
void test_second_max(vector<int> vec) {
    auto retval = second_max(vec.begin(), vec.end());
    if (retval.second) {
        cout << "The second largest element in vec is " << *retval.first << endl;
    } else {
        if (retval.first == vec.end()) {
            cout << "List empty, no elements\n";
        } else {
            cout << "Container's elements are all equal to " << *retval.first << endl;
        }
    }
}




/**************************************************
 
 Description: (function for problem 3A)
 Take a vector<string> and an integer, count the
 number of elements that have length less than n,
 using the count_if with lambda expression
 
 Parameters:
 vecstr: a vector of string that to be checked
 n: required length
 
 Returns:
 Return the number of element that satisfy the
 requirement
 
 **************************************************/
int countStringLambda(vector<string> vecstr, int n) {
    return count_if(vecstr.begin(), vecstr.end(), [n] (string s) { return s.length() < n; });
}




/**************************************************
 
 Description: (function for problem 3A)
 Take a string and an integer, determine if the
 string's length is less than the given integer
 
 Parameters:
 s: a string which length is need to be checked
 n: required length
 
 Returns:
 Return true if the length of s is satisfied,
 false otherwise
 
 **************************************************/
bool freeFun(string s, int n) {
    return s.length() < n;
}




/**************************************************
 
 Description: (function for problem 3C)
 Take a vector<string> and an integer, count the
 number of elements that have length less than n,
 using the count_if with a binded free function
 
 Parameters:
 vecstr: a vector of string that to be checked
 n: required length
 
 Returns:
 Return the number of element that satisfy the
 requirement
 
 **************************************************/
int countStringFreeFun(vector<string> vecstr, int n) {
    auto g = bind<bool>(freeFun, _1, n);
    return count_if(vecstr.begin(), vecstr.end(), g);
}




/**************************************************
 
 Description: (function for problem 3c)
 Function class, store required length internally
 during construction, overload operator() which
 takes a string, and do the length check
 
 Parameters:
 n: for ctor - store required length
 s: for op() - string which length needs to be check
 
 Returns:
 For op(), return true if string is satisfies the
 requirement, false otherwise
 
 **************************************************/
class ShorterLengthThan {
  private:
    int n;
  public:
    ShorterLengthThan(int n) : n(n) {};
    bool operator() (string s) { return s.length() < n; }
};




/**************************************************
 
 Description: (function for problem 3C)
 Take a vector<string> and an integer, count the
 number of elements that have length less than n,
 using the count_if with function object
 
 Parameters:
 vecstr: a vector of string that to be checked
 n: required length
 
 Returns:
 Return the number of element that satisfy the
 requirement
 
 **************************************************/
int countStringFunctor(vector<string> vecstr, int n) {
    return count_if(vecstr.begin(), vecstr.end(), ShorterLengthThan(n));
}




/**************************************************
 
 Description: (function for problem 4)
 Read, compute and print the frequency count of
 characters entered by te user in the stardard
 input stream cin
 
 Parameters:
 None
 
 Returns:
 None
 
 **************************************************/
void charFrequency() {
    cout << "Enter one or more lines of text.\n";
    cout << "To end input press Ctrl-Z in Windows and Ctrl-D in Linux\n";
    map<char, int> m;
    istream_iterator<string> start(cin);
    istream_iterator<string> eof;
    for_each(start, eof,
             [&m] (string s) {
                 for_each(s.begin(), s.end(),
                          [&m] (char c) {
                              char lowerCase = tolower(c);
                              map<char, int>::iterator it = m.find(lowerCase);
                              if (m.end() == it) {
                                  m.insert(make_pair(lowerCase, 1));
                              } else {
                                  it->second += 1;
                              }
                          });
                 
             });
    for_each(m.begin(), m.end(), [](pair<char, int> p){ cout << p.first << " " << p.second << endl; });
}




/**************************************************
 
 Description: (function for problem 5)
 Use default multiset sorting stragety, copy a vector
 or string in it, then output the result
 
 Parameters:
 None
 
 Returns:
 None
 
 **************************************************/
void multisetUsingDefaultComparator() {
    multiset<string> gibberish;
    vector<string> vec = { "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
    copy(vec.begin(), vec.end(), inserter(gibberish, gibberish.begin()));
    ostream_iterator<string> out(cout, " ");
    copy(gibberish.begin(), gibberish.end(), out);
}




/**************************************************
 
 Description: (function for problem 5)
 User-defined functor of a comparing strategy for
 multiet
 
 Parameters:
 s1: one string element
 s2: another string element
 
 Returns:
 Return true if s1 comes before s2 after sorting
 by using the new comparing strategy, false
 otherwise
 
 **************************************************/
bool fncomp(string s1, string s2) {
    return s1.length() < s2.length() || (s1.length()  ==  s2.length() && s1 < s2);
}




/**************************************************
 
 Description: (function for problem 5)
 Use user-defined sorting stragety for multiset,
 copy a vector or string in it, then output the result
 
 Parameters:
 None
 
 Returns:
 None
 
 **************************************************/
void multisetUsingDefinedComparator() {
    bool(*fn_pt)(string, string) = fncomp;
    multiset<string, bool(*)(string, string)> gibberish (fn_pt);
    vector<string> vec = { "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
    copy(vec.begin(), vec.end(), inserter(gibberish, gibberish.begin()));
    ostream_iterator<string> out(cout, " ");
    copy(gibberish.begin(), gibberish.end(), out);
}




/**************************************************
 
 Description:
 Main function for testing all 5 problems
 
 Parameters:
 None
 
 Returns:
 Return 0 for success
 
 **************************************************/
int main()
{
   // problem 1:
   test_is_palindrome();
   cout << "\n";

   // problem 2:
   std::vector<int> v1{ 1 }; // one element
   test_second_max(v1);

   std::vector<int> v2{ 1, 1 }; // all elements equal
   test_second_max(v2);

   std::vector<int> v3{ 1, 1, 3, 3, 7, 7}; // at least with two distict elements

   test_second_max(v3);
   cout << "\n";

   // problem 3:
   std::vector<std::string> vecstr
   { "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
      "range", "[first", "last)", "for", "which", "pred", "is", "true."
   };
   cout << countStringLambda(vecstr, 5) << endl;
   cout << countStringFreeFun(vecstr, 5) << endl;
   cout << countStringFunctor(vecstr, 5) << endl;
   cout << "\n";

   // problem 4:
   charFrequency();
   cout << "\n";

   // problem 5:
   multisetUsingDefaultComparator();
   cout << "\n";
   multisetUsingDefinedComparator();
   cout << "\n";

    return 0;
}


























