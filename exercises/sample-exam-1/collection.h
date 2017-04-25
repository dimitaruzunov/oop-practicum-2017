#ifndef COLLECTION_H
#define COLLECTION_H

#include "gramophone-record.h"

class Collection {
  GramophoneRecord* gramophoneRecords;
  int size;
  int capacity;

  void copy(const Collection& other);
  void erase();
  void resize();

public:

  Collection();
  Collection(const Collection& other);
  ~Collection();

  Collection& operator=(const Collection& other);

  void operator+(const GramophoneRecord& gramophoneRecord);

  void printByGenre(const char* genre) const;

  void findByAlbum(const char* album) const;

  void printAllShorterThanTime(int time) const;
};

#endif
