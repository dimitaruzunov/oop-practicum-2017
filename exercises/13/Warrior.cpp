#include "Warrior.h"

Warrior::Warrior() : Hero(120)
{
    rage = 0;
}
Warrior::Warrior(size_t live,size_t rage) :Hero(live)
{
    this->rage = rage;
}

void Warrior::attack(Hero* hero) const
{

}



