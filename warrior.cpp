#include "warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior() {
    // 設定各項屬性
    setHp(300);
    setMp(50);
    setAnger(0);
    setDef(70);
    setPscAtk(70);
    setMgAtk(25);
    setMoney(0);
}

// ====== 攻擊方法 ======
int Warrior::normalAtk() {
    cout << "[Warrior] 普通攻擊!(重斬)" << endl;
    // 怒氣 += 20
    setAnger(getAnger() + 20);
    // 物攻 * 0.5
    return static_cast<int>(getPscAtk() * 0.5);//顯式類型轉換運算符，用於在編譯期進行類型轉換。static_cast<目標類型>(要轉換的表達式)
}

int Warrior::specialAtk() {
    cout << "[Warrior] 特殊攻擊!(狂怒斬)" << endl;
    // 怒氣 += 40
    setAnger(getAnger() + 40);
    // 物攻 * 1
    return static_cast<int>(getPscAtk() * 1);
}

int Warrior::superAtk() {
    cout << "[Warrior] 終極攻擊!(龍炎斬)" << endl;
    // 用完怒氣歸零
    setAnger(0);
    // 物攻 * 2
    return static_cast<int>(getPscAtk() * 2);
}