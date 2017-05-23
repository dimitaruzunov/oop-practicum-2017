#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

class Person {
  string name;
  int age;

public:

  Person(const string& name, int age);

  void print() const;
};

#endif
