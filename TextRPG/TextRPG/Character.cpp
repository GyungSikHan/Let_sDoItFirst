#include "Character.h"

#include <iostream>

Character* Character::instance = nullptr;

Character* Character::getInstance(string _name)
{
	if (!instance)
	{
		instance = new Character(_name);
	}
	else if (_name != instance->name)
	{
		cout << "존재하지 않는 캐릭터입니다." << endl;
	}
	
	return instance;
}

Character::Character(string _name) : name(_name)
{
	cout << "캐릭터 " << this->name << " 생성 완료! 레벨: " << level << ", 체력: " << this->health << ", 공격력: " << this->attack << endl;
}

Character::~Character()
{
}

void Character::displayStatus()
{
	cout << this->name << "의 상태창을 확인합니다." << endl
		<< "-----" << endl
		<< "레벨: " << this->level << endl
		<< "체력: " << this->health << "/" << this->maxHealth << endl
		<< "공격력: " << this->attack << endl
		<< "경험치: " << this->experience << endl
		<< "골드: " << this->gold << endl
		<< "인벤토리: " << endl;
	
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << "  " << i + 1 << ". " << inventory[i]->getName() << endl;
	}

	cout << "-----" << endl;
}

void Character::levelUp()
{
	if (experience < 100)
	{
		cout << "경험치가 부족하여 레벨업할 수 없습니다." << endl;
	}

	if (this->level >= 10)
	{
		cout << "최고 레벨에 도달하여 레벨업할 수 없습니다." << endl;
	}

	this->level += 1;
	this->experience -= 100;
	this->maxHealth += 20 * (this->level);
	this->attack += 5 * (this->level);
	this->health = this->maxHealth;
}

void Character::useItem(int _index)
{
	inventory[_index]->use();

	inventory.erase(inventory.begin() + _index);
}

void Character::visitShop()
{
	/*TODO*/
}
