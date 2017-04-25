#include <cstring>
#include "collection.h"

void Collection::copy(const Collection& other) {
  gramophoneRecords = new GramophoneRecord[other.capacity];
  for (int i = 0; i < other.size; ++i) {
    gramophoneRecords[i] = other.gramophoneRecords[i];
  }

  size = other.size;
  capacity = other.capacity;
}

void Collection::erase() {
  delete[] gramophoneRecords;
}

void Collection::resize() {
  GramophoneRecord* oldGramophoneRecords = gramophoneRecords;

  gramophoneRecords = new GramophoneRecord[capacity * 2];

  for (int i = 0; i < size; ++i) {
    gramophoneRecords[i] = oldGramophoneRecords[i];
  }

  delete[] oldGramophoneRecords;

  capacity *= 2;
}

Collection::Collection() {
  size = 0;
  capacity = 8;

  gramophoneRecords = new GramophoneRecord[capacity];
}

Collection::Collection(const Collection& other) {
  copy(other);
}

Collection::~Collection() {
  erase();
}

Collection& Collection::operator=(const Collection& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Collection::operator+(const GramophoneRecord& gramophoneRecord) {
  if (size == capacity) {
    resize();
  }

  gramophoneRecords[size] = gramophoneRecord;
  size++;
}

void Collection::printByGenre(const char* genre) const {
  for (int i = 0; i < size; ++i) {
    if (strcmp(gramophoneRecords[i].getGenre(), genre) == 0) {
      gramophoneRecords[i].print();
    }
  }
}

void Collection::findByAlbum(const char* album) const {
  for (int i = 0; i < size; ++i) {
    if (strcmp(gramophoneRecords[i].getAlbum(), album) == 0) {
      gramophoneRecords[i].print();
      return;
    }
  }
}

void Collection::printAllShorterThanTime(int time) const {
  for (int i = 0; i < size; ++i) {
    if (gramophoneRecords[i].getTime() <= time) {
      gramophoneRecords[i].print();
    }
  }
}
