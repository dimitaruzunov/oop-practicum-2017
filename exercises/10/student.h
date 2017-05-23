#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
  string speciality;
  int grade;

public:

  Student(const string& name, int age, const string& speciality, int grade);

  void print() const;
};

#endif
