#pragma once
#include "player.h"

class Mage : public Player {
public:
    Mage();

    int normalAtk() override;
    int specialAtk() override;
    int superAtk() override;
};