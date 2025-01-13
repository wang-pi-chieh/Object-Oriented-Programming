#include "mage.h"
#include <iostream>
using namespace std;

Mage::Mage() {
    setHp(200);
    setMp(150);
    setAnger(0);
    setDef(30);
    setPscAtk(15);
    setMgAtk(100);
    setMoney(0);
}

// ====== 攻擊方法 ======
int Mage::normalAtk() {
    cout << "[Mage] 普通攻擊(魔法彈)!" << endl;
    // 怒氣 += 10
    setAnger(getAnger() + 10);
    // 使用魔力攻擊
    return static_cast<int>(getMgAtk() * 0.75);
}

int Mage::specialAtk() {
    cout << "[Mage] 特殊攻擊(大火球)!" << endl;
    // 怒氣 += 10
    setAnger(getAnger() + 20);
    // 魔力攻擊 * 1.25
    return static_cast<int>(getMgAtk() * 1.25);
}

int Mage::superAtk() {
    cout << "[Mage] 終極攻擊(流星雨)!" << endl;
    // 怒氣 = 0
    setAnger(0);
    return static_cast<int>(getMgAtk() * 2.5);
}