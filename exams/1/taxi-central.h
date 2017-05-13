#ifndef TAXI_CENTRAL_H
#define TAXI_CENTRAL_H

#include "taxi-driver.h"
#include "order.h"

using std::cout;

class TaxiCentral {
  char name[30];

  TaxiDriver* taxiDrivers;
  int numberOfTaxiDrivers;
  int taxiDriversCapacity;

  Order* orders;
  int numberOfOrders;
  int ordersCapacity;

  void copyTaxiDrivers(const TaxiCentral& other);
  void copyOrders(const TaxiCentral& other);
  void copy(const TaxiCentral& other);
  void erase();

  void resizeTaxiDrivers();
  void resizeOrders();

  TaxiDriver* firstFreeDriver() const;
  TaxiDriver* freeDriverByName(const char* name) const;
  void makeOrder(const char* sourceAddress, const char* destinationAddress,
                 TaxiDriver& taxiDriver);
  int getOrderIndex(const char* sourceAddress,
                    const char* destinationAddress) const;
  int getDriverIndex(const char* name) const;
  void removeOrder(int index);

public:

  TaxiCentral();
  TaxiCentral(const TaxiCentral& other);
  ~TaxiCentral();

  TaxiCentral& operator=(const TaxiCentral& other);

  void addTaxiDriver(const char* name, double salary);
  bool makeOrder(const char* sourceAddress, const char* destinationAddress);
  bool makeOrder(const char* sourceAddress, const char* destinationAddress,
                 const char* taxiDriverName);
  void cancelOrder(const char* sourceAddress, const char* destinationAddress);
  ostream& printTaxiDrivers(ostream& os = cout) const;
  ostream& printOrders(ostream& os = cout) const;

  friend ostream& operator<<(ostream& os, const TaxiCentral& taxiCentral);
};

#endif
