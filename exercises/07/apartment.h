#ifndef APARTMENT_H
#define APARTMENT_H

#include "room.h"

class Apartment {
  Room* rooms;
  int roomsCount;

  void copy(const Apartment& other);

  void erase();

public:

  Apartment();

  Apartment(Room rooms[], int roomsCount);

  Apartment(const Apartment& other);

  ~Apartment();

  Apartment& operator=(const Apartment& other);

  double getArea() const;

  double getAverageRoomArea() const;

  const Room& operator[](const char* description) const;

  bool operator<(const Apartment& other) const;

  bool operator<=(const Apartment& other) const;

  bool operator==(const Apartment& other) const;

  bool operator>=(const Apartment& other) const;

  bool operator>(const Apartment& other) const;

  friend istream& operator>>(istream& is, Apartment& apartment);

  friend ostream& operator<<(ostream& os, const Apartment& apartment);
};

#endif
