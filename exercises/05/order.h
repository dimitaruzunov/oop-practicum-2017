#ifndef ORDER_H
#define ORDER_H

class Order {
  char* number;
  char** items;
  int size;
  int capacity;

  static const int INITIAL_CAPACITY;

  void setNumber(const char* number);
  void setItem(int index, const char* item);

  void resize();
  void copy(const Order& other);
  void erase();

public:

  Order();
  Order(const char* number);
  Order(const char* number, const char* items[], int itemsCount);
  Order(const Order& other);
  ~Order();

  Order& operator=(const Order& other);

  void addItem(const char* item);
  void cancel();
  void print() const;
};

#endif
