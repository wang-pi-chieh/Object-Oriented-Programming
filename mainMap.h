#pragma once

#include "map.h"
#include "player.h"
using namespace std;

class mainMap : public Map {
public:
	mainMap(Player*, int, int, char, char, char, char);
	void setMapPlace(int, int) override;   //ª±®ax ª±®ay
	void printMap() override;   //¯x°}x ¯x°}y ª±®ax ª±®ay
	void setTarget(char) override;
private:
	int mainGrid[16][32];
};