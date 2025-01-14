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
		character->addAttack(getAttackIncrease());
	};
	int getPrice(){return price;};
	int getItemIdx(){return itemIdx;};

	int getAttackIncrease(){return attackIncrease;};
private:
	string name = "AttackBoost (°ø°Ý·Â +7)";
	int attackIncrease = 7;
	int price = 170;
	int itemIdx = 2;
};

