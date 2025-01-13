#pragma once
#include "Monster.h"
#include <iostream>
#include <string>

using namespace std;
class Slime : public Monster {
private:
    string name = "NULL";
    int health = 0;
    int attack = 0;
public:
    Slime(int level) {
        int RandomHelathBoost = rand() % 10 + 15;
        int RandomDamageBoost = rand() % 5 + 2;
        setName();
        setAttack(level, RandomDamageBoost);
        setHealth(level, RandomHelathBoost);
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
    int dropEXP() { return 10; };
    bool isDead();
};