#ifndef ROOM_H
#define ROOM_H

#include <iostream>

using std::istream;
using std::ostream;

class Room {
  char description[30];
  double area;

public:

  Room();

  Room(const char* description, double area);

  const char* getDescription() const;

  double getArea() const;

  friend istream& operator>>(istream& is, Room& room);

  friend ostream& operator<<(ostream& os, const Room& room);
};

#endif
