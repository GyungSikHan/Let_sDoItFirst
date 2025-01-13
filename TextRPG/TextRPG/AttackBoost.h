#pragma once
#include <string>
#include "Item.h"
#include "Character.h"
using namespace std;


class AttackBoost : public Item
{
public:
	string getName(){return name;};
	void use(Character* character){
		character->setAttack(character->getAttack() + getAttackIncrease());
	};
	int getPrice(){return price;};
	int getItemIdx(){return itemIdx;};

	int getAttackIncrease(){return attackIncrease;};
private:
	string name = "AttackBoost (°ø°Ý·Â +10)";
	int attackIncrease = 10;
	int price = 15;
	int itemIdx = 2;
};

