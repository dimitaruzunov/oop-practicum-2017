#include "set.h"

bool Set::includes(int element) const {
  for (int i = 0; i < size; ++i) {
    if (elements[i] == element) {
      return true;
    }
  }

  return false;
}

void Set::push(int element) {
  if (includes(element)) {
    return;
  }

  if (size == capacity) {
    resize();
  }

  elements[size] = element;
  ++size;
}

void Set::remove(int index) {
  for (int i = index; i < size - 1; ++i) {
    elements[i] = elements[i + 1];
  }
  --size;
}

void Set::resize() {
  int* oldElements = elements;
  elements = new int[capacity * 2];

  for (int i = 0; i < size; ++i) {
    elements[i] = oldElements[i];
  }
  delete[] oldElements;

  capacity *= 2;
}

void Set::copy(const Set& other) {
  elements = new int[other.capacity];

  for (int i = 0; i < other.size; ++i) {
    elements[i] = other.elements[i];
  }

  size = other.size;
  capacity = other.capacity;
}

void Set::erase() {
  delete[] elements;
}

Set::Set(): size(0), capacity(8), elements(new int[capacity]) {}

Set::Set(const Set& other) {
  copy(other);
}

Set::Set(int element): size(0), capacity(8), elements(new int[capacity]) {
  push(element);
}

Set::~Set() {
  erase();
}

Set& Set::operator=(const Set& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

bool Set::operator==(const Set& other) {
  for (int i = 0; i < size; ++i) {
    if (!other.includes(elements[i])) {
      return false;
    }
  }

  for (int i = 0; i < other.size; ++i) {
    if (!includes(other.elements[i])) {
      return false;
    }
  }

  return true;
}

Set& Set::operator+=(const Set& other) {
  for (int i = 0; i < other.size; ++i) {
    push(other.elements[i]);
  }

  return *this;
}

Set Set::operator+(const Set& other) {
  Set result = *this;
  return result += other;
}

Set& Set::operator^=(const Set& other) {
  return *this = *this ^ other;
}

Set Set::operator^(const Set& other) {
  Set result;

  for (int i = 0; i < size; ++i) {
    if (other.includes(elements[i])) {
      result.push(elements[i]);
    }
  }

  return result;
}

Set& Set::operator-=(const Set& other) {
  return *this = *this - other;
}

Set Set::operator-(const Set& other) {
  Set result;

  for (int i = 0; i < size; ++i) {
    if (!other.includes(elements[i])) {
      result.push(elements[i]);
    }
  }

  return result;
}

std::ostream& operator<<(std::ostream& os, const Set& set) {
  os << "{";

  if (set.size > 0) {
    for (int i = 0; i < set.size - 1; ++i) {
      os << set.elements[i] << ", ";
    }
    os << set.elements[set.size - 1];
  }

  return os << "}\n";
}
