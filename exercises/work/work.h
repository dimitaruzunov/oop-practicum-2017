#ifndef WORK_H
#define WORK_H

class Work {
  char* title;
  char* author;
  int year;

  void assignString(char** destination, const char* source);
  void copy(const Work& other);
  void erase();

public:

  Work();
  Work(const char* title, const char* author, int year);
  Work(const Work& other);
  virtual ~Work();

  Work& operator=(const Work& other);

  int getYear() const;
  virtual void print() const;
};

#endif
