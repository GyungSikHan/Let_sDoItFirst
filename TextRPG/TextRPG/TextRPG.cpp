#include <iostream>
#include "GameMGR.h"

int main()
{
  GameMGR::Create();
  GameMGR::GetInstance()->StartGame(true);

}
