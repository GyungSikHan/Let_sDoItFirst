#include "Orc.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>

using namespace std;

void Orc::takeDamage(int damage) {
	this->health -= damage;
}
Item* Orc::dropItem() {
	int randomItem = rand() % 2;
	if (randomItem == 0)return new HealthPotion();
	else if (randomItem == 1)return new AttackBoost();
	return nullptr;
}

void Orc::setName() {
	this->name = "µå·¡°ï";
}

void Orc::setAttack(int level, int random) {
	this->attack = level * random;
}

void Orc::setHealth(int level, int random) {
	this->health = level * random;
}