#pragma once
#include <memory>

#include "BossMonster.h"
#include "Character.h"
#include "Monster.h"

class GameMGR
{
private:
    GameMGR();
    GameMGR(const GameMGR&) = delete;
    GameMGR& operator = (const GameMGR&) = delete;

    ~GameMGR();
public:
     void Init();
    static void Create();
    static GameMGR* GetInstance();
    
    Monster* GenerateMonster(int level);
    BossMonster* GenerateBossMonster(int level);
    void Battle();
    void VisitShop();
    void DisplayInventory();

    void StartGame(bool bDebug = false);
private:
    void InitCharacter();
    void PrintCharacterInfo();
    void Play();

    void Attack(Monster* monster, int index);

    bool IsMonsterDead(Monster* monster);
    bool IsPlayerDead();

    void PlayerDead();
    void RestartGame();
private:
    Character* player;
	static GameMGR* instance;
    class Shop* shop;

    bool bPlayerDead{};

    bool bDebugMode{};
};
