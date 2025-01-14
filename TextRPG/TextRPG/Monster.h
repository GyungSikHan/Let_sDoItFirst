#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "item.h"

class Monster {
public:
    virtual string getName() = 0;
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual void setHealth(int health) = 0;
    virtual void setName(string name) = 0;
    virtual void setAttack(int attack) = 0;
    virtual void takeDamage(int damage) = 0;
    virtual vector<Item*> dropItem() = 0;
    virtual int dropGold() = 0;
    virtual int dropEXP(int level) = 0;
    virtual bool isDead() = 0;
};