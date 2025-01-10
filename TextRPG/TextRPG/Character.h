#pragma once
#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Character
{
public:
	static Character* getInstance(string _name = "");

	void displayStatus();
	void levelUp();
	void useItem(int _index);
	void visitShop();

	inline string getName() { return name; }
	inline const int getLevel() { return level; }
	inline const int getHealth() { return health; }
	inline const int getMaxHealth() { return maxHealth; }
	inline const int getAttack() { return attack; }
	inline const int getExperience() { return experience; }
	inline const int getGold() { return gold; }

private:
	Character(string _name);
	~Character();
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	static Character* instance;

	string name;
	int level = 1;
	int health = 200;
	int maxHealth = 200;
	int attack = 30;
	int experience = 0;
	int gold = 0;

	vector<Item*> inventory;
};

