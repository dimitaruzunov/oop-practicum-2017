#include "vet.h"

Vet::Vet(const string& name, int experience, const string& animal)
  : Doctor(name, experience), animal(animal) {}

double Vet::chance(const string& animal) const {
  if (this->animal == animal) {
    return 50 + experience * (4.0 / 5);
  }

  return 45 + experience * (3.0 / 4);
}

ostream& operator<<(ostream& os, const Vet& vet) {
  return os << (Doctor&) vet
            << "Speciality: " << vet.animal << '\n';
}
