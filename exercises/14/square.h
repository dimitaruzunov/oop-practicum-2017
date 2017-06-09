#ifndef SHAPES_SQUARE_H
#define SHAPES_SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:

  Square(double width);

  void print() const;
};

#endif
