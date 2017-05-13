#ifndef TAXI_DRIVER_H
#define TAXI_DRIVER_H

#include <iostream>

using std::istream;
using std::ostream;

class TaxiDriver {
  char name[30];
  double salary;
  bool busy;

public:

  TaxiDriver(const char* name = "", double salary = 0);

  const char* getName() const;
  bool isBusy() const;
  void setBusy(bool value);

  friend istream& operator>>(istream& is, TaxiDriver& taxiDriver);
  friend ostream& operator<<(ostream& os, const TaxiDriver& taxiDriver);
};

#endif
