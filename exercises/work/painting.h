#ifndef PAINTING_H
#define PAINTING_H

#include "work.h"

class Painting : public Work {
  double width;
  double height;

public:

  Painting(const char* title, const char* author,
           int year, double width, double height);

  void print() const;
};

#endif
