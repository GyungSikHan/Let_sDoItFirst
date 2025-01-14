#include "Character.h"

#include <iostream>

Character* Character::instance = nullptr;

Character* Character::getInstance()
{
	if (!instance)
	{
		instance = new Character();
	}
	else
	{
		cout << "이미 캐릭터가 존재합니다." << endl;
	}
	
	return instance;
}

void Character::DeleteInstance()
{
	if(instance == nullptr)
		return;

	delete instance;
	instance = nullptr;
}

Character::Character()
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
	vector<int> itemCnt(2, 0);

	for (int i = 0; i < inventory.size(); i++)
	{
		int itemType = inventory[i]->getItemIdx() - 1;
		
		itemCnt[itemType] += 1;
	}

	cout << "------------ Inventory --------------" << endl;
	cout << "[1] HealthPotion (체력 +70) - " << itemCnt[0] << "개" << endl;
	cout << "[2] AttackBoost (공격력 +7) - " << itemCnt[1] << "개" << endl;
	cout << "-------------------------------------" << endl;
}

void Character::checkLevelUp()
{
	if (this->level >= 10)
	{
		this->experience = this->maxExperience;

		cout << "최고 레벨에 도달하여 레벨업할 수 없습니다." << endl;
	}

	if (this->experience >= this->maxExperience)
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

void Character::popItemByType(int _itemIndex)
{
	int invenIndex = -1;

	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getItemIdx() == _itemIndex)
		{
			invenIndex = i;
			break;
		}
	}

	if (invenIndex == -1)
	{
		cout << "해당 아이템이 인벤토리에 없습니다." << endl;
		return;
	}

	popItemByIndex(invenIndex);
}

void Character::popItemByIndex(int _invenIndex)
{
	inventory.erase(inventory.begin() + _invenIndex);
}

bool Character::useItem(int _itemIndex)
{
	int invenIndex = -1;

	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getItemIdx() == _itemIndex)
		{
			invenIndex = i;
			break;
		}
	}

	if (invenIndex == -1)
	{
		cout << "해당 아이템이 인벤토리에 없습니다." << endl;

		return false;
	}

	inventory[invenIndex]->use(this);
	popItemByIndex(invenIndex);

	return true;
}

bool Character::isDeath()
{
	if (this->health <= 0)
	{
		return true;
	}

	return false;
}

void Character::takeDamage(int _damage)
{
	this->health -= _damage;

	if (this->health <= 0)
	{
		this->health = 0;
	}
}