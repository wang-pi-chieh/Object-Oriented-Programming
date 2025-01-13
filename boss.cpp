#include "boss.h"
#include <cstdlib>
#include <ctime>
// Boss 的建構函數
Boss::Boss() {
    health = 800;       // 血量
    attack = 20;        // 攻擊力//捨棄 用隨機值
    superattack = attack * 2;  // 大招
    coin = 800;         // 金幣
    srand(static_cast<unsigned>(std::time(nullptr)));
}

// 回傳 Boss 的血量
int Boss::getHealth() const {
    return health;
}

// 回傳 Boss 的攻擊力
int Boss::getAttack() const {
    //return attack;
    
    return 20 + rand() % 11; //20-30取隨機
}

// 回傳 Boss 的大招
int Boss::getSuperAttack() const {
    return superattack;
}

// 回傳 Boss 的金幣數量
int Boss::getCoin() const {
    return coin;
}