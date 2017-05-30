#include "Hero.h"

Hero::Hero()
{
    this->live = 100;
}
Hero::Hero(size_t live)
{
    this->live = live;
}
void Hero::print() const
{
    std::cout<<"Live: "<<live<<std::endl;
}

