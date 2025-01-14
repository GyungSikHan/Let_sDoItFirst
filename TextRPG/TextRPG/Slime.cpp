#include "Slime.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <iostream>
#include <vector>

using namespace std;

Slime::Slime(int level) {
	int RandomHelathBoost = rand() % 10 + 15;
	int RandomDamageBoost = rand() % 5 + 2;
	int tempHealth = level * RandomHelathBoost;
	int tempAttack = level * RandomDamageBoost;
	string tempName = "ΩΩ∂Û¿”";
	setName(tempName);
	setAttack(tempAttack);
	setHealth(tempHealth);
}

void Slime::takeDamage(int damage) {
	int tHealth = getHealth() - damage;
	if (tHealth < 0) tHealth = 0;
	setHealth(tHealth);
}

vector<Item*> Slime::dropItem() {
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

void Slime::setName(string name) {
	this->name = name;
}

void Slime::setAttack(int attack) {
	this->attack = attack;
}

void Slime::setHealth(int health) {
	this->health = health;
}

int Slime::dropGold() {
	int randomGold = rand() % 20 + 30;
	return randomGold;
}

bool Slime::isDead() {
	if (getHealth() > 0) return false;

	return true;
}