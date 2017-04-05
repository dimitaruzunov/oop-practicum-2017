#include <iostream>
#include "apartment.h"

using std::cin;
using std::cout;
using std::boolalpha;

int main() {
  Apartment firstApartment;
  cin >> firstApartment;
  cout << firstApartment;

  Apartment secondApartment;
  cin >> secondApartment;
  cout << secondApartment;

  cout << boolalpha << (firstApartment < secondApartment) << '\n';
  cout << boolalpha << (firstApartment <= secondApartment) << '\n';
  cout << boolalpha << (firstApartment == secondApartment) << '\n';
  cout << boolalpha << (firstApartment >= secondApartment) << '\n';
  cout << boolalpha << (firstApartment > secondApartment) << '\n';

  cout << firstApartment["Bedroom"] << '\n';

  return 0;
}
