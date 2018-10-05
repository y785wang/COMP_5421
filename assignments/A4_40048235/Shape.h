#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include "Canvas.h"

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::fixed;
using std::ostream;

class Shape {
  private:
    static int count;
    int ID;
    string name;
    string description;
  public:
    Shape(string, string);
    virtual ~Shape() = default;
    friend ostream& operator<<(ostream &, const Shape &);
    
    int getID() const ;
    string getName() const ;
    string getDescription() const ;
    void setName(string);
    void setDescription(string);
    virtual string toString() const = 0;
    virtual double geoArea() const = 0;
    virtual double geoPerimeter() const = 0;
    virtual int scrArea() const = 0;
    virtual int scrPerimeter() const = 0;
    virtual void draw(Canvas &, int, int, char = '*', char = ' ') const = 0;
    virtual int getHeight() const = 0;
    virtual int getWidth() const = 0;
};

#endif
