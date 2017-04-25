#ifndef GRAMOPHONE_RECORD_H
#define GRAMOPHONE_RECORD_H

class GramophoneRecord {
  int year;
  char* genre;
  char* artist;
  char* album;
  int time;

  void copy(const GramophoneRecord& other);
  void erase();

public:

  GramophoneRecord();
  GramophoneRecord(int year, const char* genre, const char* artist, const char* album, int time);
  GramophoneRecord(const GramophoneRecord& other);
  ~GramophoneRecord();

  GramophoneRecord& operator=(const GramophoneRecord& other);

  const char* getGenre() const;
  const char* getAlbum() const;
  int getTime() const;

  void print() const;
};

#endif
