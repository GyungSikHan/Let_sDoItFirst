#include "Shop.h"
#include <iostream>
#include "Item.h"
using namespace std;

void Shop::displayItems()
{
	cout << "상점에 오신 것을 환영합니다!" <<endl;
	cout << "구매 가능한 아이템 :" <<endl;
	for (auto& item : avaliableItems)
	{
		cout << item->getItemIdx() << ". " << item->getName() << " : " << item->getPrice() << " 골드" << endl;
	}
}

void Shop::buyItem(int index/*, Character* player*/)
{
	// TODO: 플레이어 골드 감소
	//player->gold -= avaliableItems[index].getPrice();
	// TODO: 플레이어 인벤토리에 아이템 추가
	//player->inventory.push_back(avaliableItems[index]);
	cout << avaliableItems[index]->getName() << "을 구매했습니다!"<< endl;
}

void Shop::sellItem(int index/*, Character* player*/)
{
	// TODO: 플레이어 골드 증가
	//player->gold += avaliableItems[index].getPrice();
	// 플레이어 인벤토리에 아이템 제거
	// Item* removeItem = nullptr;
	// for(auto& item : player->inventory)
	// {
	//		if(item.getItemIdx == index) {
	//			cout << removeItem->getName() << "을 판매했습니다!" << endl;
	//			TODO: 플레이어 인벤토리에서(vector) 아이템 제거
	//		}
	// }
	//
}
