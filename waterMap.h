#pragma once

#include "map.h"
#include "player.h"
using namespace std;

class waterMap : public Map {
public:
	waterMap(Player*, int, int, char, char, char, char);
	void printMap() override;   //¯x°}x ¯x°}y ª±®ax ª±®ay
	void setTarget(char) override;

private:
	int waterGrid[16][64];
};