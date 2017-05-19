#include <iostream>
#include "painting.h"

using std::cout;

Painting::Painting(const char* title, const char* author,
                   int year, double width, double height)
  : Work(title, author, year), width(width), height(height) {}

void Painting::print() const {
  Work::print();
  cout << "Width: " << width << "\nHeight: " << height << '\n';
}
