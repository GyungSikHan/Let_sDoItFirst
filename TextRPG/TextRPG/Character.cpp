#include "Character.h"

#include <iostream>

Character* Character::instance = nullptr;

Character* Character::getInstance(string _name)
{
	if (!instance)
	{
		instance = new Character(_name);
	}
	else
	{
		cout << "이미 캐릭터가 존재합니다." << endl;
	}
	
	return instance;
}

Character::Character(string _name) : name(_name)
{
	
}

Character::~Character()
{

}

void Character::displayStatus()
{
	cout << "------------ Player Info ------------" << endl;
	cout << "Name:" << this->name << endl;
	cout << "Level: " << this->level << endl;
	cout << "HP: " << this->health << "/" << this->maxHealth << endl;
	cout << "Attack: " << this->attack << endl;
	cout << "EXP: " << this->experience << "/" << this->maxExperience << endl;
	cout << "Gold: " << this->gold << endl;
	cout << "-------------------------------------" << endl;
}

void Character::displayInventory()
{
	cout << "------------ Inventory --------------" << endl;

	for (int i = 0; i < inventory.size(); i++)
	{
		cout << "[" << i + 1 << "] " << inventory[i]->getName() << endl;
	}

	cout << "-------------------------------------" << endl;
}

void Character::checkLevelUp()
{
	if (this->level >= 10)
	{
		experience = maxExperience;

		cout << "최고 레벨에 도달하여 레벨업할 수 없습니다." << endl;
	}

	if (this->experience > this->maxExperience)
	{
		levelUp();

		cout << "레벨업! 축하합니다! (" << this->level - 1 << " -> " << this->level << ")" << endl;
	}
}

void Character::levelUp()
{
	this->level += 1;
	this->experience -= maxExperience;
	this->maxHealth = 100 + 20 * (this->level - 1);
	this->attack = 5 + 5 * (this->level - 1);
	this->maxExperience = 100.0f + 50.0f * float(this->level - 1);
	this->health = this->maxHealth;
}

void Character::pushItem(Item* _item)
{
	inventory.push_back(_item);
}

void Character::popItem(int _index)
{
	inventory.erase(inventory.begin() + _index);
}

void Character::useItem(int _index)
{
	inventory[_index]->use();
	popItem(_index);
}

void Character::visitShop()
{
	/*TODO*/
}
