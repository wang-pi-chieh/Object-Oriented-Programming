#ifndef MONSTER_H
#define MONSTER_H

class Monster {
protected:
    int health;       // 血量
    int attack;       // 攻擊力
    int coin;         // 金幣
    int superattack;  // 大招

public:
    // 純虛擬函數，讓子類別覆寫
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual int getCoin() const = 0;
    virtual int getSuperAttack() const = 0;

    // 虛擬函數，允許覆寫
    virtual void setHealth(int h);

};

#endif