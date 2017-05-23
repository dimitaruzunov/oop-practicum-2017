#include <iostream>
#include <cstring>
#include "ticket.h"

using std::cout;

Ticket::Ticket() {
  title = nullptr;
  price = 0;
}

Ticket::Ticket(const char* title, double price) {
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);

  this->price = price;
}

Ticket::Ticket(const Ticket& other) {
  copy(other);
}

Ticket::~Ticket() {
  erase();
}

Ticket& Ticket::operator=(const Ticket& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Ticket::print() const {
  cout << "Title: " << title << "\nPrice: " << price << '\n';
}

double Ticket::getPrice() const {
  return price;
}

int Ticket::getCount() const {
  return 1;
}

void Ticket::copy(const Ticket& other) {
  title = new char[strlen(other.title) + 1];
  strcpy(title, other.title);

  price = other.price;
}

void Ticket::erase() {
  delete[] title;
}
