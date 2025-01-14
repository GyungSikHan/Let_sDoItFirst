#pragma once
#include <string>
#include "Item.h"
#include "Character.h"
using namespace std;

class HealthPotion : public Item
{
public:
	HealthPotion(){};
	string getName(){return name;};
	void use(Character* character){
		character->addHealth(getHealthRestore());
	};
	int getPrice() { return price; };
	int getItemIdx() { return itemIdx; };

	int getHealthRestore(){return healthRestore;};
private:
	string name = "HealthPotion (Ã¼·Â +70)";
	int healthRestore = 70;
	int price = 130;
	int itemIdx = 1;
};

