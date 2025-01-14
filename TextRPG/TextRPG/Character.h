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
	void popItemByType(int _itemIndex);
	void popItemByIndex(int _inventoryIndex);
	void useItem(int _itemIndex);
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

	inline void addHealth(int _health)
	{
		health += _health;

		if (health > maxHealth)
		{
			health = maxHealth;
		}
	}
	inline void addAttack(int _attack)
	{
		attack += _attack;
	}
	inline void addExperience(float _experience)
	{
		experience += _experience;
	}
	inline void addGold(int _gold)
	{
		gold += _gold;
	}

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

	/*
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
	*/
};

