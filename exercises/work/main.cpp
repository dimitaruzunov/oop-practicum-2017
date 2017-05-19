#include <iostream>
#include "painting.h"
#include "album.h"
#include "book.h"
#include "museum.h"

using std::cout;

int main() {
  Painting monaLisa("Mona Lisa", "Leonardo da Vinci", 1503, 77, 53);

  Album appetiteForDestruction("Appetite For Destruction",
                               "Guns N' Roses", 1987, "Rock N' Roll");

  Book intensity("Intensity", "Dean Koontz", 1987, "Horror");

  Work* works[] = {
    &monaLisa,
    &appetiteForDestruction,
    &intensity
  };

  Museum museum(works, 3);

  museum.print();
  cout << '\n';
  museum.printByYear(1987);

  return 0;
}