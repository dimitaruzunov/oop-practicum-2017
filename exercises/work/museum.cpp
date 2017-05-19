#include "museum.h"

Museum::Museum(): works(nullptr), worksCount(0) {}

Museum::Museum(Work** works, int worksCount) {
  assignWorks(works, worksCount);
}

Museum::Museum(const Museum& other) {
  copy(other);
}

Museum::~Museum() {
  erase();
}

Museum& Museum::operator=(const Museum& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

void Museum::print() const {
  for (int i = 0; i < worksCount; ++i) {
    works[i]->print();
  }
}

void Museum::printByYear(int year) const {
  for (int i = 0; i < worksCount; ++i) {
    if (works[i]->getYear() == year) {
      works[i]->print();
    }
  }
}

void Museum::assignWorks(Work** works, int worksCount) {
  this->works = new Work*[worksCount];
  for (int i = 0; i < worksCount; ++i) {
    this->works[i] = works[i];
  }
  this->worksCount = worksCount;
}

void Museum::copy(const Museum& other) {
  assignWorks(other.works, other.worksCount);
}

void Museum::erase() {
  delete[] works;
}
