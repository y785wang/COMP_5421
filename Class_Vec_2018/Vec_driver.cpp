#include<iostream>
#include<iomanip>
using namespace std;

#include "Vec.h"

int main()
{
    try
    {
        Vec a;
        cin >> a; // will prompt for and reads 10 inegers
        cout << a << endl;

        Vec b{ 1,2,3,4,5,6,7,8,9 };
        cout << left << setw(20) << "b: " << b << endl;

        cout << left << setw(20) << " b.reverse(): " << b.reverse() << endl;
        Vec c = b.reverse();
        cout << left << setw(20) << "c = b reversed: " << c << endl;

        // add 1 to every element of c
        c += 1;
        cout << left << setw(20) << "c += 1: " << c << endl;

        // add 1 to every element of c
        c = c + 1;
        cout << left << setw(20) << "c = c + 1: " << c << endl;

        // copy b+c to d
        Vec d = b + c;
        cout << left << setw(20) << "d = b + c: " << d << endl;

        // add -2 to every element of d
        d -= 2;
        cout << left << setw(20) << "d -= 2: " << d << endl;

        // copy b-c to e
        Vec e = b - c;
        cout << left << setw(20) << "e = b - c: " << e << endl;

        // multiply every element of e by -2
        e = e * (-2);
        cout << left << setw(20) << "e = e * (-2): " << e << endl;

        // multiply every element of e by -2
        e = 2 * e;
        cout << left << setw(20) << "e = 2 * e: " << e << endl;

        // devide every element of e by 4
        e = e / 4;
        cout << left << setw(20) << "e = e / 4: " << e << endl;

        // demo initializer-list
        Vec f = { 1, 2, 3 }, g = { 2, 3 };
        cout << "f: " << f << endl;
        cout << "g: " << g << endl;

        cout << f << " is" << ((f < g) ? "" : " not") << " less than " << g << endl;
        cout << f << " is" << ((f <= g) ? "" : " not") << " less than or equal to " << g << endl;
        cout << f << " is" << ((f > g) ? "" : " not") << " greater than " << g << endl;
        cout << f << " is" << ((f >= g) ? "" : " not") << " greater than or equal to" << g << endl;
        cout << f << " and " << g << " are " << ((f == g) ? "" : " not") << " equal" << endl;
        cout << f << " and " << g << " are " << ((f != g) ? "" : " not") << " unequal" << endl;

        Vec h{ 1,2,3 }, hh{ 2,3,4 }, hhh{ 3,4,5 };

        Vec r = hh;
        r = r++;
        cout << "r: " << r << endl;
        if (r != hh)
        {
            throw logic_error("error: operator++(int)");
        }
        cout << "r: " << r << endl;

        Vec s = hh;
        s = s--;
        cout << "s: " << s << endl;
        if (s != hh)
        {
            throw logic_error("error: operator--(int)");
        }
        cout << "s: " << s << endl;

        Vec rr = hh;
        ++rr;
        cout << "rr: " << rr << endl;
        if (rr != hhh)
        {
            throw logic_error("error: operator++");
        }
        cout << "rr: " << rr << endl;

        Vec ss = hh;
        --ss;
        cout << "ss: " << ss << endl;
        if (ss != h)
        {
            throw logic_error("error: operator--");
        }
        cout << "ss: " << ss << endl;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    catch (std::logic_error& le)
    {
        std::cerr << "logic error : " << le.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "catch-all error  " << '\n';
    }
    return 0;
}
