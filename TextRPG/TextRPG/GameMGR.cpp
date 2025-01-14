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
    return nullptr;
}

void GameMGR::Battle()
{
    Monster* monster{};
    if (player->getLevel() >= 10)
        monster = GenerateMonster(player->getLevel());
    else
        monster = GenerateMonster(player->getLevel());

    if(monster == nullptr)
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
	    cout << "-----" <<monster->getName() << "-----" << endl;
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
                    //GEt Exp
                    {
                        int tempExp = monster->dropEXP();
                        cout << tempExp << "를 획득했습니다!!!" << endl;
			            player->addExperience(tempExp);
	                    player->checkLevelUp();
                    }
                }
            }
	    	break;
	    case 2:
            //TODO  아이템 확인 후 사용
            do
            {
		        DisplayInventory();
	            cout << "어떤 아이템을 사용하시겠습니까?? ";
	            cin >> index2;
                if(player->getInventory()[index2-1]->getItemIdx() != 0)
	            {
		            cout << player->getInventory()[index2]->getName() << "을 사용합니다!!!" << endl;
			        player->useItem(index2-1);
                    break;
	            }
	            else
	            {
                    cout << "아이템이 없습니다!!  다시 선택해주세요!!!" << endl;
	            }
            }
            while (true);

	    	break;
	    case 3:
            bRun = true;
	        cout << player->getName() << "이 도망갑니다" << endl;
	        break;
	    }
        if(bRun == false && bMonsterDead == false)
        {
	        Attack(monster, 1);
            if(IsPlayerDead() == true)
				bPlayerDead = true;
        }
    }
}

void GameMGR::VisitShop()
{
    
    shop->displayItems();

	int index{};
	int index2{};
    while(index != 3)
    {
        cout << "1. 아이템 구매 2. 아이템 판매 3. 나가기";
        cin >> index;
        switch (index)
        {
        case 1:
            cout << "구매할 아이템 번호를 입력하세요: ";
            cin >> index2;
            
            if (player->getGold() < shop->getShopItems()[index2 - 1]->getPrice())
                cout << "금액이 부족합니다!!!" << endl;
            else
		        shop->buyItem(index2-1, player);
            break;

        case 2:
            cout << "판매할 아이템 번호를 입력하세요: ";
            DisplayInventory();
            cin >> index2;
        	//TODO 아이템 get 하는 함수
            //if (find(player->getInventory().begin(), player->getInventory().end(), shop->getShopItems()[index2-1]->getItemIdx()) == player->getInventory().end())
            //    cout << "해당 아이템이 없습니다!!!" << endl;
            //else
            ////TODO 파는 내용
	        //    shop->sellItem(index2, player);
	            
            
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

void GameMGR::StartGame()
{
    bool bEnd{};
    int temp{};
    cout<<"Text 세계에 오신걸 환영합니다."<<endl;
    cout<<"1. 게임 시작     2. 게임종료"<<endl;
    while(temp != 1 && temp != 2)
    {
        cin>>temp;
        if (temp != 1 && temp != 2)
            cout<<"잘못 입력했습니다. 다시 입력해주세요"<<endl;
    }

    switch (temp)
    {
        case 1:
            InitCharacter();
            Play();
            break;
        case 2:
            bEnd = true;
            break;
    }
}

void GameMGR::InitCharacter()
{
    string name{};
    cout<<"캐릭터의 이름을 지어주세요(10자 이내) :";
    cin>>name;
    if (name.size() > 10)
        name.erase(10, name.size());
    player = Character::getInstance();
    player->setName(name);
    player->displayInventory();
    //인벤토리 아이템 공간 만듦
    //shop->pushItem(player);
}

void GameMGR::PrintCharacterInfo()
{
    player->displayStatus();
}

void GameMGR::Play()
{
    int data{};
    while (data != 6 )
    {
	    cout<<"1. 전투 2. 상점 3. Player 정보 4. 인벤토리 5. 잡은 몬스터 수 보기 6. 게임 끝내기"<<endl;
	    cin >> data;
        switch(data)
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
