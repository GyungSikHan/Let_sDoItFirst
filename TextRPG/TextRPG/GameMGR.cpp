#include "GameMGR.h"

#include <ppltasks.h>

#include "Goblin.h"
#include "Orc.h"
#include "Shop.h"
#include "Troll.h"

GameMGR* GameMGR::instance = nullptr;

GameMGR::GameMGR()
{
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
    int ran = (int)(rand() % 3);
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

void GameMGR::Battle(Character* player)
{
    Monster* monster{};
    //if (Character::getInstance()->getLevel() >= 10)
    //    monster = GenerateMonster();
    //else
    //    monster = GenerateMonster();

    if(monster == nullptr)
    {
        cout << "몬스터가 존재하지 않습니다!!" << endl;
	    return;
    }
    cout << monster->getName() << "이 등장했다!!!" << endl;

    //TODO 전투 및 결과
    bool bMonsterDead{};

	int index{};
    while (bMonsterDead == false && bPlayerDead == false)
    {
		cout << "1. 공격 2. 인벤토리 3. 도망가기 ";
    	cin >> index;
	    switch (index)
	    {
	    case 1: 
	        monster->takeDamage(Character::getInstance()->getAttack());
            bMonsterDead = IsMonsterDead(monster);
	    	break;
	    case 2:
	        DisplayInventory(Character::getInstance());
	        //TODO 아이템 선택 후 사용
			break;
	    case 3:
	        cout << Character::getInstance()->getName() << "이 도망갑니다" << endl;
	        break;
	    }

        if(index == 3)
        {
            cout << monster->getName() << "이 공격합니다!!" << endl;
            cout << monster->getAttack() << "의 데미지를 입었습니다!!!" << endl;
            //TODO 플레이어 데미지 입음
            bPlayerDead = IsPlayerDead();
        }
    }
}

void GameMGR::VisitShop(Character* player)
{
    
    shop->displayItems();

	int index{};
    while(index != 3)
    {
        cout << "1. 아이템 구매 2. 아이템 판매 3. 나가기";
        cin >> index;
        //TODO 아이템 살지 팔지 결정
        switch (index)
        {
        case 1:
	        shop->buyItem(index);
            break;
        case 2:
            //TODO 아이템 판매
            break;
        case 3:
            cout << "상점에서 나갑니다" << endl;
            break;
        }
    }

}

void GameMGR::DisplayInventory(Character* player)
{
    //character에 함수로 구현해도 될듯..?
    //vector<Item*> 반환하는 Get함수 필요
    for (Item* item : player->GetItems()
    {
        cout << item->getName() << "이 " << item->getItemIdx() << "개 있습니다" << endl;
    }
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
        case 1://TODO 게임시작
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
    Character::getInstance(name);
    //TODO  Player 체력, 레벨, 경험치, 공격력, 골드 셋팅
}

void GameMGR::PrintCharacterInfo()
{
    cout<<"------------ Player Info ------------"<<endl;
    cout<<"이름 : "<<Character::getInstance()->getName() <<endl;
    cout<<"Level : "<<Character::getInstance()->getLevel()<<endl;
    cout<<"HP : "<<Character::getInstance()->getHealth()<<"/"<<Character::getInstance()->getMaxHealth()<<endl;
    cout<<"Power : " << Character::getInstance()->getAttack()<<endl;
    //cout<<"EXP : "<<Character::getInstance().getexp()<<"/"<<Character::getInstance().getMaxExp<<endl;//추가 예정
    
    
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
                //Battle();
                break;
            case 2:
               // VisitShop();
                break;
            case 3:
                //PrintCharacterInfo();
                break;
            case 4:
                //DisplayInventory();
                break;
        case 5://TODO 잡은 몬스터 갯수
            break;
        case 6:
            cout << "게임을 종료합니다!!" << endl;
            break;
        }
    }
}

bool GameMGR::IsMonsterDead(Monster* monster)
{
    return monster->getHealth() <= 0;
}

bool GameMGR::IsPlayerDead()
{
    return Character::getInstance()->getHealth() <= 0;
}
