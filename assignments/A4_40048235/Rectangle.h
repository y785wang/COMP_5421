#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
  private:
    int width;
    int height;
  public:
    Rectangle(int, int, string = "Class Rectangle", string = "Rectangle");
    virtual ~Rectangle() override = default;
    virtual string toString() const override;
    virtual double geoArea() const override;
    virtual double geoPerimeter() const override;
    virtual int scrArea() const override;
    virtual int scrPerimeter() const override;
    virtual void draw(Canvas &, int, int, char = '*', char = ' ') const override;
    virtual int getHeight() const override;
    virtual int getWidth() const override;
};

#endif
