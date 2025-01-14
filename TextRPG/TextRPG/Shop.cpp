#include "Shop.h"
#include <iostream>
#include "Item.h"
#include "Character.h"
using namespace std;

void Shop::displayItems()
{
	cout<<"============== 상점 =============="<<endl;
	cout<<"----------------------------------"<<endl;
	for (auto& item : avaliableItems)
	{
		int minusPrice = item->getPrice() * sellPriceRatio;
		int sellPrice = item->getPrice() - minusPrice;
		cout << item->getName() << " | 구매가 : " << item->getPrice() << "Gold | 판매가 : " << sellPrice << endl;
	}
	cout<<"----------------------------------"<<endl;
}

void Shop::buyItem(int index, Character* player)
{
	player->addGold(-(avaliableItems[index]->getPrice()));
	player->pushItem(avaliableItems[index]);
	cout << avaliableItems[index]->getPrice() << " Gold를 사용하여" << avaliableItems[index]->getName() << "을 구매했다!" << endl;
}

void Shop::sellItem(int index, Character* player)
{
	for (auto& item : avaliableItems)
	{
		if (item->getItemIdx() == index) 
		{
			int minusPrice = item->getPrice() * sellPriceRatio;
			int sellPrice = item->getPrice() - minusPrice;
			player->addGold(sellPrice);
			cout << item->getName() << "을(를) 판매하여 " << sellPrice<<" Gold를 얻었다!" << endl;
			player->popItemByType(index); 
			break;
		}
	}
}
