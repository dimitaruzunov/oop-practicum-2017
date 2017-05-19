#include "surgeon.h"

Surgeon::Surgeon(const string& name, int experience,
                 const string& speciality)
  : Doctor(name, experience), speciality(speciality) {}

double Surgeon::chance(const string& speciality) const {
  if (this->speciality == speciality) {
    return 60 + experience;
  }

  return 40 + experience * (2.0 / 3);
}

ostream& operator<<(ostream& os, const Surgeon& surgeon) {
  return os << (Doctor&) surgeon
            << "Speciality: " << surgeon.speciality << '\n';
}
