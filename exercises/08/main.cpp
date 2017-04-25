#include <iostream>
#include "set.h"

using std::cout;
using std::boolalpha;

int main() {
  Set emptySet;
  cout << emptySet << '\n';

  Set set; // set = {}
  set += 1; // set = {1}
  cout << set << set + 2 << set << '\n';

  set += 2; // set = {1, 2}
  cout << set << set - 1 << set << '\n';

  set += 42; // set = {1, 2, 42}
  cout << set << (set ^ 42) << set << '\n';

  cout << boolalpha << (set == 42) << '\n';

  cout << boolalpha << (set - (Set(1) + 2) == 42) << '\n';

  return 0;
}