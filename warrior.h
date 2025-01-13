#pragma once
#include "player.h"

class Warrior : public Player {
public:
    Warrior(); // 建構子

    // 覆寫攻擊方法
    int normalAtk() override;
    int specialAtk() override;
    int superAtk() override;
};