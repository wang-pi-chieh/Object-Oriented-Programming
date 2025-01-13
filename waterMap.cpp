#include <iostream>
#include "player.h"
#include "waterMap.h"
#include "goblin.h"
#include "boss.h"
#include "battle.h"
using namespace std;

waterMap::waterMap(Player* PLayer, int Iniplayx, int Iniplayy, char obsta, char debuff, char sid, char inter)
    :Map(PLayer, Iniplayx, Iniplayy, obsta, debuff, sid, inter){
    srand(static_cast<unsigned>(std::time(nullptr)));
    int M[16][64] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 1},
        {1, 0, 0, 2, 2, 2, 0, 6, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 6, 0, 0, 0, 2, 1},
        {1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 6, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1},
        {1, 0, 6, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 6, 0, 0, 2, 2, 2, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };


    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 64; ++j) {
            /*if (M[i][j] == 'r') {
                int random = rand() % 2;

                if (random == 0) {  //遇到0的時候，是空格，是未走到的安全地帶
                    waterGrid[i][j] == 0;
                    cout << " ";
                }
                else if (random == 1) {
                    waterGrid[i][j] = 6;
                    cout << "\033[36mM\033[0m";
                }
            }
            else */waterGrid[i][j] = M[i][j];
        }
    }
    
}

void waterMap::printMap() {
    for (int i = 0; i < 16; i++) { //i row
        for (int j = 0; j < 64; j++) { //j column
            if (i == playerAt_X && j == playerAt_Y) {  //玩家位置
                cout << "\033[35mP\033[0m";
            }
            
            else if (waterGrid[i][j] == 1) {  //遇到1的時候，是side，是不可走地帶
                cout << getSide();

            }
            else if (waterGrid[i][j] == 2) {  //遇到2的時候，是obstacle，是不可走地帶
                cout << "\033[34mv\033[0m";
            }
            else if (waterGrid[i][j] == 3) {   //遇到3的時候，是interact，是可走且能互動地帶
                cout << getInter();
            }
            else if (waterGrid[i][j] == 4) {   //遇到4的時候，是debuffFloor，是可走且會扣血地帶
                cout << getDebuffFloor();
            }
            else if (waterGrid[i][j] == 0) {  //遇到0的時候，是空格，是未走到的安全地帶
                cout << " ";
            }
            else if (waterGrid[i][j] == 5) {  //遇到5的時候，是boss
                cout << "\033[46mB\033[0m";
            }
            else if (waterGrid[i][j] == 6) {  //遇到6的時候，是goblin
                cout << "\033[36mM\033[0m";
            }
        }
        cout << endl;
    }
}


void waterMap::setTarget(char direction) {

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
    if (waterGrid[test_X][test_Y] == 2 || waterGrid[test_X][test_Y] == 1) {

    }
    else if (waterGrid[test_X][test_Y] == 4) {
        //扣血指令
        cout << "踩到水窪摔倒，扣 1 滴血！" << endl;
        int nowHP = player->getHp();
        player->setHp(nowHP - 1);
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (waterGrid[test_X][test_Y] == 3) {
        //互動指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (waterGrid[test_X][test_Y] == 5) {
        //system("cls");
        Boss boss;
        Monster* enemy = &boss;

        // 假設這裡初始化一個 boss
        Battle battle(player, enemy); // 正確構造 Battle 實例
        battle.startBattle();
    }
    else if (waterGrid[test_X][test_Y] == 6) {
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