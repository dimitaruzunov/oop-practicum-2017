#pragma once
#include "Hero.h"

class Warrior : public Hero
{
private:
    size_t rage;
public:
    Warrior();
    Warrior(size_t live,size_t rage);
    size_t getRage() const;
    void attack(Hero* hero) const;
};
