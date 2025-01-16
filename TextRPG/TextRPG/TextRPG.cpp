#include <iostream>
#include "GameMGR.h"

int main()
{
	srand(time(nullptr));
  GameMGR::Create();
  GameMGR::GetInstance()->StartGame(true);

}
