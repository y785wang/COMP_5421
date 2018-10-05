#ifndef ISOSCELES_H
#define ISOSCELES_H

#include "Shape.h"

class Isosceles : public Shape {
  public:
    Isosceles(string, string);
    virtual ~Isosceles() override = default;
    virtual string toString() const override = 0;
    virtual double geoArea() const override = 0;
    virtual double geoPerimeter() const override = 0;
    virtual int scrArea() const override = 0;
    virtual int scrPerimeter() const override = 0;
    virtual void draw(Canvas &, int, int, char, char) const override = 0;
    virtual int getHeight() const override = 0;
    virtual int getWidth() const override = 0;
};

#endif

