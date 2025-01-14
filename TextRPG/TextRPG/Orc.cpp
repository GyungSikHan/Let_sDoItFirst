#include "Orc.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>
#include <vector>

using namespace std;

Orc::Orc(int level) {
	int RandomHelathBoost = rand() % 10 + 20;
	int RandomDamageBoost = rand() % 5 + 5;
	int tempHealth = level * RandomHelathBoost;
	int tempAttack = level * RandomDamageBoost;
	string tempName = "ø¿≈©";
	setName(tempName);
	setAttack(tempHealth);
	setHealth(tempAttack);
}


void Orc::takeDamage(int damage) {
	int tHealth = getHealth() - damage;
	if (tHealth < 0) tHealth = 0;
	setHealth(tHealth);
}

vector<Item*> Orc::dropItem() {
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

void Orc::setName(string name) {
	this->name = name;
}

void Orc::setAttack(int attack) {
	this->attack = attack;
}

void Orc::setHealth(int health) {
	this->health = health;
}

int Orc::dropGold() {
	int randomGold = rand() % 20 + 30;
	return randomGold;
}

bool Orc::isDead() {
	if (getHealth() > 0) return false;

	return true;
}