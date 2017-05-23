#include <iostream>
#include "student.h"

using std::cout;

Student::Student(const string& name, int age,
                 const string& speciality, int grade)
  : Person(name, age), speciality(speciality), grade(grade) {}

void Student::print() const {
  Person::print();
  cout << "Speciality: " << speciality << "\nGrade: " << grade << '\n';
}
