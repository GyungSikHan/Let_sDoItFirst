#pragma once
#include "Monster.h"
#include<iostream>
#include<string>

using namespace std;
class BossMonster : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    BossMonster(int level/*캐릭터 레벨*/) {
        int RandomHelathBoost = rand() % 15 + 30;
        int RandomDamageBoost = rand() % 8 + 8;
        this->health = level * RandomHelathBoost;
        this->attack = level * RandomDamageBoost;
        this->name = "Dragon";
    }
    string getName() { return name; }
    int getHealth() { return health; }
    int getAttack() { return attack; }
    void takeDamage(int damage) { this->health -= damage; }
    Item* dropItem(/*아이템 관련 매개변수*/) {
        /*아이템 종류에 따른 함수*/
    }
};