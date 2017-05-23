#ifndef TICKETS_GROUP_TICKET_H
#define TICKETS_GROUP_TICKET_H

#include "ticket.h"

class GroupTicket : public Ticket {
  int count;
  double discountPrice;

public:

  GroupTicket(const char* title, double price, double minPrice, int count);

  void print() const;
  double getPrice() const;
  int getCount() const;
};

#endif
