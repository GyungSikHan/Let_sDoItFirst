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
	inline const vector<Item*> getInventory() { return inventory; }

	inline void setName(string _name)
	{
		name = _name;
	}
	inline void setHealth(int _health)
	{
		if (health > maxHealth)
		{
			health = maxHealth;
		}
		else
		{
			health = _health;
		}
	}
	inline void setAttack(int _attack)
	{
		attack = _attack;
	}
	inline void setGold(int _gold)
	{
		gold = _gold;
	}
	void pushItem(class Item* _item){
		inventory.push_back(_item);
	};
private:
	Character(string _name);
	~Character();
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	static Character* instance;

	string name;
	int level = 1;
	int health = 100;
	int maxHealth = 100;
	int attack = 5;
	int experience = 0;
	int maxExperience = 100;
	int gold = 0;

	vector<Item*> inventory;
};

