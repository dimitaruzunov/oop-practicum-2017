#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
protected:
  double width;
  double height;

public:

  Rectangle(double width, double height);

  double perimeter() const;
  double area() const;
  void print() const;
};


#endif
