#include "shop.h"
#include <iostream>
#include<algorithm>
using namespace std;


shop::shop(Player* pLayer1) {
    player = pLayer1;
}

// HP藥水功能
void shop::hpPotion() {
    if (player->getMoney() >= 100) {
        cout << "[商店] 已購買 HP 藥水。\n";
        player->setMoney(player->getMoney() - 100);
        player->setHpPotion(player->getHpPotion() + 1);
    }
    else {
        cout << "[商店] 金幣不足，無法購買 HP 藥水。請按q離開商店\n";
    }
}
// MP藥水功能
void shop::mpPotion() {
    if (player->getMoney() >= 100) {
        cout << "[商店] 已購買 MP 藥水。\n";
        player->setMoney(player->getMoney() -100);
        player->setMpPotion(player->getMpPotion() + 1);
    }
    else {
        cout << "[商店] 金幣不足，無法購買 HP 藥水。請按q離開商店\n";
    }
}
void shop::upgrade() {
    if (player->getMoney() >= 300) {
        cout << "[商店] 血量提升20 魔力提升5 物攻提升5 魔攻提升5\n";
        player->setMoney(player->getMoney() - 300);
        player->setHp(player->getHp() + 20);
        player->setMp(player->getMp() + 5);
        player->setPscAtk(player->getPscAtk() + 5);
        player->setMgAtk(player->getMgAtk() + 5);
    }
    else {
        cout << "[商店] 金幣不足，無法購買升級。請按q離開商店\n";
    }
    
}

// 列印商店畫面
void shop::printShop() {
    cout << "              __________            " << endl;
    cout << "             /  shop   /            " << endl;
    cout << "            /__owner__/___         " << endl;
    cout << "             ^^^^^^^^^^             " << endl;
    cout << "  welcome >  |  O   < |             " << endl;
    cout << "              ________              " << endl;
    cout << "             |  |___| |    v        " << endl;
    cout << "             |        |    o        " << endl;
    cout << "____________________________________" << endl;
    cout << "                                    " << endl;
    cout << "====================== 商店 ======================\n";
    cout << "1. HP 藥水 (100 金幣): 每瓶藥水恢復100HP，輸入1購買\n";
    cout << "2. MP 藥水 (100 金幣): 每瓶藥水恢復80MP，輸入2購買\n";
    cout << "3. 全新升級！(300 金幣): 獲取升級 血量提升 魔力提升 基礎攻擊力提升，輸入3購買\n";
    cout << "=================================================\n";
    cout << "[當前玩家資訊] 金幣: " << player->getMoney() << "  生命值: " << player->getHp() << "  魔法值: " << player->getMp() ;
    cout << "  物攻值: " << player->getPscAtk();
    cout << "  魔攻值: " << player->getMgAtk() << "\n";
    cout << "[當前藥水資訊] 生命藥水: " << player->getHpPotion() << "  魔法藥水: " << player->getMpPotion() << "\n";
    cout << "=================================================\n";
}