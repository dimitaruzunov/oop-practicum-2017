#pragma once

#include "Hero.h"

class Magician :public Hero
{
private:
    size_t mana;

public:
    Magician();
    Magician(size_t live,size_t mana);
    void attack(Hero* hero) const;

    size_t getMana() const;
 };
