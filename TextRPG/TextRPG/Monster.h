#pragma once
#include <iostream>
#include "item.h"

class Monster {
public:
    virtual string getName() = 0;
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual void takeDamge(int damage) = 0;
    virtual Item* dropItem() = 0;
};