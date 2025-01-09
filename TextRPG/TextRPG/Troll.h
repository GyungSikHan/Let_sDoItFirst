#pragma once
#include "Monster.h"
#include<iostream>
#include<string>

class Troll : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Troll(int level) {
        int RandomHelathBoost = rand() % 10 + 25;
        int RandomDamageBoost = rand() % 5 + 7;
        this->health = level * RandomHelathBoost;
        this->attack = level * RandomDamageBoost;
        this->name = "Æ®·Ñ";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem();
};