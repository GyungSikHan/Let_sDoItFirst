#include "GameMGR.h"
#include "Goblin.h"
#include "Orc.h"
#include "Shop.h"
#include "Slime.h"
#include "Troll.h"

GameMGR* GameMGR::instance = nullptr;

GameMGR::GameMGR()
{
	Init();
}

GameMGR::~GameMGR()
{

}

void GameMGR::Init()
{
	shop = new Shop();
}

void GameMGR::Create()
{
	if (instance == nullptr)
		instance = new GameMGR;
}


GameMGR* GameMGR::GetInstance()
{
	return instance;
}


Monster* GameMGR::GenerateMonster(int level)
{
	int ran = (int)(rand() % 4);
	Monster* monster{};
	switch (ran)
	{
	case 0:
		monster = new Goblin(level);
		return monster;
		break;
	case 1:
		monster = new Orc(level);
		return monster;
		break;
	case 2:
		monster = new Troll(level);
		return monster;
		break;
	case 3:
		monster = new Slime(level);
		return monster;
		break;
	default:
		ran = (int)(rand() % 3);
		break;
	}
	return monster;
}

BossMonster* GameMGR::GenerateBossMonster(int level)
{
	if (instance == nullptr)
		return nullptr;

	Monster* monster = new BossMonster(level);
	return dynamic_cast<BossMonster*>( monster);
}

void GameMGR::Battle()
{
	Monster* monster{};
	if (player->getLevel() >= 10)
		monster = GenerateBossMonster(player->getLevel());
	else
		monster = GenerateMonster(player->getLevel());

	if (monster == nullptr)
	{
		cout << "몬스터가 존재하지 않습니다!!" << endl;
		return;
	}
	cout << monster->getName() << "이 등장했다!!!" << endl;

	//TODO 전투 및 결과
	bool bMonsterDead{};
	bool bRun{};
	int index{};
	int index2{};
	while (bMonsterDead == false && bPlayerDead == false && bRun == false)
	{
		bool bUse{};
		cout << "-----" << monster->getName() << "-----" << endl;
		cout << "체력: " << monster->getHealth() << " 공격력 : " << monster->getAttack() << endl;
		cout << "1. 공격 2. 인벤토리 3. 도망가기 ";
		cin >> index;

		switch (index)
		{
		case 1:
			Attack(monster, 0);
			if (IsMonsterDead(monster) == true)
			{
				bMonsterDead = true;
				{
					cout << monster->getName() << "이 죽었습니다!!" << endl;
					//Get Gold
					{
						int tmpeGold = monster->dropGold();
						cout << tmpeGold << "획득!!" << endl;
						player->addGold(tmpeGold);
						cout << "소지골드 : " << player->getGold() << endl;
					}
					for (Item* item : monster->dropItem())
					{
						cout << item->getName() << "을 획득했습니다!!" << endl;
						player->pushItem(item);
					}
					//Exp 셋팅
					{
						int tempExp = monster->dropEXP();
						cout << tempExp << "의 EXP를 얻었습니다!!!" << endl;
						player->addExperience(tempExp);
						player->checkLevelUp();
					}
				}
			}
			break;
		case 2:
			DisplayInventory();
			cout << "어떤 아이템을 사용하시겠습니까?? ";
			cin >> index2;
			//TODO useItem bool 형으로 만들어서 아이템 잘못 선택시 사용 못하고 다른 행동으로 바꾸게 적용하기
			bUse = player->useItem(index2);
			if (index2 == 1 && bUse == true)
				cout << "체력회복!!!" << player->getHealth() << "/" << player->getMaxHealth() << endl;
			else if (index2 == 2 && bUse == true)
				cout << "공격력 증가 : " << player->getAttack() << endl;
			else if ((index2 != 1 && index2 != 2) || bUse == false)
			{
				cout << "잘못 입력했습니다!!" << endl;
				continue;
			}

			break;
		case 3:
			bRun = true;
			cout << player->getName() << "이 도망갑니다" << endl;
			break;
		}
		if (bRun == false && bMonsterDead == false)
		{
			Attack(monster, 1);
			if (IsPlayerDead() == true)
				bPlayerDead = true;
		}
	}

	PlayerDead();
	int a{};
	delete monster;
	monster = nullptr;
}

void GameMGR::VisitShop()
{

	shop->displayItems();

	int index{};
	int index2{};
	while (index != 3)
	{
		cout << "1. 아이템 구매 2. 아이템 판매 3. 나가기";
		cin >> index;
		bool bSell{};
		switch (index)
		{
		case 1:
			cout << "구매할 아이템 번호를 입력하세요: ";
			cin >> index2;
			if (player->getGold() < shop->getShopItems()[index2 - 1]->getPrice())
				cout << "Gold가 부족합니다!!!" << endl;
			else
				shop->buyItem(index2 - 1, player);
			break;
		case 2:
			if (player->getInventory().size() == 0)
			{
				cout << "판매할 아이템이 없습니다!!!" << endl;
				break;
			}

			cout << "판매할 아이템 번호를 입력하세요: ";
			DisplayInventory();
			cin >> index2;

			for (int i = 0; i < player->getInventory().size(); i++)
			{
				if (player->getInventory()[i]->getItemIdx() == index2)
				{
					bSell = true;
					shop->sellItem(index2, player);
					break;
				}
			}
			if (bSell == false)
				cout << "해당 아이템이 없습니다!!!" << endl;
			break;
		case 3:
			cout << "상점에서 나갑니다" << endl;
			break;
		}
	}

}

void GameMGR::DisplayInventory()
{
	player->displayInventory();
}

void GameMGR::StartGame(bool bDebug)
{
	bDebugMode = bDebug;
	PrintDebug();
	int temp{};
	cout << "Text 세계에 오신걸 환영합니다." << endl;
	cout << "1. 게임 시작     2. 게임종료" << endl;
	while (temp != 1 && temp != 2)
	{
		cin >> temp;
		ExitGame(temp);
		if (temp != 1 && temp != 2)
			cout << "잘못 입력했습니다. 다시 입력해주세요" << endl;
	}

	switch (temp)
	{
	case 1:
		InitCharacter();
		Play();
		if(bPlayerDead == true)
			RestartGame();
		break;
	case 2:
		break;
	}
}

void GameMGR::InitCharacter()
{
	string name{};
	cout << "캐릭터의 이름을 지어주세요(10자 이내) :";
	cin >> name;
	if (name.size() > 10)
		name.erase(10, name.size());
	player = Character::getInstance();
	player->setName(name);
}

void GameMGR::PrintCharacterInfo()
{
	player->displayStatus();
}

void GameMGR::Play()
{
	PrintDebug();
	int data{};
	while (data != 5)
	{
		cout << "1. 전투 2. 상점 3. Player 정보 4. 인벤토리 5. 게임 끝내기" << endl;
		cin >> data;
		ExitGame(data);

		switch (data)
		{
		case 1:
			Battle();
			break;
		case 2:
			VisitShop();
			break;
		case 3:
			PrintCharacterInfo();
			break;
		case 4:
			DisplayInventory();
			break;
		case 5:
			cout << "게임을 종료합니다!!" << endl;
			break;
		}

		if(bPlayerDead == true)
			break;
	}
}

void GameMGR::Attack(Monster* monster, int index)
{
	if (index == 0)
	{
		cout << player->getName() << "이 공격합니다!!!" << endl;
		cout << "공격력 : " << player->getAttack() << endl;
		monster->takeDamage(player->getAttack());
		cout << monster->getName() << "이 공격당합니다!!" << endl;
		cout << "남은체력 : " << monster->getHealth() << endl;
	}
	else
	{
		cout << monster->getName() << "이 공격합니다!!!" << endl;
		cout << "공격력 : " << monster->getAttack() << endl;
		player->takeDamage(monster->getAttack());
		cout << player->getName() << "이 공격당합니다!!" << endl;
		cout << "남은체력 : " << player->getHealth() << endl;
	}
}

bool GameMGR::IsMonsterDead(Monster* monster)
{
	return monster->isDead();
}

bool GameMGR::IsPlayerDead()
{
	return player->isDeath();
}

void GameMGR::PlayerDead()
{
	if(bPlayerDead == false)
		return;
	cout << player->getName() << "이 죽었습니다!!!" << endl;
}

void GameMGR::RestartGame()
{
	if(bPlayerDead == false)
		return;

	if(bDebugMode == false)
	{
		player->DeleteInstance();
		player = nullptr;
		StartGame();
	}
	else
	{
		while (bEndDebug == false)
		{
			cout << "디버깅 모드에선 죽지 않습니다" << endl;
			bPlayerDead = false;
			player->addHealth(player->getMaxHealth());
			Play();
		}
	}
}
