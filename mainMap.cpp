#include <iostream>
#include "mainMap.h"
#include "metalMap.h"
#include "woodMap.h"
#include "waterMap.h"
#include "fireMap.h"
#include "player.h"
#include "shop.h"
#include <cstdio>
#include <conio.h>
using namespace std;

//主城建構子
mainMap::mainMap(Player* PLayer, int Iniplayx, int Iniplayy, char obsta, char debuff, char sid, char inter)
    :Map(PLayer, Iniplayx, Iniplayy, obsta, debuff, sid, inter) {
    int M[16][32] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,6},
        {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1},
        {7,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1},
        {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
        {1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
        {8,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,5},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            mainGrid[i][j] = M[i][j];
        }
    }
}

void mainMap::setMapPlace(int iniX, int iniY) {
    playerAt_X = 16;
    playerAt_Y = 16;
}

//列印地圖
void mainMap::printMap() {
    for (int i = 0; i < 14; i++) { //i row //有把i從16改為14 縮減空格行
        for (int j = 0; j < 32; j++) { //j column
            if (i == playerAt_X && j == playerAt_Y) {  //玩家位置
                cout << "\033[35mP\033[0m";

            }
            else if (mainGrid[i][j] == 1) {  //遇到1的時候，是side，是不可走地帶 
                cout << getSide();

            }
            else if (mainGrid[i][j] == 2) {  //遇到2的時候，是obstacle，是不可走地帶
                cout << getObstacle();
            }
            else if (mainGrid[i][j] == 3) {   //遇到3的時候，是interact，是商店
                cout << "S";
            }
            else if (mainGrid[i][j] == 4) {   //遇到4的時候，是debuffFloor，是可走且會扣血地帶
                cout << getDebuffFloor();
            }
            else if (mainGrid[i][j] == 0) {  //遇到0的時候，是空格，是未走到的安全地帶
                cout << " ";
            }
            else if (mainGrid[i][j] == 5) {
                cout << "\033[38;5;220mM\033[0m";      //金
            }
            else if (mainGrid[i][j] == 6) {
                cout << "\033[32mW\033[0m";            //木
            }
            else if (mainGrid[i][j] == 7) {
                cout << "\033[34mA\033[0m";            //水
            }
            else if (mainGrid[i][j] == 8) {
                cout << "\033[1;31mF\033[0m";          //火
            }
        }
        cout << endl;
    }
    cout << "控制說明: " << endl;
    cout << "  W: 上移 A: 左移 S: 下移 D: 右移" << endl;
    cout << "  =============================================" << endl;
    cout << "  地圖說明: 歡迎來到RPG遊戲，這裡是主城!" << endl;
    cout << "  當前血量: " << player->getHp();
    cout << "  當前魔力: " << player->getMp();
    cout << "  當前物攻: " << player->getPscAtk();
    cout << "  當前魔攻: " << player->getMgAtk();
    cout << "  當前擁有金錢: " << player->getMoney();
    cout << "  當前擁有生命藥水: " << player->getHpPotion();
    cout << "  當前擁有魔力藥水: " << player->getMpPotion() << endl;
    cout << "  \033[34mA\033[0m是\033[34m深海遺跡\033[0m" << endl;
    cout << "  \033[32mW\033[0m是\033[32m翠綠森林\033[0m" << endl;
    cout << "  \033[1;31mF\033[0m是\033[1;31m熔岩深淵\033[0m" << endl;
    cout << "  \033[38;5;220mM\033[0m是\033[38;5;220m金龍山脈\033[0m" << endl;
    cout << "  S是商店" << endl;
    cout << "  =============================================" << endl;
    cout << "  tips: 主線地圖中按下q結束遊戲\n" << endl;

}


void mainMap::setTarget(char direction) {

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
    if (mainGrid[test_X][test_Y] == 2 || mainGrid[test_X][test_Y] == 1) {
        //cout << "你碰到了障礙物，無法通過！" << endl;
    }
    else if (mainGrid[test_X][test_Y] == 4) {
        //扣血指令
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
    else if (mainGrid[test_X][test_Y] == 3) {
        //互動指令
        shop shop(player);//建置
        cout << "是否要進入\033[38;5;220m商店\033[0m" << endl;
        cout << "如果要，請輸入1，否則輸入0: ";
        int stop = 1;
        cin >> stop;
        if (stop) {
            system("cls");
            shop.printShop();
            cout << "請輸入購買品項1或2或3，或輸入q離開商店: \n";

            while (true) {
                char buy;
                buy = _getch();
                cin.clear();
                if (buy == '1') {
                    shop.hpPotion();
                    system("pause");
                    system("cls");
                    shop.printShop();
                }
                else if (buy == '2') {
                    shop.mpPotion();
                    system("pause");
                    system("cls");
                    shop.printShop();
                }
                else if (buy == '3') {
                    shop.upgrade();
                    system("pause");
                    system("cls");
                    shop.printShop();
                }
                // 判斷是否退出遊戲
                else if (buy == 'q' || buy == 'Q') {
                    cout << "離開商店!" << endl;
                    break;
                }
                else {
                    cout << "請輸入1~3!\n";
                }
            }

            system("pause");

        }
    }
    //金
    else if (mainGrid[test_X][test_Y] == 5) {
        metalMap METALMap(player, 1, 1, '#', '!', '*', '@');
        int stop = 1;
        cout << "是否要進入\033[38;5;220m金龍山脈\033[0m" << endl;
        cout << "如果要，請輸入1，否則輸入0: ";
        if (stop) {
            char command;
            system("cls");
            while (true) {
                system("cls");
                METALMap.printMap();
                cout << "  歡迎來到\033[38;5;220m金龍山脈\033[0m，請注意腳下\033[38;5;220m尖刺^\033[0m，踩到會扣血!\n";
                cout << "  當前剩餘血量: " << player->getHp();
                cout << "  當前剩餘魔力: " << player->getMp();
                cout << "  當前擁有金錢: " << player->getMoney() << endl;
                cout << "  當前擁有生命藥水: " << player->getHpPotion();
                cout << "  當前擁有魔力藥水: " << player->getMpPotion() << endl;
                cout << "  tips: 按下q回到主城\n" << endl;
                cout << "請輸入指令: ";
                cin.clear();
                command = _getch();

                // 判斷是否退出遊戲 (有用到嗎?
                if (command == 'q' || command == 'Q') {
                    cout << "遊戲結束!" << endl;
                    break;
                }
                // 移動玩家
                METALMap.setTarget(command);
                //要問玩家是否還要玩
            }
        }
    }
    //木
    else if (mainGrid[test_X][test_Y] == 6) {
        woodMap WOODMap(player, 1, 1, '#', 'F', '*', '@');
        int stop = 1;
        cout << "是否要進入\033[32m翠綠森林\033[0m" << endl;
        cout << "如果要，請輸入1，否則輸入0: ";
        cin >> stop;
        if (stop) {
            char command;
            system("cls");
            while (true) {
                system("cls");
                WOODMap.printMap();
                cout << "  歡迎來到\033[32m翠綠森林\033[0m\n";
                cout << "  當前剩餘血量: " << player->getHp();
                cout << "  當前剩餘魔力: " << player->getMp();
                cout << "  當前擁有金錢: " << player->getMoney() << endl;
                cout << "  當前擁有生命藥水: " << player->getHpPotion();
                cout << "  當前擁有魔力藥水: " << player->getMpPotion() << endl;
                cout << "  tips: 按下q回到主城\n" << endl;
                cout << "請輸入指令: ";
                cin.clear();
                command = _getch();

                // 判斷是否退出遊戲
                if (command == 'q' || command == 'Q') {
                    cout << "遊戲結束!" << endl;
                    break;
                }
                // 移動玩家
                WOODMap.setTarget(command);
                //要問玩家是否還要玩
            }
        }
    }
    //水
    else if (mainGrid[test_X][test_Y] == 7) {
        waterMap WATERMap(player, 1, 1, '#', '!', '*', '@');
        int stop = 1;
        cout << "是否要進入\033[34m深海遺跡\033[0m" << endl;
        cout << "如果要，請輸入1，否則輸入0: ";
        cin >> stop;
        if (stop) {
            char command;
            system("cls");
            while (true) {
                system("cls");
                WATERMap.printMap();
                cout << "  歡迎來到\033[34m深海遺跡\033[0m\n";
                cout << "  當前剩餘血量: " << player->getHp();
                cout << "  當前剩餘魔力: " << player->getMp();
                cout << "  當前擁有金錢: " << player->getMoney() << endl;
                cout << "  當前擁有生命藥水: " << player->getHpPotion();
                cout << "  當前擁有魔力藥水: " << player->getMpPotion() << endl;
                cout << "請輸入指令: ";
                cin.clear();
                command = _getch();

                // 判斷是否退出遊戲
                if (command == 'q' || command == 'Q') {
                    cout << "遊戲結束!" << endl;
                    break;
                }
                // 移動玩家
                WATERMap.setTarget(command);
                //要問玩家是否還要玩
            }
        }
    }
    //火
    else if (mainGrid[test_X][test_Y] == 8) {
        fireMap FIREMap(player, 1, 1, '#', '!', '*', '@');
        int stop = 1;

        cout << "是否要進入\033[1;31m熔岩深淵\033[0m" << endl;
        cout << "如果要，請輸入1，否則輸入0: ";
        cin >> stop;
        if (stop) {
            char command;
            system("cls");
            while (true) {
                system("cls");
                FIREMap.printMap();
                cout << "  歡迎來到\033[1;31m熔岩深淵\033[0m，請注意腳下\033[1;31m火球F\033[0m，踩到會扣血!\n";
                cout << "  當前剩餘血量: " << player->getHp();
                cout << "  當前剩餘魔力: " << player->getMp();
                cout << "  當前擁有金錢: " << player->getMoney() << endl;
                cout << "  當前擁有生命藥水: " << player->getHpPotion();
                cout << "  當前擁有魔力藥水: " << player->getMpPotion() << endl;
                cout << "  tips: 按下q回到主城\n" << endl;
                cout << "請輸入指令: ";
                cin.clear();
                command = _getch();

                // 判斷是否退出遊戲(有用到嗎?
                if (command == 'q' || command == 'Q') {
                    cout << "遊戲結束!" << endl;
                    break;
                }
                // 移動玩家
                FIREMap.setTarget(command);
                //要問玩家是否還要玩
            }
        }

    }

    else {
        playerAt_X = test_X;
        playerAt_Y = test_Y;
    }
}