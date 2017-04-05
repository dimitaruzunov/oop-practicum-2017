#include "apartment.h"

Apartment::Apartment(): rooms(nullptr), roomsCount(0) {}

Apartment::Apartment(Room rooms[], int roomsCount) {
  this->rooms = new Room[roomsCount];
  this->roomsCount = roomsCount;

  for (int i = 0; i < roomsCount; ++i) {
    this->rooms[i] = rooms[i];
  }
}

Apartment::Apartment(const Apartment& other) {
  copy(other);
}

Apartment::~Apartment() {
  erase();
}

Apartment& Apartment::operator=(const Apartment& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Apartment::copy(const Apartment& other) {
  this->rooms = new Room[other.roomsCount];
  this->roomsCount = other.roomsCount;

  for (int i = 0; i < other.roomsCount; ++i) {
    this->rooms[i] = other.rooms[i];
  }
}

void Apartment::erase() {
  delete[] rooms;
}

double Apartment::getArea() const {
  double area = 0;

  for (int i = 0; i < roomsCount; ++i) {
    area += rooms[i].getArea();
  }

  return area;
}

double Apartment::getAverageRoomArea() const {
  return getArea() / roomsCount;
}

const Room& Apartment::operator[](const char* description) const {
  for (int i = 0; i < roomsCount; ++i) {
    if (strcmp(rooms[i].getDescription(), description) == 0) {
      return rooms[i];
    }
  }

  return Room();
}

bool Apartment::operator<(const Apartment& other) const {
  return getAverageRoomArea() < other.getAverageRoomArea();
}

bool Apartment::operator>(const Apartment& other) const {
  return other < *this;
}

bool Apartment::operator>=(const Apartment& other) const {
  return !(*this < other);
}

bool Apartment::operator<=(const Apartment& other) const {
  return !(*this > other);
}

bool Apartment::operator==(const Apartment& other) const {
  return *this >= other && *this <= other;
}

istream& operator>>(istream& is, Apartment& apartment) {
  apartment.erase();

  (is >> apartment.roomsCount).ignore();

  apartment.rooms = new Room[apartment.roomsCount];

  for (int i = 0; i < apartment.roomsCount; ++i) {
    is >> apartment.rooms[i];
  }

  return is;
}

ostream& operator<<(ostream& os, const Apartment& apartment) {
  os << "Apartment:\n";

  for (int i = 0; i < apartment.roomsCount; ++i) {
    os << apartment.rooms[i] << '\n';
  }

  return os << "Area: " << apartment.getArea() << '\n';
}
