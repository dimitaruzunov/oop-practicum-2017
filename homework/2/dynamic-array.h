#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
  int* elements;
  int size;
  int capacity;

  static const int INITIAL_CAPACITY;

  void copy(const DynamicArray& other);
  void erase();
  void resize();

public:

  DynamicArray();
  DynamicArray(int elements[], int elementsCount);
  DynamicArray(int capacity);
  DynamicArray(const DynamicArray& other);
  ~DynamicArray();

  DynamicArray& operator=(const DynamicArray& other);

  int getSize() const;
  bool isEmpty() const;
  int get(int index) const;
  int operator[](int index) const;
  bool includes(int element) const;

  void set(int index, int newValue);
  void push(int element);
  int pop();
  void insertAt(int index, int element);
  int removeAt(int index);

  DynamicArray& operator+=(const DynamicArray& other);
  DynamicArray operator+(const DynamicArray& other);
  DynamicArray& operator-=(const DynamicArray& other);
  DynamicArray operator-(const DynamicArray& other);

  void print() const;
};

#endif
