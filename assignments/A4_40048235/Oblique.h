#ifndef OBLIQUE_H
#define OBLIQUE_H

#include "Isosceles.h"

class Oblique : public Isosceles {
  private:
    int b;
  public:
    Oblique(int, string = "Class Oblique", string = "Oblique");
    virtual ~Oblique() override = default;
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
