#include <iostream>
#include "player.h"
#include "woodMap.h"
#include "goblin.h"
#include "boss.h"
#include "battle.h"
using namespace std;

woodMap::woodMap(Player* PLayer, int Iniplayx, int Iniplayy, char obsta, char debuff, char sid, char inter)
    :Map(PLayer, Iniplayx, Iniplayy, obsta, debuff, sid, inter) {
    int M[16][64] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 2, 6, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 6, 1},
        {1, 0, 2, 2, 0, 2, 2, 2, 0, 2, 0, 2, 2, 0, 0, 0, 2, 0, 2, 0, 6, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0, 2, 0, 2, 0, 2, 2, 0, 0, 0, 1},
        {1, 0, 2, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 2, 2, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 0, 2, 0, 0, 2, 2, 2, 0, 2, 0, 2, 2, 2, 2, 0, 1},
        {1, 0, 2, 2, 0, 2, 2, 2, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 2, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 6, 2, 0, 2, 2, 2, 2, 0, 2, 2, 2, 0, 0, 2, 2, 0, 2, 0, 2, 0, 5, 0, 2, 6, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 6, 2, 0, 0, 2, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 0, 1},
        {1, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 2, 2, 0, 0, 2, 0, 0, 2, 2, 6, 0, 2, 0, 0, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 1},
        {1, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 0, 2, 0, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 64; ++j) {
            woodGrid[i][j] = M[i][j];
        }
    }
}

void woodMap::printMap() {
    for (int i = 0; i < 16; i++) { //i row
        for (int j = 0; j < 64; j++) { //j column
            if (i == playerAt_X && j == playerAt_Y) {  //玩家位置
                cout << "\033[35mP\033[0m";

            }
            else if (woodGrid[i][j] == 1) {  //遇到1的時候，是side，是不可走地帶
                cout << getSide();

            }
            else if (woodGrid[i][j] == 2) {  //遇到2的時候，是obstacle，是不可走地帶
                cout << "\033[32mT\033[0m";
            }
            else if (woodGrid[i][j] == 3) {   //遇到3的時候，是interact，是可走且能互動地帶
                cout << getInter();
            }
            else if (woodGrid[i][j] == 4) {   //遇到4的時候，是debuffFloor，是可走且會扣血地帶
                cout << getDebuffFloor();
            }
            else if (woodGrid[i][j] == 5) {  //遇到5的時候，是boss
                cout << "\033[48;5;23mB\033[0m";
            }
            else if (woodGrid[i][j] == 6) {  //遇到6的時候，是goblin
                cout << "\033[38;5;23mM\033[0m";
            }
            else if (woodGrid[i][j] == 0) {  //遇到0的時候，是空格，是未走到的安全地帶
                cout << " ";

            }
        }
        cout << endl;
    }
}


void woodMap::setTarget(char direction) {

    char test_X = playerAt_X, test_Y = playerAt_Y;
    switch (direction) {
    case 'w': test_X--; break;
    case 'a': test_Y--; break;
    case 's': test_X++; break;
    case 'd': test_Y++; break;
    default:
        cout << "現在不能做其他行動!" << endl;
        return;
    }
    if (woodGrid[test_X][test_Y] == 2 || woodGrid[test_X][test_Y] == 1) {
        //cout << "你碰到了障礙物，無法通過！" << endl;
    }
    else if (woodGrid[test_X][test_Y] == 4) {
        //扣血指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (woodGrid[test_X][test_Y] == 3) {
        //互動指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (woodGrid[test_X][test_Y] == 5) {
        //system("cls");
        Boss boss;
        Monster* enemy = &boss;

        // 假設這裡初始化一個 boss
        Battle battle(player, enemy); // 正確構造 Battle 實例
        battle.startBattle();
    }
    else if (woodGrid[test_X][test_Y] == 6) {
        //system("cls");
        Goblin goblin;
        Monster* enemy = &goblin;

        // 假設這裡初始化一個 boss
        Battle battle(player, enemy); // 正確構造 Battle 實例
        battle.startBattle();
    }
    else {
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
}