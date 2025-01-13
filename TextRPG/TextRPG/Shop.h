#pragma once
#include "Item.h"
#include <vector>
#include "HealthPotion.h"
#include "AttackBoost.h"

class Shop
{
public:
	Shop(){
		avaliableItems.push_back(new HealthPotion);
		avaliableItems.push_back(new AttackBoost);
	}

	void displayItems();
	void buyItem(int index/*, Character* player*/);
	void sellItem(int index/*, Character* player*/);

private:
	vector<Item*> avaliableItems;
};

