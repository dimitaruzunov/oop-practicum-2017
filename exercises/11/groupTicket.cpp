#include <iostream>
#include "groupTicket.h"

using std::cout;

GroupTicket::GroupTicket(const char* title, double price,
                         double minPrice, int count)
  : Ticket(title, price), count(count) {
  if (count >= 20) {
    discountPrice = price - 2 * count;

    if (discountPrice < minPrice) {
      discountPrice = minPrice;
    }
  } else {
    discountPrice = price;
  }
}

void GroupTicket::print() const {
  Ticket::print();

  cout << "Discount price: " << discountPrice << '\n';
}

double GroupTicket::getPrice() const {
  return discountPrice;
}

int GroupTicket::getCount() const {
  return count;
}
