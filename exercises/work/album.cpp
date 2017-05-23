#include <iostream>
#include "album.h"

using std::cout;

Album::Album() {
  assignString(&genre, "");
}

Album::Album(const char* title, const char* author,
             int year, const char* genre): Work(title, author, year) {
  assignString(&this->genre, genre);
}

Album::Album(const Album& other): Work(other) {
  copy(other);
}

Album::~Album() {
  erase();
}

Album& Album::operator=(const Album& other) {
  Work::operator=(other);

  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Album::print() const {
  Work::print();
  cout << "Genre: " << genre << '\n';
}

void Album::assignString(char** destination, const char* source) {
  *destination = new char[strlen(source) + 1];
  strcpy(*destination, source);
}

void Album::copy(const Album& other) {
  assignString(&genre, other.genre);
}

void Album::erase() {
  delete[] genre;
}
