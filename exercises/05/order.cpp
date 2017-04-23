#include <cstring>
#include <algorithm>
#include <iostream>
#include "order.h"

const int Order::INITIAL_CAPACITY = 8;

void Order::setNumber(const char* number) {
  this->number = new char[strlen(number) + 1];
  strcpy(this->number, number);
}

void Order::setItem(int index, const char* item) {
  items[index] = new char[strlen(item) + 1];
  strcpy(items[index], item);
}

void Order::resize() {
  char** oldItems = items;
  items = new char*[capacity * 2];

  for (int i = 0; i < size; ++i) {
    setItem(i, oldItems[i]);
    delete[] oldItems[i];
  }
  delete[] oldItems;

  capacity *= 2;
}

void Order::copy(const Order& other) {
  setNumber(other.number);

  size = other.size;
  capacity = other.capacity;
  items = new char*[capacity];
  for(int i = 0; i < size; ++i) {
    setItem(i, other.items[i]);
  }
}

void Order::erase() {
  delete[] number;

  for (int i = 0; i < size; ++i) {
    delete[] items[i];
  }
  delete[] items;
}

Order::Order() {
  setNumber("");

  size = 0;
  capacity = INITIAL_CAPACITY;
  items = new char*[capacity];
}

Order::Order(const char* number) {
  setNumber(number);

  size = 0;
  capacity = INITIAL_CAPACITY;
  items = new char*[capacity];
}

Order::Order(const char* number, const char* items[], int itemsCount) {
  setNumber(number);

  size = itemsCount;
  capacity = std::max(itemsCount, INITIAL_CAPACITY);
  this->items = new char*[capacity];
  for (int i = 0; i < size; ++i) {
    setItem(i, items[i]);
  }
}

Order::Order(const Order& other) {
  copy(other);
}

Order::~Order() {
  erase();
}

Order& Order::operator=(const Order& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Order::addItem(const char* item) {
  if (size == capacity) {
    resize();
  }

  setItem(size, item);
  ++size;
}

void Order::cancel() {
  for (int i = 0; i < size; ++i) {
    delete[] items[i];
  }

  size = 0;
}

void Order::print() const {
  std::cout << "Number: " << number << '\n';

  if (size > 0) {
    std::cout << "Items: ";
    for (int i = 0; i < size - 1; ++i) {
      std::cout << items[i] << ", ";
    }
    std::cout << items[size - 1] << '\n';
  }
}
