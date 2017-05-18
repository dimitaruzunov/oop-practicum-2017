#include <iostream>
#include "discountTicket.h"

using std::cout;

DiscountTicket::DiscountTicket(const char* title, double price)
  : Ticket(title, price), discountPrice(price / 2) {}

void DiscountTicket::print() const {
  Ticket::print();

  cout << "Discount price: " << discountPrice << '\n';
}

double DiscountTicket::getPrice() const {
  return discountPrice;
}
