#pragma once

#include "map.h"
#include "player.h"
using namespace std;

class metalMap : public Map {
public:
	metalMap(Player*, int, int, char, char, char, char);
	void printMap() override;   //¯x°}x ¯x°}y ª±®ax ª±®ay
	void setTarget(char) override;


private:
	int metalGrid[16][64];
};