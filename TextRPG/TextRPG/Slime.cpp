#include "Slime.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>

using namespace std;

void Slime::takeDamage(int damage) {
	this->health -= damage;
}

Item* Slime::dropItem() {
	int ItemDropped = rand() % 10;
	if (ItemDropped < 3) {
		int randomItem = rand() % 100;
		if (randomItem < 10)return new HealthPotion();
		else if (10 <= randomItem && randomItem < 55)return new AttackBoost();
		else return new HealthPotion();
	}
	return nullptr;
}

void Slime::setName() {
	this-> name = "½½¶óÀÓ";
}

void Slime::setAttack(int level, int random) {
	this-> attack = level * random;
}

void Slime::setHealth(int level, int random) {
	this-> health = level * random;
}

int Slime::dropGold() {
	int randomGold = rand() % 20 + 30;
	return randomGold;
}

bool Slime::isDead() {
	if (getHealth() > 0) return true;
	else return false;

	return false;
}