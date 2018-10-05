#include "Matrix2x2.h"

#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
//using std::defaultfloat; // HB lab g++ version is too low to do it
using std::left;
using std::right;
using std::to_string;
using std::ostringstream;
using std::invalid_argument;
using std::overflow_error;




/**************************************************
 
 Description:
 Default ctor, sets all four entries to zero
 
 Parameters:
 None
 
 Returns:
 None
 
 **************************************************/
// works for HB lab Linux terminal
// Matrix2x2::Matrix2x2() : entries{0,0,0,0} {}
// works for HB lab win7 vs2013
Matrix2x2::Matrix2x2() {
    entries.push_back(0);
    entries.push_back(0);
    entries.push_back(0);
    entries.push_back(0);
}




/**************************************************
 
 Description:
 Normal ctor, accepts initial values for all four
 entries as parameters
 
 Parameters:
 a: first entry
 b: second entry
 c: third entry
 d: forth entry
 
 Returns:
 None
 
 **************************************************/
// works for HB lab Linux terminal
// Matrix2x2::Matrix2x2(double a, double b, double c, double d) : entries{a,b,c,d} {};
// works for HB lab win7 vs2013
Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
    entries.push_back(a);
    entries.push_back(b);
    entries.push_back(c);
    entries.push_back(d);
}




/**************************************************
 
 Description:
 Input operator overloading. For test purpose, it
 asks users to enter four numbers a, b, c, d as
 four entries of the matrix
 
 Parameters:
 in: accept user inputs, then store them into matrix
 m: the matrix that store the user inputs
 
 Returns:
 Istream& in.
 
 **************************************************/
istream& operator>>(istream &in, Matrix2x2 &m) {
    cout << "To create the following 2x2 matrix: " << endl;
    cout << "|a  b|" << endl;
    cout << "|    |" << endl;
    cout << "|c  d|" << endl;
    cout << "enter four numbers a, b, c, d, in that order:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        in >> m[i];
    }
    return in;
}




/**************************************************
 
 Description:
 Output operator overloading. Represent the Matrix2x2
 as a hand-writting matrix form. The columns are
 separated by a space but wide enough to house each
 entry.
 
 Parameters:
 out: receive matrix representation and notation
      by a specific form
 m: matrix that need to be represented
 
 Returns:
 Ostream& out.
 
 **************************************************/
ostream& operator<<(ostream &out, const Matrix2x2 m) {
    int leftWidth, rightWidth;
    int la, lb, lc, ld; // length for these entries
    
    ostringstream oss;
    oss << (int)m[0];
    la = oss.str().length();
    if (-1 < m[0] && m[0] < 0) ++la;
    oss.str("");
    oss << (int)m[1];
    lb = oss.str().length();
    if (-1 < m[1] && m[1] < 0) ++lb;
    oss.str("");
    oss << (int)m[2];
    lc = oss.str().length();
    if (-1 < m[2] && m[2] < 0) ++lc;
    oss.str("");
    oss << (int)m[3];
    ld = oss.str().length();
    if (-1 < m[3] && m[3] < 0) ++ld;

    leftWidth = la > lc ? la + 3 : lc + 3;
    rightWidth = lb > ld ? lb + 3 : ld + 3;
    
    out << fixed << setprecision(2);
    out << "|" << setw(leftWidth) << right << m[0];
    out << setw(rightWidth + 1) << right << m[1] << "|" << endl;
    out << "|" << setw(leftWidth + rightWidth + 2) << "|" << endl;
    out << "|" << setw(leftWidth) << right << m[2];
    out << setw(rightWidth + 1) << right << m[3] << "|" << endl;
    // out << defaultfloat;
    out.unsetf(std::ios_base::floatfield);
    
    return out;
}




/**************************************************
 
 Description:
 Generate a transposed matrix of the invoking one,
 return the transposed one
 
 Parameters:
 None
 
 Returns:
 Transposed matrix of the invoking one
 
 **************************************************/
Matrix2x2 Matrix2x2::transpose() const {
    Matrix2x2 temp;
    temp[0] = entries[0];
    temp[1] = entries[2];
    temp[2] = entries[1];
    temp[3] = entries[3];
    return temp;
}




/**************************************************
 
 Description:
 Calculate the determinant of the invoking matrix,
 return the determinant
 
 Parameters:
 None
 
 Returns:
 Determinant of the invoking matrix
 
 **************************************************/
double Matrix2x2::determinant() const {
    return entries[0] * entries[3] - entries[1] * entries[2];
}




/**************************************************
 
 Description:
 Calculate the trace of the invoking matrix,
 return the trace
 
 Parameters:
 None
 
 Returns:
 Trace of the invoking matrix
 
 **************************************************/
double Matrix2x2::trace() const {
    return entries[0] + entries[3];
}




/**************************************************
 
 Description:
 Determine if the invoking matrix is symmetric or
 not
 
 Parameters:
 None
 
 Returns:
 True if the invoking matrix is symmetric, false
 otherwise
 
 **************************************************/
bool Matrix2x2::isSymmetric() const {
    if (entries[1] == entries[2]) {
        return true;
    } else {
        return false;
    }
}




/**************************************************
 
 Description:
 Determine if the invoking matrix is similar to
 the parameter m
 
 Parameters:
 m: matrix to be compared with the invoking one
 
 Returns:
 True if the invoking matrix is similar to the
 parameter m
 
 **************************************************/
bool Matrix2x2::isSimilar(const Matrix2x2 &m) const {
    if(this->determinant() == m() && this->trace() == m.trace()) {
        return true;
    } else {
        return false;
    }
}




/**************************************************
 
 Description:
 Generate the inversed matrix of the invoking one,
 return the inversed one
 
 Parameters:
 None
 
 Returns:
 Inversed matrix of the invoking one
 
 **************************************************/
Matrix2x2 Matrix2x2::inverse() const {
    double d = determinant();
    if (-1.0e-6 <= d && d <= 1.0e-6) throw overflow_error("Inverse undefined");
    Matrix2x2 temp(1/d*entries[3], 1/d*-entries[1], 1/d*-entries[2], 1/d*entries[0]);
    return temp;
}




/**************************************************
 
 Description:
 Addition. The invoking matrix adds another matrix,
 return the invoking one
 
 Parameters:
 Matrix that to be added
 
 Returns:
 The invoking matrix.
 
 **************************************************/
Matrix2x2& Matrix2x2::operator+=(const Matrix2x2 &m) {
    entries[0] += m[0];
    entries[1] += m[1];
    entries[2] += m[2];
    entries[3] += m[3];
    return *this;
}




/**************************************************
 
 Description:
 Subtraction. The invoking matrix substracts another
 matrix, return the invoking one
 
 Parameters:
 Matrix that to be subtracted
 
 Returns:
 The invoking matrix.
 
 **************************************************/
Matrix2x2& Matrix2x2::operator-=(const Matrix2x2 &m) {
    entries[0] -= m[0];
    entries[1] -= m[1];
    entries[2] -= m[2];
    entries[3] -= m[3];
    return *this;
}




/**************************************************
 
 Description:
 Multiplication. The invoking matrix multiplies
 another matrix, return the invoking one
 
 Parameters:
 Matrix that to be multiplied
 
 Returns:
 The invoking matrix.
 
 **************************************************/
Matrix2x2& Matrix2x2::operator*=(const Matrix2x2 &m) {
    double a = entries[0] * m[0] + entries[1] * m[2];
    double b = entries[0] * m[1] + entries[1] * m[3];
    double c = entries[2] * m[0] + entries[3] * m[2];
    double d = entries[2] * m[1] + entries[3] * m[3];
    entries[0] = a;
    entries[1] = b;
    entries[2] = c;
    entries[3] = d;
    return *this;
}




/**************************************************
 
 Description:
 Division. The invoking matrix divides another matrix,
 return the invoking one
 
 Parameters:
 Matrix that to be divided
 
 Returns:
 The invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator/=(const Matrix2x2 &m) {
    Matrix2x2 temp1(*this);
    Matrix2x2 temp2(m);
    temp1 *= temp2.inverse();
    entries[0] = temp1[0];
    entries[1] = temp1[1];
    entries[2] = temp1[2];
    entries[3] = temp1[3];
    return *this;
}




/**************************************************
 
 Description:
 Scalare addition. The invoking matrix adds a real
 number, return the invoking matrix
 
 Parameters:
 Real number that to be added
 
 Returns:
 The invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator+=(const double &x) {
    entries[0] += x;
    entries[1] += x;
    entries[2] += x;
    entries[3] += x;
    return *this;
}




/**************************************************
 
 Description:
 Scalare subtraction. The invoking matrix subtracts
 a real number, return the invoking matrix
 
 Parameters:
 Real number that to be subtracked
 
 Returns:
 The invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator-=(const double &x) {
    entries[0] -= x;
    entries[1] -= x;
    entries[2] -= x;
    entries[3] -= x;
    return *this;
}




/**************************************************
 
 Description:
 Scalare multiplication. The invoking matrix multiplies
 a real number, return the invoking matrix
 
 Parameters:
 Real number that to be multiplied
 
 Returns:
 The invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator*=(const double &x) {
    entries[0] *= x;
    entries[1] *= x;
    entries[2] *= x;
    entries[3] *= x;
    return *this;
}




/**************************************************
 
 Description:
 Scalare division. The invoking matrix divides
 a real number, return the invoking one
 
 Parameters:
 Real number that to be divided
 
 Returns:
 The invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator/=(const double &x) {
    if (-1.0e-6 <= x && x <= 1.0e-6) throw overflow_error("Division by zero");
    entries[0] /= x;
    entries[1] /= x;
    entries[2] /= x;
    entries[3] /= x;
    return *this;
}




/**************************************************
 
 Description:
 Addition. A matrix adds another matrix, return
 the result matrix
 
 Parameters:
 m1: one matrixm, for m1+m2
 m2: another matrix, for m1+m2
 
 Returns:
 The result matrix of addition
 
 **************************************************/
Matrix2x2 operator+(const Matrix2x2 &m1, const Matrix2x2 &m2) {
    Matrix2x2 temp(m1);
    temp += m2;
    return temp;
}




/**************************************************
 
 Description:
 Subtraction. A matrix subtracts another matrix,
 return the result matrix
 
 Parameters:
 m1: one matrix, for m1-m2
 m2: another matrix, for m1-m2
 
 Returns:
 The result matrix of subtraction
 
 **************************************************/
Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2) {
    Matrix2x2 temp(m1);
    temp -= m2;
    return temp;
}




/**************************************************
 
 Description:
 Multiplication. A matrix multiplies to another
 matrix, return the
 result matrix
 
 Parameters:
 m1: one matrix, for m1*m2
 m2: another matrix, for m1*m2
 
 Returns:
 The result matrix of multiplication
 
 **************************************************/
Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2) {
    Matrix2x2 temp(m1);
    temp *= m2;
    return temp;
}




/**************************************************
 
 Description:
 Division. A matrix divides another matrix, return
 the result matrix
 
 Parameters:
 m1: one matrix, for m1/m2
 m2: another matrix, for m1/m2
 
 Returns:
 The result matrix of division
 
 **************************************************/
Matrix2x2 operator/(const Matrix2x2 &m1, const Matrix2x2 &m2) {
    Matrix2x2 temp(m1);
    temp /= m2;
    return temp;
}




/**************************************************
 
 Description:
 Scalar addition. A matrix adds a real number,
 return the result matrix
 
 Parameters:
 m: one matrix, for m1+x
 x: one real number, for m1+x
 
 Returns:
 The result matrix of addition
 
 **************************************************/
Matrix2x2 operator+(const Matrix2x2 &m, const double &x) {
    Matrix2x2 temp(m);
    temp += x;
    return temp;
}




/**************************************************
 
 Description:
 Scalar subtraction. A matrix subtracts a real number,
 return the result matrix
 
 Parameters:
 m: one matrix, for m-x
 x: one real number, for m-x
 
 Returns:
 The result matrix of subtraction
 
 **************************************************/
Matrix2x2 operator-(const Matrix2x2 &m, const double &x) {
    Matrix2x2 temp(m);
    temp -= x;
    return temp;
}




/**************************************************
 
 Description:
 Scalar multiplication. Matrix multiply a real number,
 return the result matrix
 
 Parameters:
 m: one matrix, for m*x
 x: one real number, for m*x
 
 Returns:
 The result matrix of multiplication
 
 **************************************************/
Matrix2x2 operator*(const Matrix2x2 &m, const double &x) {
    Matrix2x2 temp(m);
    temp *= x;
    return temp;
}




/**************************************************
 
 Description:
 Scalar division. Matrix divide a real number,
 return the result matrix
 
 Parameters:
 m: one matrix, for m/x
 x: one real number, for m/x
 
 Returns:
 The result matrix of division
 
 **************************************************/
Matrix2x2 operator/(const Matrix2x2 &m, const double &x) {
    Matrix2x2 temp(m);
    temp /= x;
    return temp;
}




/**************************************************
 
 Description:
 Scalar addition. A real number adds a matrix,
 return the result matrix
 
 Parameters:
 x: one real number, for x+m
 m: one matrix, for x+m
 
 Returns:
 The result matrix of addition
 
 **************************************************/
Matrix2x2 operator+(const double &x, const Matrix2x2 &m) {
    return m + x;
}




/**************************************************
 
 Description:
 Scalar subtraction. A real number subtracts a
 matrix, return the result matrix
 
 Parameters:
 x: one real number, for x-m
 m: one matrix, for x-m
 
 Returns:
 The result matrix of subtraction
 
 **************************************************/
Matrix2x2 operator-(const double &x, const Matrix2x2 &m) {
    Matrix2x2 temp(m);
    temp[0] = x - m[0];
    temp[1] = x - m[1];
    temp[2] = x - m[2];
    temp[3] = x - m[3];
    return temp;
}




/**************************************************
 
 Description:
 Scalar multiplication. A real number multiplies a
 matrix, return the result matrix
 
 Parameters:
 x: one real number, for x*m
 m: one matrix, for x*m
 Returns:
 The result matrix of multiplication
 
 **************************************************/
Matrix2x2 operator*(const double &x, const Matrix2x2 &m) {
    Matrix2x2 temp(m);
    temp *= x;
    return temp;
}




/**************************************************
 
 Description:
 Scalar division. A real number divides a matrix,
 return the result matrix
 
 Parameters:
 x: one real number, for x/m
 m: one matrix, for x/m
 
 Returns:
 The result matrix of division
 
 **************************************************/
Matrix2x2 operator/(const double &x, const Matrix2x2 &m) {
    Matrix2x2 temp(m);
    return x * temp.inverse();
}




/**************************************************
 
 Description:
 Determine if two matrixes are equal
 
 Parameters:
 m1: one matrix
 m2: another matrix
 
 Returns:
 True if two matrixes are equal, false otherwise
 
 **************************************************/
bool operator==(const Matrix2x2 &m1, const Matrix2x2 &m2) {
    if (m1[0] == m2[0] && m1[1] == m2[1] &&
        m1[2] == m2[2] && m1[3] == m2[3]) {
        return true;
    } else {
        return false;
    }
}




/**************************************************
 
 Description:
 Determine if two matrixes are not equal
 
 Parameters:
 m1: one matrix
 m2: another matrix
 
 Returns:
 True if two matrixes are not equal, false otherwise
 
 **************************************************/
bool operator!=(const Matrix2x2 &m1, const Matrix2x2 &m2) {
    return !(m1 == m2);
}




/**************************************************
 
 Description:
 Do nothing
 
 Parameters:
 None
 
 Returns:
 Return the invoking matrix
 
 **************************************************/
Matrix2x2 Matrix2x2::operator+() const {
    return *this;
}




/**************************************************
 
 Description:
 Multiply the invoking matrix by -1
 
 Parameters:
 None
 
 Returns:
 Return the negative matrix of the invoking one
 
 **************************************************/
Matrix2x2 Matrix2x2::operator-() const {
    Matrix2x2 temp(*this);
    temp *= -1;
    return temp;
}




/**************************************************
 
 Description:
 Pre-increment. Add invoking matrix by 1
 
 Parameters:
 None
 
 Returns:
 Return the invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator++() {
    *this += 1;
    return *this;
}




/**************************************************
 
 Description:
 Pre-decrement. Subtract invoking matrix by 1
 
 Parameters:
 None
 
 Returns:
 Return the invoking matrix
 
 **************************************************/
Matrix2x2& Matrix2x2::operator--() {
    *this -= 1;
    return *this;
}




/**************************************************
 
 Description:
 Post-increment. Duplicate the invoking matrix, add
 one to the invoking matrix
 
 Parameters:
 None
 
 Returns:
 Return the duplicated one
 
 **************************************************/
Matrix2x2 Matrix2x2::operator++(int) {
    Matrix2x2 temp(*this);
    *this += 1;
    return temp;
}




/**************************************************
 
 Description:
 Post-decrement. Duplicate the invoking matrix,
 subtract one from the invoking matrix
 
 Parameters:
 None
 
 Returns:
 Return the duplicated one
 
 **************************************************/
Matrix2x2 Matrix2x2::operator--(int) {
    Matrix2x2 temp(*this);
    *this -= 1;
    return temp;
}




/**************************************************
 
 Description:
 Subscripts, const version. Based on the index,
 return one of four entries. Read-only.
 
 Parameters:
 Index that determines which entry should be return
 
 Returns:
 One of four entries
 
 **************************************************/
const double& Matrix2x2::operator[](int index) const {
    if (index < 0 || index >= 4) {
        throw invalid_argument("invalid argument");
    }
    return entries[index];
}




/**************************************************
 
 Description:
 Subscripts, non-const version. Based on the index,
 return one of four entries. Read and write.
 
 Parameters:
 Index that determines which entry should be return
 
 Returns:
 One of four entries
 
 **************************************************/
double& Matrix2x2::operator[](int index) {
    if (index < 0 || index >= 4) {
        throw invalid_argument("invalid argument");
    }
    return entries[index];
}




/**************************************************
 
 Description:
 Calculate eigenvalues for invoking matrix
 
 Parameters:
 Determine which eigenvalue is needed
 
 Returns:
 vector<double>, represent an eigenvalue, contains
 both real and imag part
 
 **************************************************/
vector<double> Matrix2x2::operator()(int index) {
    if (1 != index && 2 != index) {
        throw invalid_argument("invalid argument");
    } else {
        double real = trace() / 2;
        double imag;
        double imagSquare = real * real - determinant();
        if (imagSquare >= 0) {
            real += sqrt(imagSquare);
            imag = 0;
        } else {
            imag = sqrt(-imagSquare);
        }
        if (2 == index) imag *= -1;
        vector<double> temp{ real, imag };
        return temp;
    }
}




/**************************************************
 
 Description:
 Calculate the determinant of the invoking matrix,
 return the determinant
 
 Parameters:
 None
 
 Returns:
 Determinant of the invoking matrix
 
 **************************************************/
double Matrix2x2::operator()() const {
    return entries[0] * entries[3] - entries[1] * entries[2];
}




/**************************************************
 
 Description:
 Print one of the eigenvalues from root based on the
 index
 
 Parameters:
 root: contains two eigenvalues
 index: determine which eigenvalues should be print
 
 Returns:
 None
 
 **************************************************/
void printEigenvalues(vector<double> root, int index) {
    if (1 != index && 2 != index) {
        throw invalid_argument("invalid argument");
    } else {
        cout << "root " << index << ": " << root[0]; // real part
        if (0 != root[1]) { // imag part
            if (1 == index) {
                cout << " +" << root[1] << "i" << endl;
            } else {
                cout << " " << root[1] << "i" << endl;
            }
        }
    }
}













