#ifndef BOSS_H
#define BOSS_H

#include "monster.h"

class Boss : public Monster {
public:
    Boss();                           // 建構函數
    int getHealth() const override;   // 回傳血量
    int getAttack() const override;   // 回傳攻擊力
    int getSuperAttack() const override;  // 回傳大招
    int getCoin() const override;     // 回傳金幣
};

#endif