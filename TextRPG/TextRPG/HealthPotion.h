#pragma once
#include <string>
#include "Item.h"
using namespace std;
class HealthPotion : public Item
{
public:
	HealthPotion(){};
	string getName(){return name;};
	void use(/*Character character*/);
	int getPrice() { return price; };
	int getItemIdx() { return itemIdx; };

private:
	string name = "HealthPotion (Ã¼·Â +50)";
	int healthRestore = 50;
	int price = 10;
	int itemIdx = 1;
};

