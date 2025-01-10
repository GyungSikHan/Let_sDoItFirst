#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Character.h"

int main()
{
    Character *mycharacter = Character::getInstance("백구");
    mycharacter->getInstance("박구");
    mycharacter->displayStatus();
    mycharacter->levelUp();
    mycharacter->displayStatus();
}
