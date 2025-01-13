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
	int ItemDropped = rand() % 10;
	if (ItemDropped < 3) {
		int randomItem = rand() % 100;
		if (randomItem < 10)return new HealthPotion();
		else if (10 <= randomItem && randomItem < 55)return new AttackBoost();
		else return new HealthPotion();
	}
	return nullptr;
}

void Orc::setName() {
	this-> name = "¿ÀÅ©";
}

void Orc::setAttack(int level, int random) {
	this-> attack = level * random;
}

void Orc::setHealth(int level, int random) {
	this-> health = level * random;
}

int Orc::dropGold() {
	int randomGold = rand() % 20 + 30;
	return randomGold;
}