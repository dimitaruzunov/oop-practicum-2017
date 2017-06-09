#include <iostream>
#include "square.h"

using std::cout;

Square::Square(double width): Rectangle(width, width) {}

void Square::print() const {
  cout << "Width: " << width
       << "\nPerimeter: " << perimeter()
       << "\nArea: " << area() << '\n';
}
