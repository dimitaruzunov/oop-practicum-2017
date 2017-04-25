#include <cstring>
#include <iostream>
#include "gramophone-record.h"

using std::cout;

void GramophoneRecord::copy(const GramophoneRecord& other) {
  year = other.year;
  time = other.time;

  genre = new char[strlen(other.genre) + 1];
  strcpy(genre, other.genre);

  artist = new char[strlen(other.artist) + 1];
  strcpy(artist, other.artist);

  album = new char[strlen(other.album) + 1];
  strcpy(album, other.album);
}

void GramophoneRecord::erase() {
  delete[] genre;
  delete[] artist;
  delete[] album;
}

GramophoneRecord::GramophoneRecord() {
  year = 0;
  time = 0;

  genre = new char[1];
  genre[0] = '\0';

  artist = new char[1];
  artist[0] = '\0';

  album = new char[1];
  album[0] = '\0';
}

GramophoneRecord::GramophoneRecord(int year, const char* genre,
                                   const char* artist, const char* album,
                                   int time) {
  this->year = year;
  this->time = time;

  this->genre = new char[strlen(genre) + 1];
  strcpy(this->genre, genre);

  this->artist = new char[strlen(artist) + 1];
  strcpy(this->artist, artist);

  this->album = new char[strlen(album) + 1];
  strcpy(this->album, album);
}

GramophoneRecord::GramophoneRecord(const GramophoneRecord& other) {
  copy(other);
}

GramophoneRecord::~GramophoneRecord() {
  erase();
}

GramophoneRecord& GramophoneRecord::operator=(const GramophoneRecord& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

const char* GramophoneRecord::getGenre() const {
  return genre;
}

const char* GramophoneRecord::getAlbum() const {
  return album;
}

int GramophoneRecord::getTime() const {
  return time;
}

void GramophoneRecord::print() const {
  cout << album << " by " << artist << ", "
       << genre << ", " << year << ", " << time << " minutes\n";
}
