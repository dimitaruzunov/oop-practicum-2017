#include <cstring>
#include <iostream>
#include "work.h"

using std::cout;

Work::Work() {
  assignString(&title, "");
  assignString(&author, "");
  year = 0;
}

Work::Work(const char* title, const char* author, int year) {
  assignString(&this->title, title);
  assignString(&this->author, author);
  this->year = year;
}

Work::Work(const Work& other) {
  copy(other);
}

Work::~Work() {
  erase();
}

Work& Work::operator=(const Work& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

int Work::getYear() const {
  return year;
}

void Work::print() const {
  cout << "Title: " << title << "\nAuthor: "
       << author << "\nYear: " << year << '\n';
}

void Work::assignString(char** destination, const char* source) {
  *destination = new char[strlen(source) + 1];
  strcpy(*destination, source);
}

void Work::copy(const Work& other) {
  assignString(&title, other.title);
  assignString(&author, other.author);
  year = other.year;
}

void Work::erase() {
  delete[] title;
  delete[] author;
}
