#include "Troll.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>

using namespace std;

void Troll::takeDamage(int damage) {
	this->health -= damage;
}

Item* Troll::dropItem() {
	int randomItem = rand() % 2;
	if (randomItem == 0)return new HealthPotion();
	else if (randomItem == 1)return new AttackBoost();
	return nullptr;
}

void Troll::setName() {
	this->name = "½½¶óÀÓ";
}

void Troll::setAttack(int level, int random) {
	this->attack = level * random;
}

void Troll::setHealth(int level, int random) {
	this->health = level * random;
}