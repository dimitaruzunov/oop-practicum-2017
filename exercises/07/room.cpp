#include "room.h"

Room::Room(): description(""), area(0) {}

Room::Room(const char* description, double area) {
  strcpy(this->description, description);
  this->area = area;
}

const char* Room::getDescription() const {
  return description;
}

double Room::getArea() const {
  return area;
}

istream& operator>>(istream& is, Room& room) {
  is.getline(room.description, 30);
  return (is >> room.area).ignore();
}

ostream& operator<<(ostream& os, const Room& room) {
  return os << "Room: " << room.description << ", " << room.area;
}
