#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person {
  double salaryForHour;
  int hours;

public:

  Worker(const string& name, int age, double salaryForHour, int hours);

  void print() const;
  double calculateSalary() const;
};

#endif
