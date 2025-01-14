#pragma once
#include "Monster.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Goblin : public Monster {
private:
    string name = "NULL";
    int health = 0;
    int attack = 0;
public:
    Goblin(int level);
    void setName(string name);
    void setAttack(int health);
    void setHealth(int health);
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage);
    vector<Item*> dropItem();
    int dropGold();
    int dropEXP(int level) { return 15 * level; };
    bool isDead();
};