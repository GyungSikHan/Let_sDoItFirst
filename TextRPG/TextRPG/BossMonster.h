#pragma once
#include "Monster.h"
#include <iostream>
#include <string>

using namespace std;
class BossMonster : public Monster {
private:
    string name = "NULL";
    int health = 0;
    int attack = 0;
public:
    BossMonster(int level) {
        setName();
        setAttack(level, 0);
        setHealth(level, 0);
    }
    void setName();
    void setAttack(int level, int random);
    void setHealth(int level, int random);
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage);
    Item* dropItem();
    int dropGold();
    bool isDead();
};