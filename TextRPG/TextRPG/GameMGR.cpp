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
    while (bMonsterDead == false && bPlayerDead == false && bRun == false)
    {
        //TODO Plyaer나 monster 죽었는지 판단하는 함수 추가해넣기
		cout << "1. 공격 2. 인벤토리 3. 도망가기 ";
    	cin >> index;
	    switch (index)
	    {
	    case 1:
            //0이면 character, 1이면 monster
            Attack(monster, 0);
	    	break;
	    case 2:
            //TODO 
	        DisplayInventory();
	        //TODO 아이템 선택 후 사용
			break;
	    case 3://TODO 뺼수도 있음
            bRun = true;
	        cout << player->getName() << "이 도망갑니다" << endl;
	        break;
	    }
        if(index != 3)
	        Attack(monster, 1);
        
    }
}

void GameMGR::VisitShop()
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
            //TODO 골드에 따라 구매 가능한지 판단
	        shop->buyItem(index, player);
            break;
        case 2:
            //TODO 아이템 있는지 판단 후 판매
            shop->sellItem(index, player);
            break;
        case 3:
            cout << "상점에서 나갑니다" << endl;
            break;
        }
    }

}

void GameMGR::DisplayInventory()
{
    //TODO player에서 구현 예정
    for (Item* item : player->getInventory())
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
        case 5://TODO 잡은 몬스터 갯수
            break;
        case 6:
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
       // player->takeDamage(monster->getAttack());
        cout << player->getName() << "이 공격당합니다!!" << endl;
        cout << "남은체력 : " << player->getHealth() << endl;
    }
}

bool GameMGR::IsMonsterDead(Monster* monster)
{
    //TODO monster에서 함수 구현예정
    return monster->getHealth() <= 0;
}

bool GameMGR::IsPlayerDead()
{
    //TODO player에서 함수 만들예정
    return player->getHealth() <= 0;
}
