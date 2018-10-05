#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <vector>
#include <iostream>
#include <cmath> // for the driver program, ambiguous call of abs on OS X

using std::vector;
using std::ostream;
using std::istream;

class Matrix2x2 {
  private:
    vector<double> entries;
  public:
    Matrix2x2();                                             // default ctor
    Matrix2x2(double, double, double, double);               // normal ctor
    Matrix2x2(const Matrix2x2 &) = default;                  // default copy ctor
    Matrix2x2& operator=(const Matrix2x2 &) = default;       // default assign op
    ~Matrix2x2() = default;                                  // default dtor

    friend istream& operator>>(istream &, Matrix2x2 &);      // output overload
    friend ostream& operator<<(ostream &, const Matrix2x2);  // input overload

    Matrix2x2 transpose() const;
    double determinant() const;
    double trace() const;
    bool isSymmetric() const;
    bool isSimilar(const Matrix2x2 &) const;
    Matrix2x2 inverse() const;
    
    Matrix2x2& operator+=(const Matrix2x2 &);                         // M += M'
    Matrix2x2& operator-=(const Matrix2x2 &);                         // M -= M'
    Matrix2x2& operator*=(const Matrix2x2 &);                         // M *= M'
    Matrix2x2& operator/=(const Matrix2x2 &);                         // M /= M'

    Matrix2x2& operator+=(const double &);                            // M += x'
    Matrix2x2& operator-=(const double &);                            // M -= x'
    Matrix2x2& operator*=(const double &);                            // M *= x'
    Matrix2x2& operator/=(const double &);                            // M /= x'

    friend Matrix2x2 operator+(const Matrix2x2 &, const Matrix2x2 &); // M + M'
    friend Matrix2x2 operator-(const Matrix2x2 &, const Matrix2x2 &); // M - M'
    friend Matrix2x2 operator*(const Matrix2x2 &, const Matrix2x2 &); // M * M'
    friend Matrix2x2 operator/(const Matrix2x2 &, const Matrix2x2 &); // M / M'

    friend Matrix2x2 operator+(const Matrix2x2 &, const double &);    // M + x
    friend Matrix2x2 operator-(const Matrix2x2 &, const double &);    // M - x
    friend Matrix2x2 operator*(const Matrix2x2 &, const double &);    // M * x
    friend Matrix2x2 operator/(const Matrix2x2 &, const double &);    // M / x

    friend Matrix2x2 operator+(const double &, const Matrix2x2 &);    // x + M
    friend Matrix2x2 operator-(const double &, const Matrix2x2 &);    // x - M
    friend Matrix2x2 operator*(const double &, const Matrix2x2 &);    // x * M
    friend Matrix2x2 operator/(const double &, const Matrix2x2 &);    // x / M

    friend bool operator==(const Matrix2x2 &, const Matrix2x2 &);     // M == M
    friend bool operator!=(const Matrix2x2 &, const Matrix2x2 &);     // M != M

    Matrix2x2 operator+() const;                                      // unary +
    Matrix2x2 operator-() const;                                      // unary -
    
    Matrix2x2& operator++();                // unary prefix increment
    Matrix2x2& operator--();                // unary prefix decrement

    Matrix2x2 operator++(int);              // unary postfix increment
    Matrix2x2 operator--(int);              // unary postfix decrement
    
    const double& operator[](int) const;    // subscript operator: read-only
    double& operator[](int);                // subscript operator: read and write
    
    vector<double> operator()(int);         // calculate eigenvalues
    double operator()() const;              // calculate determinant
};

void printEigenvalues(vector<double>, int); // print one of eigenvalues


#endif
