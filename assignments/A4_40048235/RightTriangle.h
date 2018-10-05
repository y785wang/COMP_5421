#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Isosceles.h"

class RightTriangle : public Isosceles {
  private:
    int b;
  public:
    RightTriangle(int, string = "Class RightTriangle", string = "RightTriangle");
    virtual ~RightTriangle() override = default;
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

