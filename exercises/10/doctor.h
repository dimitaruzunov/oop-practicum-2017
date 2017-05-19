#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Doctor {
  string name;

protected:
  int experience;

public:

  Doctor(const string& name, int experience);

  friend ostream& operator<<(ostream& os, const Doctor& doctor);
};

#endif
