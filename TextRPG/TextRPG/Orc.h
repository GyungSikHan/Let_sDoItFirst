#pragma once
#include<iostream>
#include<string>

#include "Monster.h"

using namespace std;
class Orc : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Orc(int level/*캐릭터 레벨*/) {
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
    Item* dropItem();
    int dropGold();
    int dropEXP() { return 20; };
};

