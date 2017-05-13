#include <cstring>
#include "taxi-central.h"

TaxiCentral::TaxiCentral() {
  strcpy(name, "");

  const int INITIAL_CAPACITY = 8;

  taxiDrivers = new TaxiDriver[INITIAL_CAPACITY];
  numberOfTaxiDrivers = 0;
  taxiDriversCapacity = INITIAL_CAPACITY;

  orders = new Order[INITIAL_CAPACITY];
  numberOfOrders = 0;
  ordersCapacity = INITIAL_CAPACITY;
}

TaxiCentral::TaxiCentral(const TaxiCentral& other) {
  copy(other);
}

TaxiCentral::~TaxiCentral() {
  erase();
}

TaxiCentral& TaxiCentral::operator=(const TaxiCentral& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void TaxiCentral::copyTaxiDrivers(const TaxiCentral& other) {
  taxiDrivers = new TaxiDriver[other.taxiDriversCapacity];

  for (int i = 0; i < other.numberOfTaxiDrivers; ++i) {
    taxiDrivers[i] = other.taxiDrivers[i];
  }

  numberOfTaxiDrivers = other.numberOfTaxiDrivers;
  taxiDriversCapacity = other.taxiDriversCapacity;
}

void TaxiCentral::copyOrders(const TaxiCentral& other) {
  orders = new Order[other.ordersCapacity];

  for (int i = 0; i < other.numberOfOrders; ++i) {
    orders[i] = other.orders[i];
  }

  numberOfOrders = other.numberOfOrders;
  ordersCapacity = other.ordersCapacity;
}

void TaxiCentral::copy(const TaxiCentral& other) {
  strcpy(name, other.name);

  copyTaxiDrivers(other);
  copyOrders(other);
}

void TaxiCentral::erase() {
  delete[] taxiDrivers;
  delete[] orders;
}

void TaxiCentral::resizeTaxiDrivers() {
  TaxiDriver* oldTaxiDrivers = taxiDrivers;

  taxiDrivers = new TaxiDriver[taxiDriversCapacity * 2];
  for (int i = 0; i < numberOfTaxiDrivers; ++i) {
    taxiDrivers[i] = oldTaxiDrivers[i];
  }
  taxiDriversCapacity *= 2;

  delete[] oldTaxiDrivers;
}

void TaxiCentral::resizeOrders() {
  Order* oldOrders = orders;

  orders = new Order[ordersCapacity * 2];
  for (int i = 0; i < numberOfOrders; ++i) {
    orders[i] = oldOrders[i];
  }
  ordersCapacity *= 2;

  delete[] oldOrders;
}

void TaxiCentral::addTaxiDriver(const char* name, double salary) {
  if (numberOfTaxiDrivers == taxiDriversCapacity) {
    resizeTaxiDrivers();
  }

  taxiDrivers[numberOfTaxiDrivers] = TaxiDriver(name, salary);
  ++numberOfTaxiDrivers;
}

TaxiDriver* TaxiCentral::firstFreeDriver() const {
  for (int i = 0; i < numberOfTaxiDrivers; ++i) {
    if (!taxiDrivers[i].isBusy()) {
      return &taxiDrivers[i];
    }
  }

  return nullptr;
}

TaxiDriver* TaxiCentral::freeDriverByName(const char* name) const {
  for (int i = 0; i < numberOfTaxiDrivers; ++i) {
    if (strcmp(taxiDrivers[i].getName(), name) == 0
        && !taxiDrivers[i].isBusy()) {
      return &taxiDrivers[i];
    }
  }

  return nullptr;
}

void TaxiCentral::makeOrder(const char* sourceAddress,
                            const char* destinationAddress,
                            TaxiDriver& taxiDriver) {
  if (numberOfOrders == ordersCapacity) {
    resizeOrders();
  }

  taxiDriver.setBusy(true);
  orders[numberOfOrders] = Order(sourceAddress, destinationAddress, taxiDriver);
  ++numberOfOrders;
}

bool TaxiCentral::makeOrder(const char* sourceAddress,
                            const char* destinationAddress) {
  TaxiDriver* taxiDriver = firstFreeDriver();
  if (!taxiDriver) {
    return false;
  }

  makeOrder(sourceAddress, destinationAddress, *taxiDriver);

  return true;
}

bool TaxiCentral::makeOrder(const char* sourceAddress,
                            const char* destinationAddress,
                            const char* taxiDriverName) {
  TaxiDriver* taxiDriver = freeDriverByName(taxiDriverName);
  if (!taxiDriver) {
    return makeOrder(sourceAddress, destinationAddress);
  }

  makeOrder(sourceAddress, destinationAddress, *taxiDriver);

  return true;
}

int TaxiCentral::getOrderIndex(const char* sourceAddress,
                               const char* destinationAddress) const {
  for (int i = 0; i < numberOfOrders; ++i) {
    if (strcmp(orders[i].getSourceAddress(), sourceAddress) == 0
        && strcmp(orders[i].getDestinationAddress(), destinationAddress) == 0) {
      return i;
    }
  }

  return -1;
}

int TaxiCentral::getDriverIndex(const char* name) const {
  for (int i = 0; i < numberOfTaxiDrivers; ++i) {
    if (strcmp(taxiDrivers[i].getName(), name) == 0) {
      return i;
    }
  }

  return -1;
}

void TaxiCentral::removeOrder(int index) {
  for (int i = index; i < numberOfOrders - 1; ++i) {
    orders[i] = orders[i + 1];
  }
  --numberOfOrders;
}

void TaxiCentral::cancelOrder(const char* sourceAddress,
                              const char* destinationAddress) {
  int index = getOrderIndex(sourceAddress, destinationAddress);
  if (index != -1) {
    int driverIndex = getDriverIndex(orders[index].getTaxiDriver().getName());
    taxiDrivers[driverIndex].setBusy(false);

    removeOrder(index);
  }
}

ostream& TaxiCentral::printTaxiDrivers(ostream& os) const {
  os << "Taxi drivers:\n";
  for (int i = 0; i < numberOfTaxiDrivers; ++i) {
    os << taxiDrivers[i] << '\n';
  }
  return os;
}

ostream& TaxiCentral::printOrders(ostream& os) const {
  os << "Orders:\n";
  for (int i = 0; i < numberOfOrders; ++i) {
    os << orders[i] << '\n';
  }
  return os;
}

ostream& operator<<(ostream& os, const TaxiCentral& taxiCentral) {
  taxiCentral.printTaxiDrivers(os);
  return taxiCentral.printOrders(os);
}
