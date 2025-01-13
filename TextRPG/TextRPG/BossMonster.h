#pragma once
#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;
class BossMonster : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    BossMonster(int level) {
        int RandomHelathBoost = rand() % 15 + 30;
        int RandomDamageBoost = rand() % 8 + 8;
        this->health = level * RandomHelathBoost;
        this->attack = level * RandomDamageBoost;
        this->name = "Dragon";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage);
    Item* dropItem();
};