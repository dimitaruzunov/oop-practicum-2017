#include <math.h>
#include <iostream>
#include "circle.h"

using std::cout;

Circle::Circle(double radius): radius(radius) {}

double Circle::perimeter() const {
  return 2 * M_PI * radius;
}

double Circle::area() const {
  return M_PI * radius * radius;
}

void Circle::print() const {
  cout << "Radius: " << radius
       << "\nPerimeter: " << perimeter()
       << "\nArea: " << area() << '\n';
}
