#include <iostream>
#include"Map.h"
using namespace std;
//0安全空格，1邊界，2障礙，3互動(商店)，4扣血

//map建構子
Map::Map(Player* PLayer, int Iniplayx, int Iniplayy, char obsta, char debuff, char sid, char inter) {
    m[15][64] = { 0 }; //m[16][64]顯示緩衝區溢位 先改為15
    setMapPlace(Iniplayx, Iniplayy);
    setObstacle(obsta);
    setDebuffFloor(debuff);
    setSide(sid);
    setInter(inter);
    player = PLayer;
}

//wasd行進，virtual提供給需要的地圖進行3互動與4扣血
void Map::setTarget(char direction) {
    char test_X = playerAt_X, test_Y = playerAt_Y;
    switch (direction) {
    case 'w': test_X--; break;
    case 'a': test_Y--; break;
    case 's': test_X++; break;
    case 'd': test_Y++; break;
    default:
        cout << "請輸入 w a s d !" << endl;
        return;
    }
    if (m[test_X][test_Y] == 2 || m[test_X][test_Y] == 1) {
        //cout << "你碰到了障礙物，無法通過！" << endl;
    }
    else if (m[test_X][test_Y] == 4) {
        //扣血指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (m[test_X][test_Y] == 3) {
        //互動指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else {
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
}

//列印地圖
void Map::printMap() {
    for (int i = 0; i < 16; i++) { //i row
        for (int j = 0; j < 64; j++) { //j column
            if (playerAt_X == i && playerAt_Y == j) {  //玩家位置
                cout << "\033[31mP\033[0m";
            }
            else if (m[i][j] == 1) {  //遇到1的時候，是side，是不可走地帶
                cout << getSide();
            }
            else if (m[i][j] == 2) {  //遇到2的時候，是obstacle，是不可走地帶
                cout << getObstacle();
            }
            else if (m[i][j] == 3) {   //遇到3的時候，是interact，是可走且能互動地帶
                cout << getInter();
            }
            else if (m[i][j] == 4) {   //遇到4的時候，是debuffFloor，是可走且會扣血地帶
                cout << getDebuffFloor();
            }
            else if (m[i][j] == 0) {  //遇到0的時候，是空格，是未走到的安全地帶
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Map::setMapPlace(int iniX, int iniY) {
    playerAt_X = iniX;
    playerAt_Y = iniY;
}

void Map::setObstacle(char Ob) {
    obstacle = Ob;
}
char Map::getObstacle() {
    return obstacle;
}

void Map::setDebuffFloor(char DF) {
    debuffFloor = DF;
}
char Map::getDebuffFloor() {
    return debuffFloor;
}

void Map::setSide(char si) {
    side = si;
}
char Map::getSide() {
    return side;
}

void Map::setInter(char itr) {
    interact = itr;
}
char Map::getInter() {
    return interact;
}