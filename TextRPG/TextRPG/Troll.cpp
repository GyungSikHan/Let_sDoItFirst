#include "Troll.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>
#include <vector>

using namespace std;

void Troll::takeDamage(int damage) {
	this->health -= damage;
}

vector<Item*> Troll::dropItem() {
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

void Troll::setName() {
	this-> name = "Æ®·Ñ";
}

void Troll::setAttack(int level, int random) {
	this-> attack = level * random;
}

void Troll::setHealth(int level, int random) {
	this-> health = level * random;
}

int Troll::dropGold() {
	int randomGold = rand() % 20 + 30;
	return randomGold;
}

bool Troll::isDead() {
	if (getHealth() > 0) return true;
	else return false;

	return false;
}