#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "shape.h"

class Circle : public Shape {
  double radius;

public:

  Circle(double radius);

  double perimeter() const;
  double area() const;
  void print() const;
};

#endif
