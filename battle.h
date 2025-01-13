// Battle.h
#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"
#include "monster.h"

class Battle {
private:
    Player* player;
    Monster* enemy;
    int turnCount;
    bool battleEndByEscape;

    // 新增的成員變量
    bool playerAttemptedDodge;
    bool playerDodgeSuccess;

public:
    Battle(Player* p, Monster* m);
    void startBattle();
    void displayUI();
    void playerTurn();
    void enemyTurn();
    bool isBattleEnd();
    void clearScreen();
};

#endif // BATTLE_H