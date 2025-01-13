#pragma once
#include"player.h"


class shop {
public:
	shop(Player*);
	void hpPotion();
	void mpPotion();
	void upgrade();
	void printShop();
private:
	Player* player;
};