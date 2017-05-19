#include <iostream>
#include "person.h"

using std::cout;

Person::Person(const string& name, int age): name(name), age(age) {}

void Person::print() const {
  cout << "Name: " << name << "\nAge: " << age << '\n';
}
