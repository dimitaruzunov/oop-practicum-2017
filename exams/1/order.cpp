#include <cstring>
#include "order.h"

Order::Order(const char* sourceAddress, const char* destinationAddress,
             const TaxiDriver& taxiDriver) {
  strcpy(this->sourceAddress, sourceAddress);
  strcpy(this->destinationAddress, destinationAddress);
  this->taxiDriver = taxiDriver;
}

const char* Order::getSourceAddress() const {
  return sourceAddress;
}

const char* Order::getDestinationAddress() const {
  return destinationAddress;
}

TaxiDriver& Order::getTaxiDriver() {
  return taxiDriver;
}

istream& operator>>(istream& is, Order& order) {
  return is
    .getline(order.sourceAddress, 60)
    .getline(order.destinationAddress, 60)
    >> order.taxiDriver;
}

ostream& operator<<(ostream& os, const Order& order) {
  return os << "Source address: " << order.sourceAddress
            << "\nDestination address: " << order.destinationAddress
            << '\n' << order.taxiDriver;
}
