#ifndef BOOK_H
#define BOOK_H

#include "work.h"

class Book : public Work {
  char* genre;

  void assignString(char** destination, const char* source);
  void copy(const Book& other);
  void erase();

public:

  Book();
  Book(const char* title, const char* author, int year, const char* genre);
  Book(const Book& other);
  ~Book();

  Book& operator=(const Book& other);

  void print() const;
};

#endif
