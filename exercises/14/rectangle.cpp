#include <iostream>
#include "rectangle.h"

using std::cout;

Rectangle::Rectangle(double width, double height)
  : width(width), height(height) {}

double Rectangle::perimeter() const {
  return 2 * (width + height);
}

double Rectangle::area() const {
  return width * height;
}

void Rectangle::print() const {
  cout << "Width: " << width
       << "\nHeight: " << height
       << "\nPerimeter: " << perimeter()
       << "\nArea: " << area() << '\n';
}
