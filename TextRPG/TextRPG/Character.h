#pragma once
#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Character
{
public:
	// Singleton Instance
	static Character* getInstance();

	// Display
	void displayStatus();
	void displayInventory();

	// Experience, Level Up
	void checkLevelUp();
	void levelUp();

	// Item, Inventory
	void pushItem(Item* _item);
	void popItem(int _index);
	void useItem(int _index);
	//void visitShop();

	// Battle
	bool isDeath();
	void takeDamage(int _damage);

	inline string getName() { return name; }
	inline const int getLevel() { return level; }
	inline const int getHealth() { return health; }
	inline const int getMaxHealth() { return maxHealth; }
	inline const int getAttack() { return attack; }
	inline const float getExperience() { return experience; }
	inline const float getMaxExperience() { return maxExperience; }
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
	Character();
	~Character();
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	static Character* instance;

	string name = "";
	int level = 1;
	int health = 100;
	int maxHealth = 100;
	int attack = 5;
	float experience = 0.0f;
	float maxExperience = 100.0f;
	int gold = 10;

	vector<Item*> inventory;
};

