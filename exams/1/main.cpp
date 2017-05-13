#include "taxi-central.h"

int main() {
  TaxiCentral taxiCentral;

  taxiCentral.addTaxiDriver("Petar Petrov", 600);
  taxiCentral.addTaxiDriver("Ivan Ivanov", 800);
  taxiCentral.addTaxiDriver("Maria Stoyanova", 700);

  taxiCentral.makeOrder("James Baucher 5", "Korab Planina 10");
  taxiCentral.makeOrder("bul. Vitosha 42", "Studentski grad 8", "Maria Stoyanova");

  taxiCentral.cancelOrder("James Baucher 5", "Korab Planina 10");

  taxiCentral.makeOrder("bul. Dragan Tsankov 6", "Studentski grad 8", "Petar Petrov");
  taxiCentral.makeOrder("bul. Dragan Tsankov 6", "Studentski grad 8", "Ivan Ivanov");

  cout << taxiCentral;

  return 0;
}