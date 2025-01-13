#include "BossMonster.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>
#include <vector>

using namespace std;

void BossMonster::takeDamage(int damage) {
	this->health -= damage;
}

vector<Item*> BossMonster::dropItem() {
	int ItemDropped = rand() % 10;
	vector<Item*> DroppedItem;
	if (ItemDropped < 3) {
		int randomItem = rand() % 100;
		if (randomItem < 10) {
			DroppedItem.push_back(new HealthPotion);
			DroppedItem.push_back(new AttackBoost);
		}
		else if (10 <= randomItem && randomItem < 55)DroppedItem.push_back(new HealthPotion);
		else DroppedItem.push_back(new AttackBoost);
	}
	return DroppedItem;
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

bool BossMonster::isDead() {
	if (getHealth() > 0) return true;
	else return false;

	return false;
}