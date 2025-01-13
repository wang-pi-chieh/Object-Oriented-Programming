#pragma once
#include "player.h"

class Wizard : public Player {
public:
    Wizard();

    int normalAtk() override;
    int specialAtk() override;
    int superAtk() override;
};