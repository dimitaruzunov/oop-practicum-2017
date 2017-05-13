#include <cstring>
#include "taxi-driver.h"

using std::boolalpha;

TaxiDriver::TaxiDriver(const char* name, double salary) {
  strcpy(this->name, name);
  this->salary = salary;
  busy = false;
}

const char* TaxiDriver::getName() const {
  return name;
}

bool TaxiDriver::isBusy() const {
  return busy;
}

void TaxiDriver::setBusy(bool value) {
  busy = value;
}

istream& operator>>(istream& is, TaxiDriver& taxiDriver) {
  return (is.getline(taxiDriver.name, 30) >> taxiDriver.salary).ignore();
}

ostream& operator<<(ostream& os, const TaxiDriver& taxiDriver) {
  return os << "Name: " << taxiDriver.name
            << "\nSalary: " << taxiDriver.salary
            << "\nBusy: " << boolalpha << taxiDriver.busy << '\n';
}
