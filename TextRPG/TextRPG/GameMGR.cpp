﻿#include "GameMGR.h"

#define NOMINMAX

#include <limits>
#include <string>
#include <Windows.h>
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
		ran = (int)(rand() % 4);
		break;
	}

	bBoss == false;
	return monster;
}

BossMonster* GameMGR::GenerateBossMonster(int level)
{
	if (instance == nullptr)
		return nullptr;
	bBoss = true;
	Monster* monster = new BossMonster(level);
	return dynamic_cast<BossMonster*>(monster);
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
	int MaxHelth = monster->getHealth();
	cout<<"야생의 " << monster->getName() << "(가) 나타났다!!!" << endl;

	//TODO 전투 및 결과
	bool bMonsterDead{};
	bool bRun{};
	int index{};
	int index2{};
	bool bUseAttackBoost{};
	int tempAttack{};
	while (bMonsterDead == false && bPlayerDead == false && bRun == false)
	{
		bool bUseItem = true;
		cout << "============== 전투 ==============" << endl;
		cout << "----------------------------------" << endl;
		cout << "[Player ~ "<<player->getName()<<"] HP : "<<player->getHealth()<<"/"<<player->getMaxHealth() << " 공격력 : "<<player->getAttack() << endl;
		cout << "[Monster ~ "<<monster->getName()<<"] HP : "<<monster->getHealth()<<"/"<< MaxHelth<<" 공격력 : "<<monster->getAttack() << endl;
		cout << "----------------------------------" << endl;
		cout<<"어떻게 하시겠습니까?"<<endl;
		cout<<"1. 공격하기"<<endl;
		cout<<"2. 아이템 사용하기"<<endl;
		cout<<"3. 도망가기"<<endl;
		cout<<"=================================="<<endl;
		cout << "(*입력) ";

		while (true)
		{
			cin >> index;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
				cout << "(*입력) ";
			}
			else if(index >= 1 && index <= 3)
				break;
		}
		switch (index)
		{
		case 1:
			Sleep(1000);
			Attack(monster, 0);
			
			break;
		case 2:
			DisplayInventory();
			cout << "사용할 아이템 번호를 입력해주세요(3 이전으로 돌아가기) : (입력)";
			while (true)
			{
				cin >> index2;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "잘못된 입력입니다. 다시 입력해주세요. : (입력)" << endl;
				}
				else if(index2 >= 1 && index2 <= 3)
					break;
			}
			if (index2 == 3)
			{
				system("cls");
				continue;
			}
			bUseItem = player->useItem(index2);
			if (index2 == 1 && bUseItem)
				cout << "체력이 회복되었다! (HP : " << player->getHealth() << "/" << player->getMaxHealth() << ")" << endl;
			else if (index2 == 2 && bUseItem)
			{
				bUseAttackBoost = true;
				cout << "공격력이 증가했다! (공격력 : " << player->getAttack() << ")" << endl;
			}
			break;
		case 3:
			bRun = true;
			bBoss = false;
			cout<<"비록 지금은 도망치지만... 다음에 다시 만날 때를 각오해라 !!!"<<endl;
			cout << player->getName() << "은(는) " <<monster->getName()<<"(으)로부터 무사히 도망쳤다..." << endl;
			break;
		}
		if (bRun == false)
		{
			Sleep(500);

			bMonsterDead = IsMonsterDead(monster);
			if (bMonsterDead == true)
			{
				Sleep(500);
				system("cls");
				if (bBoss == false)
				{
					cout << monster->getName() << "을(를) 쓰러트렸다!!!" << endl;
					//Exp 셋팅
					{
						int tempExp = monster->dropEXP(player->getLevel());
						cout << "EXP를 " << tempExp << "의 EXP를 얻었습니다!!!" << endl;
						player->addExperience(tempExp);
						player->checkLevelUp();
					}
					//Get Gold
					{
						int tmpeGold = monster->dropGold();
						cout << tmpeGold << " Gold를 획득했다!" << endl;
						player->addGold(tmpeGold);
					}
					for (Item* item : monster->dropItem())
					{
						cout << item->getName() << "을(를) 획득했! 운이 좋았어!" << endl;
						player->pushItem(item);
					}
				}
				Sleep(1000);
				system("cls");
				break;

			}
			Attack(monster, 1);
			if (IsPlayerDead() == true)
				bPlayerDead = true;
		}
		Sleep(1000);
		system("cls");
	}
	if(bUseAttackBoost == true)
	{
		player->OriginAttack();
		cout << "지속 아이템 효과가 끝났습니다..." << endl;
		cout << "공격력이 감소했다! (공격력 : " << player->getAttack() << ")" << endl;
		Sleep(1000);
		system("cls");
	}
	PlayerDead();
	BossDead(monster);
	delete monster;
	monster = nullptr;
}

void GameMGR::VisitShop()
{
	int index{};
	int index2{};
	while (index != 3)
	{
		shop->displayItems();
		cout << "어서오세요, 무엇을 하시겠습니까? (소지금 : "<< player->getGold()<<" Gold)"<<endl;
		cout<<"1. 아이템 구매" << endl;
		cout << "2. 아이템 판매" << endl;
		cout << "3. 나가기"<<endl;
		cout << "==================================" << endl;
		cout << "(*입력)";
		while (true)
		{
			cin >> index;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
				cout << "(입력)";
			}
			else if(index >= 1 && index <= 3)
				break;
			
		}
		cout << "//" << endl;

		bool bSell{};
		switch (index)
		{
		case 1:
			cout << "구매할 아이템 번호를 입력해주세요(3. 뒤로가기) : (입력)";
			while (true)
			{
				cin >> index2;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
					cout << "(입력)";
				}
				else if (index2 >= 1 && index2 <= 3)
					break;
			}
			cout << "//" << endl;
			if (index2 == 3)
			{
				system("cls");
				continue;
			}
			else if (player->getGold() < shop->getShopItems()[index2 - 1]->getPrice())
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

			DisplayInventory();
			cout << "아이템 판매가는 구매가의 절반입니다." << endl;
			cout << "확인하셨다면 판매할 아이템 번호를 입력해주세요(3. 뒤로가기) : (입력)";
			while (true)
			{
				cin >> index2;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
					cout << "(입력)";
				}
				if (index2 >= 1 || index2 <= 3)
					break;
			}
			if(index2 == 3)
			{
				system("cls");
				continue;
			}
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
			cout << "상점을 나가 마을로 돌아갑니다..." << endl;
			break;
		}

		Sleep(1000);
		system("cls");
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
	cout << "==================================" << endl;
	cout << "Text의 세계에 오신 것을 환영합니다." << endl;
	cout << "숫자를 입력하고 엔터를 눌러주세요." << endl;
	cout << "1. 게임 시작" << endl;
	cout << "2. 게임 종료" << endl;
	cout << "==================================" << endl;
	cout << "(*입력) " << endl;
	while (true)
	{
		cin >> temp;
		ExitGame(temp);
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
		}
		else if (temp == 1 || temp == 2)
			break;
	}
	
	switch (temp)
	{
	case 1:
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Sleep(1000);
		system("cls");
		InitCharacter();
		Play();
		RestartGame();
		break;
	case 2:
		EndGame();
		break;
	}
}

void GameMGR::InitCharacter()
{
	string name{};
	bBoss = false;
	bPlayerDead = false;
	cout << "모험가님의 이름은 무엇입니까? (10자 이내)" << endl;
	cout << "(*입력) " << endl;
	while (true)
	{
		getline(cin, name);

		if(name.empty() == false)
			break;
		cout << "다시 입력해주세요." << endl;
		cout << "(*입력) " << endl;
	}

	if (name.size() > 10)
		name.erase(10, name.size());
	player = Character::getInstance();
	player->setName(name);
	cout << "환영합니다. " << player->getName() << " 님." << endl;
}

void GameMGR::PrintCharacterInfo()
{
	player->displayStatus();
}

void GameMGR::Play(int* temp)
{
	Sleep(1000);
	system("cls");
	int data{};
	while (data != 5)
	{
		PrintDebug();
		cout << "============== 마을 ==============" << endl;
		cout << "무엇을 하시겠습니까 ?" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 상점" << endl;
		cout << "3. Player 정보" << endl;
		cout << "4. 인벤토리" << endl;
		cout << "5. 게임 끝내기" << endl;
		cout << "==================================" << endl;
		cout << "(*입력) ";
		while(true)
		{
			cin >> data;
			ExitGame(data);
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
				cout << "(*입력) ";
			}
			else if (data >= 0/*debugmode가 아니라면 1*/ && data <= 5)
				break;
		}
		Sleep(500);
		system("cls");
		switch (data)
		{
		case 0:
			GoFromDebugModeToBoss();
			break;
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
			if (temp != nullptr)
				*temp = 5;
			EndGame();
			break;
		}

		if (bPlayerDead == true)
			break;
		
		else if(bBoss == true)
			break;
		
	}


}

void GameMGR::Attack(Monster* monster, int index)
{
	if (index == 0)
	{
		cout << player->getName() << "의 공격!" << endl;
		cout << monster->getName() << "에게 " << player->getAttack() << "만큼의 데미지를 입혔다!" << endl;
		monster->takeDamage(player->getAttack());
		cout << "//" << endl;
	}
	else
	{
		cout << monster->getName() << "의 공격!" << endl;
		cout << player->getName() << "은(는) "<< monster->getAttack()<<"만큼의 데미지를 입었다..." << endl;
		player->takeDamage(monster->getAttack());
		cout << "//" << endl;
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
	if (bPlayerDead == false)
		return;
	cout << player->getName() << "이 죽었습니다!!!" << endl;
	Sleep(800);
	cout << "이대로 Text 세계의 평화는 어떻게 되는 것인가....." << endl;
	Sleep(1000);
	system("cls");
}

void GameMGR::BossDead(Monster* monster)
{
	if(bBoss == false)
		return;
	if(bPlayerDead == true)
		return;

	cout << monster->getName() << "을(를) 쓰러트렸다!!!" << endl;
	cout << "정말 쉽지 않은 싸움이었지만 해냈어...!" << endl;
	cout << "//" << endl;
	Sleep(800);

	cout << "==================================" << endl;
	cout << "그리하여, 세상은 Text용사" << endl;
	Sleep(800);
	cout << player->getName()<<"의 활약으로" << endl;
	Sleep(800);
	cout << "평화를 되찾았다..." << endl;
	cout << "==================================" << endl;
	Sleep(800);
	system("cls");
	
}

void GameMGR::RestartGame()
{
	if (bPlayerDead == false && bBoss == false)
		return;

	if (bDebugMode == false)
	{
		PlayerDelete();
		StartGame();
	}
	else
	{
		int temp{};
		while (bEndDebug == false && temp != 5)
		{
			cout << "디버깅 모드에선 죽지 않습니다" << endl;
			bPlayerDead = false;
			bBoss = false;
			player->addHealth(player->getMaxHealth());
			Play(&temp);
		}
	}
}

void GameMGR::PlayerDelete()
{
	player->DeleteInstance();
	player = nullptr;
}

void GameMGR::PrintDebug()
{
	if (bDebugMode == false)
		return;
	
	cout << "-----Debuging Mode-----" << endl;
	cout << "종료하시려면 9를 누르세요" << endl;
	cout << "보스로 바로 가시려면 0을 누르세요" << endl;
}

void GameMGR::ExitGame(int index)
{
	if (bDebugMode == true && index == 9)
	{
		cout << "강제 종료" << endl;
		exit(1);
	}
}

void GameMGR::EndGame()
{
	system("cls");
	cout << "게임을 종료합니다..." << endl;
	cout << "다음에 다시 만나요, 모험가님." << endl;
	cout << "(게임종료)" << endl;
	Sleep(700);
}

void GameMGR::GoFromDebugModeToBoss()
{
	if(bDebugMode == false && player != nullptr)
		return;
	while (player->getLevel() != 10)
	{
		player->addExperience(100.0f);
		player->checkLevelUp();
	}
	player->addGold(1000);
	player->addAttack(1000);
}
