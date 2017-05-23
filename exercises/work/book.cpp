#include <iostream>
#include "book.h"

using std::cout;

Book::Book() {
  assignString(&genre, "");
}

Book::Book(const char* title, const char* author,
           int year, const char* genre): Work(title, author, year) {
  assignString(&this->genre, genre);
}

Book::Book(const Book& other): Work(other) {
  copy(other);
}

Book::~Book() {
  erase();
}

Book& Book::operator=(const Book& other) {
  Work::operator=(other);

  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Book::print() const {
  Work::print();
  cout << "Genre: " << genre << '\n';
}

void Book::assignString(char** destination, const char* source) {
  *destination = new char[strlen(source) + 1];
  strcpy(*destination, source);
}

void Book::copy(const Book& other) {
  assignString(&genre, other.genre);
}

void Book::erase() {
  delete[] genre;
}
