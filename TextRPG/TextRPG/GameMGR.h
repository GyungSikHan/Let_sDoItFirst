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
    void Battle(Character* player);
    void VisitShop(Character* player);
    void DisplayInventory(Character* player);

public:
    void StartGame();
    void InitCharacter();
    void PrintCharacterInfo();
    void Play();
    bool IsMonsterDead(Monster* monster);
    bool IsPlayerDead();

private:
    static GameMGR* instance;
    class Shop* shop;

    bool bPlayerDead{};
};
