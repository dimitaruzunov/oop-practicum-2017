#include "doctor.h"

Doctor::Doctor(const string& name, int experience)
  : name(name), experience(experience) {}

ostream& operator<<(ostream& os, const Doctor& doctor) {
  return os << "Name: " << doctor.name
            << "\nExperience: " << doctor.experience << '\n';
}
