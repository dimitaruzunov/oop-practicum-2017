#include "Magician.h"


Magician::Magician() : Hero()
{
    this->mana = 100;
}
Magician::Magician(size_t live,size_t mana) : Hero(live)
{
    this->mana = mana;
}
void Magician::attack(Hero* hero) const
{
    hero->setLive(hero->getLive() - this->mana);
}


size_t Magician::getMana() const
{
    return mana;
}
