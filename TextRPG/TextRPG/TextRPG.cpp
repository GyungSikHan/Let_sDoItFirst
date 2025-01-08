#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameManager {
public:


};

class Item {
public:
    virtual string getName() = 0;
};

class Monster {
public:
    virtual string getName() = 0;
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual void takeDamge(int damage) = 0;
    virtual Item* dropItem();
};


class Goblin : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Goblin(int level) {
        this->health = level * 21;
        this->attack = level * 6;
        this->name = "고블린";
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAttack() {
        return attack;
    }
    void takeDamage(int damage) {
        this->health -= damage;
    }
    Item* dropItem() {

    }
};


class Orc : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Orc(int level) {
        this->health = level * 26;
        this->attack = level * 7;
        this->name = "오크";
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAttack() {
        return attack;
    }
    void takeDamage(int damage) {
        this->health -= damage;
    }
    Item* dropItem() {

    }
};


class Troll : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Troll(int level) {
        this->health = level * 28;
        this->attack = level * 9;
        this->name = "트롤";
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAttack() {
        return attack;
    }
    void takeDamage(int damage) {
        this->health -= damage;
    }
};

class Slime : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    Slime(int level) {
        this->health = level * 24;
        this->attack = level * 5;
        this->name = "슬라임";
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAttack() {
        return attack;
    }
    void takeDamage(int damage) {
        this->health -= damage;
    }
    Item* dropItem() {

    }
};

class BossMonster : public Monster {
private:
    string name;
    int health = 0;
    int attack = 0;
public:
    BossMonster(int level) {
        this->health = level * 45;
        this->attack = level * 15;
        this->name = "Dragon";
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAttack() {
        return attack;
    }
    void takeDamage(int damage) {
        this->health -= damage;
    }
    Item* dropItem() {

    }
};



int main()
{
    std::cout << "Hello World!\n";
}
