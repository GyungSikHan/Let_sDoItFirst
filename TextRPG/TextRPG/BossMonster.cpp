#include "BossMonster.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>
#include <vector>

using namespace std;

BossMonster::BossMonster(int level) {
	int tempHealth = 520;
	int tempAttack = 60;
	string tempName = "µå·¡°ï";
	setName(tempName);
	setAttack(tempHealth);
	setHealth(tempAttack);
}

BossMonster::~BossMonster() {

}

void BossMonster::takeDamage(int damage) {
	int tHealth = getHealth() - damage;
	if (tHealth < 0) tHealth = 0;
	setHealth(tHealth);
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

void BossMonster::setName(string name) {
	this->name = name;
}

void BossMonster::setAttack(int attack) {
	this->attack = attack;
}

void BossMonster::setHealth(int health) {
	this->health = health;
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