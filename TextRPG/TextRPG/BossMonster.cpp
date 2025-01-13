#include "BossMonster.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>

using namespace std;

void BossMonster::takeDamage(int damage) {
	this->health -= damage;
}

Item* BossMonster::dropItem() {
	int randomItem = rand() % 2;
	if (randomItem == 0)return new HealthPotion();
	else if (randomItem == 1)return new AttackBoost();
	return nullptr;
}

void BossMonster::setName() {
	this-> name = "µå·¡°ï";
}

void BossMonster::setAttack(int level, int random) {
	this-> attack = level * random;
}

void BossMonster::setHealth(int level, int random) {
	this-> health = level * random;
}

int BossMonster::dropGold() {
	int randomGold = rand() % 2;
	return randomGold;
}