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
	int ItemDropped = rand() % 10;
	if (ItemDropped < 3) {
		int randomItem = rand() % 100;
		if (randomItem < 10)return new HealthPotion();
		else if (10 <= randomItem && randomItem < 55)return new AttackBoost();
		else return new HealthPotion();
	}
	return nullptr;
}

void BossMonster::setName() {
	this-> name = "µå·¡°ï";
}

void BossMonster::setAttack(int level, int random) {
	this->attack = 520;
}

void BossMonster::setHealth(int level, int random) {
	this-> health = 60;
}

int BossMonster::dropGold() {
	int randomGold = rand() % 20 + 30;
	return randomGold;
}