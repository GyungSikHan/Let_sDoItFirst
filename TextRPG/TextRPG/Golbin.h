#pragma once
#incluide "Monster.h"
#include<iostream>
#include<string>

class Goblin : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Goblin(int level) {
        this->health = level * 21;
        this->attack = level * 6;
        this->name = "°íºí¸°";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem() {}
};