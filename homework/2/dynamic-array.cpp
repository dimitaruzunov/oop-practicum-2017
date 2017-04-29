#include <algorithm>
#include <iostream>
#include "dynamic-array.h"

using std::max;
using std::cout;

const int DynamicArray::INITIAL_CAPACITY = 8;

DynamicArray::DynamicArray() {
  elements = new int[INITIAL_CAPACITY];
  size = 0;
  capacity = INITIAL_CAPACITY;
}

DynamicArray::DynamicArray(int elements[], int elementsCount) {
  int initialCapacity = max(size, INITIAL_CAPACITY);
  this->elements = new int[initialCapacity];

  for (int i = 0; i < elementsCount; ++i) {
    this->elements[i] = elements[i];
  }

  size = elementsCount;
  capacity = initialCapacity;
}

DynamicArray::DynamicArray(int capacity) {
  elements = new int[capacity];
  size = 0;
  this->capacity = capacity;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
  copy(other);
}

DynamicArray::~DynamicArray() {
  erase();
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

int DynamicArray::getSize() const {
  return size;
}

bool DynamicArray::isEmpty() const {
  return size == 0;
}

int DynamicArray::get(int index) const {
  return elements[index];
}

int DynamicArray::operator[](int index) const {
  return get(index);
}

bool DynamicArray::includes(int element) const {
  for (int i = 0; i < size; ++i) {
    if (elements[i] == element) {
      return true;
    }
  }

  return false;
}

void DynamicArray::set(int index, int newValue) {
  elements[index] = newValue;
}

void DynamicArray::push(int element) {
  insertAt(size, element);
}

int DynamicArray::pop() {
  return removeAt(size - 1);
}

void DynamicArray::insertAt(int index, int element) {
  if (size == capacity) {
    resize();
  }

  for (int i = size; i > index; --i) {
    elements[i] = elements[i - 1];
  }

  elements[index] = element;
  ++size;
}

int DynamicArray::removeAt(int index) {
  int removedElement = elements[index];

  for (int i = index; i < size - 1; ++i) {
    elements[i] = elements[i + 1];
  }

  --size;

  return removedElement;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& other) {
  for (int i = 0; i < other.size; ++i) {
    push(other[i]);
  }

  return *this;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) {
  DynamicArray result = *this;
  return result += other;
}

DynamicArray& DynamicArray::operator-=(const DynamicArray& other) {
  return *this = *this - other;
}

DynamicArray DynamicArray::operator-(const DynamicArray& other) {
  DynamicArray result;

  for (int i = 0; i < size; ++i) {
    if (!other.includes(elements[i])) {
      result.push(elements[i]);
    }
  }

  return result;
}

void DynamicArray::print() const {
  cout << '[';

  if (!isEmpty()) {
    for (int i = 0; i < size - 1; ++i) {
      cout << elements[i] << ", ";
    }
    cout << elements[size - 1];
  }

  cout << "]\n";
}

void DynamicArray::copy(const DynamicArray& other) {
  elements = new int[other.capacity];

  for (int i = 0; i < other.size; ++i) {
    elements[i] = other.elements[i];
  }

  size = other.size;
  capacity = other.capacity;
}

void DynamicArray::erase() {
  delete[] elements;
}

void DynamicArray::resize() {
  int* oldElements = elements;
  elements = new int[capacity * 2];

  for (int i = 0; i < size; ++i) {
    elements[i] = oldElements[i];
  }
  delete[] oldElements;

  capacity *= 2;
}
