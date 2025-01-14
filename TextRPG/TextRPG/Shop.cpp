#include "Shop.h"
#include <iostream>
#include "Item.h"
#include "Character.h"
using namespace std;

void Shop::displayItems()
{
	cout << "상점에 오신 것을 환영합니다!" <<endl;
	cout << "구매 및 판매 가능한 아이템 :" <<endl;
	for (auto& item : avaliableItems)
	{
		int minusPrice = item->getPrice() * sellPriceRatio;
		int sellPrice = item->getPrice() - minusPrice;
		cout << item->getItemIdx() << ". " << item->getName() << " / 가격 : " << item->getPrice() << " 골드" <<" / 판매가 : " << sellPrice << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	player->setGold(player->getGold() - avaliableItems[index]->getPrice());
	player->pushItem(avaliableItems[index]);
	cout << avaliableItems[index]->getName() << "을 구매했습니다!"<< endl;
}

void Shop::sellItem(int index, Character* player)
{
	for (auto& item : avaliableItems)
	{
		if (item->getItemIdx() == index) {
			int minusPrice = item->getPrice() * sellPriceRatio;
			int sellPrice = item->getPrice() - minusPrice;
			player->setGold(player->getGold() + sellPrice);
			cout << item->getName() << "을 판매했습니다! / 현재 골드 : " << player->getGold() << endl;
			player->popItemByType(index); 
			break;
		}
	}
}
