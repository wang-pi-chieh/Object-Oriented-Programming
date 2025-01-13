#include "goblin.h"
#include <cstdlib>
#include <ctime>

// Goblin 的建構函數
Goblin::Goblin() {
    health = 100;  // 血量
    attack = 20;  // 攻擊力//捨棄 用隨機值
    coin = 100;   // 金幣
    srand(static_cast<unsigned>(std::time(nullptr)));
}

// 回傳 Goblin 的血量
int Goblin::getHealth() const {
    return health;
}

// 回傳 Goblin 的攻擊力
int Goblin::getAttack() const {
    return 15 + std::rand() % 6; //15-20取隨機
    //return attack;
}

// 回傳 Goblin 的金幣數量
int Goblin::getCoin() const {
    return coin;
}

int Goblin::getSuperAttack() const {
    return superattack;
}