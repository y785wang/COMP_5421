#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {
  private:
    int d;
  public:
    Rhombus(int, string = "Class Rhombus", string = "Rhombus");
    virtual ~Rhombus() override = default;
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

