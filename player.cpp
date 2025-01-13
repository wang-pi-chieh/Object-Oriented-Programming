#include "player.h"
/*#include"boss.h"
#include"goblin.h"*/
#include <cstdlib>  // rand(), srand()
#include <ctime>
using namespace std;

// 預設建構子
Player::Player()
    : hp(0), mp(0), anger(0),
    Def(0),
    pscAtk(0), mgAtk(0),
    dodgeRate(0.5f), escapeRate(0.7f),
    money(0),hpPotion(0),mpPotion(0)
{
    srand(static_cast<unsigned>(time(nullptr)));/*設定種子值，否則每次執行程式時生成的隨機序列是相同的
    使用time()函數，以當前時間作為種子。time() 返回的是 time_t 型別，通常是整數。將其轉換為無符號整數以匹配 srand() 的參數要求。*/
}

// 含參數建構子
Player::Player(int h, int m, int a,
    int d,
    int pa, int ma,
    float dr, float er, int mon,int hP,int mP)
    : hp(h), mp(m), anger(a),
    Def(d),
    pscAtk(pa), mgAtk(ma),
    dodgeRate(dr), escapeRate(er),
    money(mon),hpPotion(hP),mpPotion(mP)

{
}

// ====== Setter ======
void Player::setHp(int val) { hp = val; }
void Player::setMp(int val) { mp = val; }
void Player::setAnger(int val) { anger = val; }
void Player::setDef(int val) { Def = val; }
void Player::setPscAtk(int val) { pscAtk = val; }
void Player::setMgAtk(int val) { mgAtk = val; }
void Player::setDodgeRate(float val) { dodgeRate = val; }
void Player::setEscapeRate(float val) { escapeRate = val; }
void Player::setMoney(int val) { money = val; }
void Player::setHpPotion(int val) { hpPotion = val; }
void Player::setMpPotion(int val) { mpPotion = val; }

// ====== Getter ======
int   Player::getHp()        const { return hp; }
int   Player::getMp()        const { return mp; }
int   Player::getAnger()     const { return anger; }
int   Player::getDef()       const { return Def; }
int   Player::getPscAtk()    const { return pscAtk; }
int   Player::getMgAtk()     const { return mgAtk; }
float Player::getDodgeRate() const { return dodgeRate; }
float Player::getEscapeRate()const { return escapeRate; }
int   Player::getMoney()     const { return money; }
int   Player::getHpPotion()     const { return hpPotion; }
int   Player::getMpPotion()     const { return mpPotion; }

// ====== 攻擊動作 ======
int Player::normalAtk() {
    // 基底類別預設行為，可由子類別覆寫
    cout << "[Player] Normal Attack!" << endl;
    return pscAtk;
}

int Player::specialAtk() {
    cout << "[Player] Special Attack!" << endl;
    return pscAtk + mgAtk;
}

int Player::superAtk() {
    cout << "[Player] Super Attack!" << endl;
    return (pscAtk + mgAtk) * 2;
}

// ====== 嘗試閃避 / 嘗試逃跑 ======
bool Player::tryDodge() {
    
    float randomValue = static_cast<float>(rand()) / RAND_MAX;//取隨機0~1的float
    return (randomValue < dodgeRate);//如果取的隨機數小於躲避機率 回傳1(成功)
}

bool Player::tryEscape() {
    
    
    float randomValue = static_cast<float>(rand()) / RAND_MAX;
    return (randomValue < escapeRate);
}


void Player::print() {
    cout << "生命值: " << getHp() << "  魔法值: " << getMp() << "  怒氣值: " << getAnger()
        << "  防禦值: " << getDef() << "  物攻值: " << getPscAtk() << "  魔攻值: " << getMgAtk()
        << "  躲避機率: " << getDodgeRate() << "  逃跑機率: " << getEscapeRate() << endl;
}
