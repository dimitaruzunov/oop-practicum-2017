#include <iostream>
#include "ticket.h"
#include "discountTicket.h"
#include "groupTicket.h"

using std::cout;

void printInfo(Ticket* tickets[], int ticketsCount) {
  double sum = 0;
  double count = 0;

  for (int i = 0; i < ticketsCount; ++i) {
    sum += tickets[i]->getPrice();
    count +=  tickets[i]->getCount();
  }

  cout << "Sum: " << sum << '\n' << "Count: " << count << '\n';
}

int main() {
  Ticket gosho("Gosho", 30);
  DiscountTicket pesho("Pesho", 20);
  GroupTicket maria("Maria", 100, 5, 20);

  Ticket* tickets[] = {
    &gosho,
    &pesho,
    &maria
  };

  printInfo(tickets, 3);

  return 0;
}