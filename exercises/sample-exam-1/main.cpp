#include <iostream>
#include "collection.h"

int main() {
  GramophoneRecord gramophoneRecords[] = {
    GramophoneRecord(2010, "Rock", "Slash", "Slash", 80),
    GramophoneRecord(2012, "Rock", "Slash", "Apocalyptic Love", 73),
    GramophoneRecord(2014, "Rock", "Slash", "World On Fire", 90),
    GramophoneRecord(1987, "Rock", "Guns N' Roses", "Appetite For Destruction", 87),
    GramophoneRecord(1991, "Rock", "Guns N' Roses", "Use Your Illusion I", 120),
    GramophoneRecord(1991, "Rock", "Guns N' Roses", "Use Your Illusion II", 120),
    GramophoneRecord(1991, "Grunge", "Pearl Jam", "Ten", 103)
  };

  Collection collection;

  for (int i = 0; i < 7; ++i) {
    collection + gramophoneRecords[i];
  }

  collection.printByGenre("Rock");
  std::cout << '\n';
  collection.printByGenre("Grunge");
  std::cout << '\n';
  collection.findByAlbum("Appetite For Destruction");
  std::cout << '\n';
  collection.printAllShorterThanTime(90);

  return 0;
}