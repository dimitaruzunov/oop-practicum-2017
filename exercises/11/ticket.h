#ifndef TICKETS_TICKET_H
#define TICKETS_TICKET_H

class Ticket {
  char* title;
  double price;

  void copy(const Ticket& other);
  void erase();

public:

  Ticket();
  Ticket(const char* title, double price);
  Ticket(const Ticket& other);
  ~Ticket();

  Ticket& operator=(const Ticket& other);

  virtual void print() const;
  virtual double getPrice() const;
  virtual int getCount() const;
};

#endif
