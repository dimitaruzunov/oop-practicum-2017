#include "order.h"

int main() {
  Order order("AC1337DC");
  order.addItem("Gibson Les Paul Classic");
  order.addItem("Friedman PT-20");
  order.addItem("MXR Carbon Copy");
  order.print();
  order.cancel();
  order.print();

  return 0;
}