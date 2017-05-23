#include <iostream>
#include "person.h"
#include "student.h"
#include "worker.h"
#include "surgeon.h"
#include "vet.h"

int main() {
  Person petar("Petar Petrov", 21);
  petar.print();

  Student ivan("Ivan Dobrev", 22, "Journalism", 6);
  ivan.print();

  Worker georgi("Georgi Georgiev", 27, 200, 40);
  georgi.print();

  Surgeon surgeon("Maria", 17, "Cardiology");
  std::cout << surgeon;
  std::cout << surgeon.chance("Cardiology")
            << '\n' << surgeon.chance("Podiatry") << '\n';

  Vet vet("Martin", 20, "Dog");
  std::cout << vet;
  std::cout << vet.chance("Dog") << '\n' << vet.chance("Cat") << '\n';

  return 0;
}