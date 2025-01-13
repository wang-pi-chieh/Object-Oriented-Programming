#pragma once
#include "player.h"

class Tank : public Player {
public:
    Tank();

    int normalAtk() override;
    int specialAtk() override;
    int superAtk() override;
};