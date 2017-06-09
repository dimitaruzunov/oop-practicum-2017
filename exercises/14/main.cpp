#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"

int main() {
  Rectangle rectangle(4, 2);
  Square square(4);
  Circle circle(6);

  Shape* shapes[] = {&rectangle, &square, &circle};

  Shape* rectangle1 = new Rectangle(4, 2);
  delete rectangle1;

  for (int i = 0; i < 3; ++i) {
    shapes[i]->print();
    std::cout << '\n';
  }

  return 0;
}