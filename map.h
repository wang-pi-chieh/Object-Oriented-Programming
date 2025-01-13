#pragma once
#include "player.h"

using namespace std;
class Map {
public:
	Map(Player*, int, int, char, char, char, char);//玩家初始x 玩家初始y 障礙模樣 負面模樣 邊界模樣 互動模樣
	virtual void printMap();//矩陣x 矩陣y 玩家x 玩家y
	virtual void setMapPlace(int, int);//玩家x 玩家y
	virtual void setTarget(char); //方向(wasd)
	void setObstacle(char);//建立障礙樣式&定義顏色
	void setDebuffFloor(char);
	void setSide(char);
	void setInter(char);

	char getObstacle();
	char getDebuffFloor();
	char getSide();
	char getInter();

protected:
	Player* player;
	int wanted_XOnMap;
	int wanted_YOnMap;
	int playerAt_X;
	int playerAt_Y;
	int m[16][64];
	char obstacle;
	char debuffFloor;
	char side;
	char interact;
};
