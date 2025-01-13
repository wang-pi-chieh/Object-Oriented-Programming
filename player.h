#pragma once
#include <iostream>

class Player {
private:
    int hp;//生命值  
    int mp;//魔法值 
    int anger;//怒氣值 
    int Def;//物理防禦
    int pscAtk;//物理攻擊
    int mgAtk;//魔法攻擊   
    int money;//現金
    int hpPotion;//生命藥水
    int mpPotion;//魔力藥水

    float dodgeRate;//閃避機率    
    float escapeRate;//逃跑機率

public:
    // ====== 建構子 ======
    Player();
    Player(int h, int m, int a,
        int d,
        int pa, int ma,
        float dr, float er,
        int mon,int hP,int mP);

    // ====== Setter ======
    virtual void setHp(int val);
    void setMp(int val);
    void setAnger(int val);
    void setDef(int val);
    void setPscAtk(int val);
    void setMgAtk(int val);
    void setHpPotion(int val);
    void setMpPotion(int val);
    void setDodgeRate(float val);
    void setEscapeRate(float val);
    virtual void setMoney(int val);

    // ====== Getter ======
    virtual int getHp()  const;
    int   getMp()         const;
    int   getAnger()      const;
    int   getDef()        const;
    int   getPscAtk()     const;
    int   getMgAtk()      const;
    int   getHpPotion() const;
    int   getMpPotion() const;
    float getDodgeRate()  const;
    float getEscapeRate() const;
    virtual int getMoney()const;

    // ====== 攻擊動作 ======
    virtual int normalAtk();
    virtual int specialAtk();
    virtual int superAtk();

    // ====== 嘗試閃避 / 嘗試逃跑 ======
    bool tryDodge();
    bool tryEscape();

    void print();//印出基礎數值

};