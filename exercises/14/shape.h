#ifndef SHAPES_SHAPE_H
#define SHAPES_SHAPE_H

class Shape {
public:

  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual void print() const = 0;

  virtual ~Shape() {};
};

#endif
