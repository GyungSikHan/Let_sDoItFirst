#pragma once
#include <string>
using namespace std;

class Item 
{
public:
	virtual string getName() = 0;
	virtual int getPrice() = 0;
	virtual int getItemIdx() = 0;
	virtual void use(/*Character character*/) = 0;
};