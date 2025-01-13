// Battle.cpp
#include "battle.h"
#include "goblin.h"
#include "boss.h"
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

// 構造函數
Battle::Battle(Player* p, Monster* m)
    : player(p), enemy(m), turnCount(0), battleEndByEscape(false),
    playerAttemptedDodge(false), playerDodgeSuccess(false)
{
}

//清屏
void Battle::clearScreen() {
    //system("clear");
    system("cls");  // Windows 使用者請將上面註解掉，並將此行取消註解
}

//顯示我方 & 敵方資訊
void Battle::displayUI() {
    clearScreen();

    Boss* b = dynamic_cast<Boss*>(enemy);  // 判斷敵人是否為 Boss

    cout << left << "【我方: Player】" << setw(18) << " "
        << "【敵人資訊】" << endl;

    // 第一列：HP
    cout << left << "HP : " << setw(5) << player->getHp()
        << setw(25) << " "
        << "HP : " << enemy->getHealth() << endl;

    // 第二列：MP / SuperATK
    cout << left << "MP : " << setw(5) << player->getMp()
        << setw(25) << " "
        << "SuperATK: " << (b ? b->getSuperAttack() : 0) << endl;

    // 第三列：PhysicalATK
    cout << "PhysicalATK : " << player->getPscAtk() << endl;

    // 第四列：MagicATK
    cout << "MagicalATK : " << player->getMgAtk() << endl;

    // **第五列：顯示怒氣值 (Anger)**
    cout << "Anger : " << player->getAnger() << endl;

    cout << "HP藥水 : " << player->getHpPotion() << endl;
    cout << "MP藥水 : " << player->getMpPotion() << endl << endl;


    // 指令選單
    cout << "======= 指令選擇 =======" << endl;
    cout << "1) 普通攻擊" << endl;
    cout << "2) 特殊攻擊 (消耗20魔力值)" << endl;
    cout << "3) 終極攻擊 (消耗30魔力值 100怒氣值)" << endl;
    cout << "4) 閃避" << endl;
    cout << "5) 嘗試逃跑" << endl;
    cout << "6) 使用HP藥水(回復100血量)" << endl;
    cout << "7) 使用MP藥水(回復80魔力)" << endl;
    cout << "========================" << endl;
    cout << "回合: " << turnCount << endl << endl;
}

//戰鬥開始 (map呼叫此函數以開始戰鬥)
void Battle::startBattle() {
    while (!isBattleEnd() && !battleEndByEscape) {
        turnCount++;
        displayUI();

        playerTurn();
        if (isBattleEnd() || battleEndByEscape) break;
        system("cls");//玩家操作完後就清屏並更新最新資訊
        displayUI();

        enemyTurn();
    }

    cout << "===== 戰鬥結束！ =====" << endl;
    if (battleEndByEscape) {
        cout << "你成功脫離戰鬥！" << endl;
    }
    else if (player->getHp() <= 0 && enemy->getHealth() <= 0) {
        cout << "雙方同歸於盡..." << endl;
        cout << "GAME OVER..." << endl;
        exit(0);
    }
    else if (player->getHp() <= 0) {
        cout << "我方戰士體力已耗盡..."/*請到主城商店購買恢復魔藥!*/ << endl;
        cout << "GAME OVER..." << endl;
        exit(0);
    }
    else if (enemy->getHealth() <= 0) {
        cout << "敵人被擊敗！獲得 " << enemy->getCoin() << " 金幣！" << endl;
        int coin = enemy->getCoin() + player->getMoney();
        player->setMoney(coin);
    }
    cout << "======================" << endl;
    system("pause");
}

void Battle::playerTurn() {
    if (player->getHp() <= 0) return;

    int choice = 0;
    while (true) {
        cout << "請輸入指令 (1~7): ";
        cin >> choice;

        //非法輸入判別
        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "輸入錯誤！請輸入 1~7" << endl;
            continue;
        }
        if (choice < 1 || choice > 7) {
            cout << "無效的指令，請再輸入 1~7" << endl;
        }
        else {
            break;
        }
    }

    int damage = 0;
    switch (choice) {
    case 1: {
        // 普通攻擊
        damage = player->normalAtk();
        cout << "[Player] 施放普通攻擊！" << endl;
        cout << "對敵人造成 " << damage << " 點傷害!" << endl;
        enemy->setHealth(enemy->getHealth() - damage);
        break;
    }
    case 2: {
        // 特殊攻擊
        if (player->getMp() < 20) {
            cout << "MP不足，無法施放特殊攻擊!" << endl;
            damage = 0;
        }
        else {
            player->setMp(player->getMp() - 20);
            damage = player->specialAtk();
            cout << "[Player] 施放特殊攻擊！" << endl;
        }

        cout << "對敵人造成 " << damage << " 點傷害!" << endl;
        enemy->setHealth(enemy->getHealth() - damage);
        break;
    }
    case 3: {
        // 終極攻擊
        if (player->getMp() < 30) {
            cout << "MP不足，無法施放終極攻擊!" << endl;
            damage = 0;
        }
        else if (player->getAnger() < 100) {
            cout << "怒氣未滿(需100)，無法施放終極攻擊!" << endl;
            damage = 0;
        }
        else {
            player->setMp(player->getMp() - 30);
            player->setAnger(0);
            damage = player->superAtk();
            cout << "[Player] 施放終極攻擊！" << endl;
        }

        cout << "對敵人造成 " << damage << " 點傷害!" << endl;
        enemy->setHealth(enemy->getHealth() - damage);
        break;
    }
    case 4: {
        // 嘗試閃避
        cout << "你嘗試閃避..." << endl;
        playerAttemptedDodge = true; // 標記玩家嘗試閃避
        playerDodgeSuccess = player->tryDodge();
        if (playerDodgeSuccess) {
            cout << "成功閃避！" << endl;
        }
        else {
            cout << "閃避失敗..." << endl;
        }
        break;
    }
    case 5: {
        // 嘗試逃跑
        bool escapeSuccess = player->tryEscape();
        if (escapeSuccess) {
            cout << "你成功脫離戰鬥！" << endl;
            battleEndByEscape = true;
            return;
        }
        else {
            cout << "逃跑失敗..." << endl;
        }
        break;
    }
    case 6: {
        if (player->getHpPotion() <= 0) {
            cout << "藥水數量不足，無法使用，請回主城商店購買 !" << endl;
        }
        else {
            player->setHpPotion(player->getHpPotion() - 1);
            player->setHp(player->getHp() + 100);
            cout << "已使用藥水，血量回復 100 !" << endl;
        }
        break;
    }
    case 7: {
        if (player->getMpPotion() <= 0) {
            cout << "藥水數量不足，無法使用，請回主城商店購買 !" << endl;
        }
        else {
            player->setMpPotion(player->getMpPotion() - 1);
            player->setMp(player->getMp() + 80);
            cout << "已使用藥水，魔力回復 80 !" << endl;
        }
        break;
    }
    }

    cout << "(按 Enter 繼續...)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Battle::enemyTurn() {
    if (enemy->getHealth() <= 0) return;

    Boss* b = dynamic_cast<Boss*>(enemy);
    int dmg = 0;

    if (b) {
        // Boss 每 3 回合放大招
        if (turnCount % 3 == 0) {
            dmg = b->getSuperAttack();
            cout << "[Boss] 施放大招！造成 " << dmg << " 點傷害！" << endl;
        }
        else {
            dmg = b->getAttack();
            cout << "[Boss] 進行普通攻擊，造成 " << dmg << " 點傷害！" << endl;
        }
    }
    else {
        // Goblin 攻擊
        dmg = enemy->getAttack();
        cout << "[Goblin] 攻擊，造成 " << dmg << " 點傷害！" << endl;
    }

    // 檢查玩家是否嘗試閃避
    if (playerAttemptedDodge) {
        if (!playerDodgeSuccess) {
            // 閃避失敗，計算實際傷害
            int adjustedDamage = dmg * (1 - static_cast<int>(player->getDef() * 0.01)); //if def 60  0.6*dmg
            if (adjustedDamage < 0) adjustedDamage = 0; // 確保傷害不為負數
            cout << "由於閃避失敗，受到 " << adjustedDamage << " 點傷害！" << endl;
            player->setHp(player->getHp() - adjustedDamage);
        }
        else {
            // 閃避成功，不受到傷害
            cout << "由於成功閃避，不受到傷害！" << endl;
        }
    }
    else {
        // 沒有嘗試閃避，正常受到傷害
        player->setHp(player->getHp() - dmg);
    }

    cout << "(按 Enter 繼續...)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    // 重置閃避狀態
    playerAttemptedDodge = false;
    playerDodgeSuccess = false;
}

bool Battle::isBattleEnd() {
    return (player->getHp() <= 0 || enemy->getHealth() <= 0);
}
