#ifndef ORDER_H
#define ORDER_H

#include "taxi-driver.h"

class Order {
  char sourceAddress[60];
  char destinationAddress[60];
  TaxiDriver taxiDriver;

public:

  Order(const char* sourceAddress = "", const char* destinationAddress = "",
        const TaxiDriver& taxiDriver = TaxiDriver());

  const char* getSourceAddress() const;
  const char* getDestinationAddress() const;
  TaxiDriver& getTaxiDriver();

  friend istream& operator>>(istream& is, Order& order);
  friend ostream& operator<<(ostream& os, const Order& order);
};

#endif
