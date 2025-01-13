#pragma once

#include "map.h"
#include "player.h"
using namespace std;

class woodMap : public Map {
public:
	woodMap(Player*, int, int, char, char, char, char);
	void printMap() override;   //¯x°}x ¯x°}y ª±®ax ª±®ay
	void setTarget(char) override;


private:
	int woodGrid[16][64];
};