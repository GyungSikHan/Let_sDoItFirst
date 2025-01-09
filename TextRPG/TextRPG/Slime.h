#pragma once
#include "Monster.h"
#include<iostream>
#include<string>

class Slime : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Slime(int level) {
        int RandomHelathBoost = rand() % 10 + 15;
        int RandomDamageBoost = rand() % 5 + 2;
        this->health = level * RandomHelathBoost;
        this->attack = level * RandomDamageBoost;
        this->name = "½½¶óÀÓ";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem();
};