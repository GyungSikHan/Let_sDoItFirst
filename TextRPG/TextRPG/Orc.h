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
        int RandomHelathBoost = rand() % 10 + 20;
        int RandomDamageBoost = rand() % 5 + 5;
        this->health = level * RandomHelathBoost;
        this->attack = level * RandomDamageBoost;
        this->name = "¿ÀÅ©";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem();
};