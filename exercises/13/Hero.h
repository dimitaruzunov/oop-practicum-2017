#pragma once

#include <iostream>


class Hero
{
protected:
    size_t live;
public:
    Hero();
    Hero(size_t live);
    virtual void attack(Hero* hero) const = 0;
    virtual void print() const;

    size_t getLive() const
    {
        return live;
    }
    void setLive(size_t live)
    {
        this->live = live;
    }



};
