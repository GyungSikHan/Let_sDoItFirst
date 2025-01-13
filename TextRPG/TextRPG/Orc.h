#pragma once
#include "Monster.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Orc : public Monster {
private:
    string name = "NULL";
    int health = 0;
    int attack = 0;
public:
    Orc(int level) {
        int RandomHelathBoost = rand() % 10 + 20;
        int RandomDamageBoost = rand() % 5 + 5;
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
    vector<Item*> dropItem();
    int dropGold();
    int dropEXP() { return 20; };
    bool isDead();
};