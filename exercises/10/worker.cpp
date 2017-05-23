#include <iostream>
#include "worker.h"

using std::cout;

Worker::Worker(const string& name, int age, double salaryForHour, int hours)
  : Person(name, age), salaryForHour(salaryForHour), hours(hours) {}

void Worker::print() const {
  Person::print();
  cout << "Salary: " << calculateSalary() << '\n';
}

double Worker::calculateSalary() const {
  return salaryForHour * hours;
}
