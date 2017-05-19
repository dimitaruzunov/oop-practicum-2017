#ifndef MUSEUM_H
#define MUSEUM_H

#include "work.h"

class Museum {
  Work** works;
  int worksCount;

  void assignWorks(Work** works, int worksCount);
  void copy(const Museum& other);
  void erase();

public:

  Museum();
  Museum(Work** works, int worksCount);
  Museum(const Museum& other);
  ~Museum();

  Museum& operator=(const Museum& other);

  void print() const;
  void printByYear(int year) const;
};

#endif
