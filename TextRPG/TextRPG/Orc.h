#pragma once
#include<iostream>
#include<string>

class Orc : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Orc(int level) {
        this->health = level * 26;
        this->attack = level * 7;
        this->name = "¿ÀÅ©";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem();
};