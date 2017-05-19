#ifndef ALBUM_H
#define ALBUM_H

#include "work.h"

class Album : public Work {
  char* genre;

  void assignString(char** destination, const char* source);
  void copy(const Album& other);
  void erase();

public:

  Album();
  Album(const char* title, const char* author, int year, const char* genre);
  Album(const Album& other);
  ~Album();

  Album& operator=(const Album& other);

  void print() const;
};

#endif
