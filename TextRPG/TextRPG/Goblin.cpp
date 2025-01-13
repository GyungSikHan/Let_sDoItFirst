#include "Goblin.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>

using namespace std;

void Goblin::takeDamage(int damage) {
	this->health -= damage;
}

Item* Goblin::dropItem() {
	int randomItem = rand() % 2;
	if (randomItem == 0)return new HealthPotion();
	else if (randomItem == 1)return new AttackBoost();
	return nullptr;
}

void Goblin::setName() {
	this->name = "°íºí¸°";
}

void Goblin::setAttack(int level, int random) {
	this->attack = level * random;
}

void Goblin::setHealth(int level, int random) {
	this->health = level * random;
}