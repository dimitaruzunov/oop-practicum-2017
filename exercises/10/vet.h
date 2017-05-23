#ifndef VET_H
#define VET_H

#include "doctor.h"

class Vet : public Doctor {
  string animal;

public:

  Vet(const string& name, int experience, const string& animal);

  double chance(const string& animal) const;

  friend ostream& operator<<(ostream& os, const Vet& vet);
};

#endif
