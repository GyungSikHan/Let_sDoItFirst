#include "Troll.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>
#include <vector>

using namespace std;

Troll::Troll(int level) {
	int RandomHelathBoost = rand() % 10 + 25;
	int RandomDamageBoost = rand() % 5 + 7;
	int tempHealth = level * RandomHelathBoost;
	int tempAttack = level * RandomDamageBoost;
	string tempName = "Æ®·Ñ";
	setName(tempName);
	setAttack(tempHealth);
	setHealth(tempAttack);
}


void Troll::takeDamage(int damage) {
	int tHealth = getHealth() - damage;
	if (tHealth < 0) tHealth = 0;
	setHealth(tHealth);
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

void Troll::setName(string name) {
	this-> name = name;
}

void Troll::setAttack(int attack) {
	this-> attack = attack;
}

void Troll::setHealth(int health) {
	this-> health = health;
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