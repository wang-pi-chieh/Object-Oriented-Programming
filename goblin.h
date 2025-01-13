#ifndef GOBLIN_H
#define GOBLIN_H

#include "monster.h"

class Goblin : public Monster {
public:
    Goblin();  // 建構函數
    int getHealth() const override;  // 回傳血量
    int getAttack() const override;  // 回傳攻擊力
    int getCoin() const override;    // 回傳金幣
    int getSuperAttack() const override;
};

#endif