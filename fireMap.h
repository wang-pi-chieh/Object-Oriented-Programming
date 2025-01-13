#pragma once

#include "map.h"
#include "player.h"
using namespace std;

class fireMap : public Map {
public:
	fireMap(Player*, int, int, char, char, char, char);
	void printMap() override;   //¯x°}x ¯x°}y ª±®ax ª±®ay
	void setTarget(char) override;

private:
	int fireGrid[16][64];
};