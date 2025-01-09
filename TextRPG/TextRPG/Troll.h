#pragma once
#incluide "Monster.h"
#include<iostream>
#include<string>

class Troll : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Troll(int level) {
        this->health = level * 28;
        this->attack = level * 9;
        this->name = "Æ®·Ñ";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem();
};