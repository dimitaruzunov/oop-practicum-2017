#ifndef SURGEON_H
#define SURGEON_H

#include "doctor.h"

class Surgeon : public Doctor {
  string speciality;

public:

  Surgeon(const string& name, int experience, const string& speciality);

  double chance(const string& speciality) const;

  friend ostream& operator<<(ostream& os, const Surgeon& surgeon);
};

#endif
