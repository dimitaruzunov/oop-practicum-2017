#ifndef TICKETS_DISCOUNT_TICKET_H
#define TICKETS_DISCOUNT_TICKET_H

#include "ticket.h"

class DiscountTicket : public Ticket {
  double discountPrice;

public:

  DiscountTicket(const char* title, double price);

  void print() const;
  double getPrice() const;
};

#endif
