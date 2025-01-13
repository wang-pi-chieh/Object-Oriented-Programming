#include <iostream>
#include "player.h"
#include "metalMap.h"
#include "goblin.h"
#include "boss.h"
#include "battle.h"
using namespace std;

metalMap::metalMap(Player* PLayer, int Iniplayx, int Iniplayy, char obsta, char debuff, char sid, char inter)
    :Map(PLayer, Iniplayx, Iniplayy, obsta, debuff, sid, inter) {
    int M[16][64] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 1},
        {1, 0, 4, 0, 6, 0, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 6, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 1},
        {1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 1},
        {1, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

    };

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 64; ++j) {
            metalGrid[i][j] = M[i][j];
        }
    }
}

void metalMap::printMap() {
    for (int i = 0; i < 16; i++) { //i row
        for (int j = 0; j < 64; j++) { //j column
            if (i == playerAt_X && j == playerAt_Y) {  //玩家位置
                cout << "\033[35mP\033[0m";

            }
            else if (metalGrid[i][j] == 1) {  //遇到1的時候，是side，是不可走地帶
                cout << getSide();

            }
            else if (metalGrid[i][j] == 2) {  //遇到2的時候，是obstacle，是不可走地帶
                cout << getObstacle();
            }
            else if (metalGrid[i][j] == 3) {   //遇到3的時候，是interact，是可走且能互動地帶
                cout << getInter();
            }
            else if (metalGrid[i][j] == 4) {   //遇到4的時候，是debuffFloor，是可走且會扣血地帶
                cout << "\033[38;5;220m^\033[0m";
            }
            else if (metalGrid[i][j] == 5) {  //遇到5的時候，是boss
                cout << "\033[48;5;130mB\033[0m";
            }
            else if (metalGrid[i][j] == 6) {  //遇到6的時候，是goblin
                cout << "\033[38;5;208mM\033[0m";
            }
            else if (metalGrid[i][j] == 0) {  //遇到0的時候，是空格，是未走到的安全地帶
                cout << " ";
            }
        }
        cout << endl;
    }
}


void metalMap::setTarget(char direction) {

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
    if (metalGrid[test_X][test_Y] == 2 || metalGrid[test_X][test_Y] == 1) {
        //cout << "你碰到了障礙物，無法通過！" << endl;
    }
    else if (metalGrid[test_X][test_Y] == 4) {
        //扣血指令
        cout << "踩到尖刺，扣 1 滴血！" << endl;
        int nowHP = player->getHp();
        player->setHp(nowHP - 1);
        if (player->getHp() <= 0) {
            cout << "\n我方戰士體力已耗盡..."/*請到主城商店購買恢復魔藥!*/ << endl;
            cout << "GAME OVER..." << endl;
            exit(0);
        }
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (metalGrid[test_X][test_Y] == 3) {
        //互動指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (metalGrid[test_X][test_Y] == 5) {
        //system("cls");
        Boss boss;
        Monster* enemy = &boss;

        // 假設這裡初始化一個 boss
        Battle battle(player, enemy); // 正確構造 Battle 實例
        battle.startBattle();
    }
    else if (metalGrid[test_X][test_Y] == 6) {
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