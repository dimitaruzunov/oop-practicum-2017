#ifndef SET_H
#define SET_H

#include <iostream>

class Set {
  int* elements;
  int size;
  int capacity;

  bool includes(int element) const;
  void push(int element);
  void remove(int index);
  void resize();

  void copy(const Set& other);
  void erase();

public:

  Set();
  Set(int element);
  Set(const Set& other);
  ~Set();

  Set& operator=(const Set& other);

  bool operator==(const Set& other);

  Set& operator+=(const Set& other);
  Set operator+(const Set& other);

  Set& operator^=(const Set& other);
  Set operator^(const Set& other);

  Set& operator-=(const Set& other);
  Set operator-(const Set& other);

  friend std::ostream& operator<<(std::ostream& os, const Set& set);
};

#endif