#include "tank.h"
#include <iostream>
using namespace std;

Tank::Tank() {
    setHp(400);
    setMp(60);
    setAnger(0);
    setDef(100);
    setPscAtk(40);
    setMgAtk(20);
    setMoney(0);
}

// ====== 攻擊方法 ======
int Tank::normalAtk() {
    cout << "[Tank] 普通攻擊(重擊)!" << endl;
    // 怒氣 += 10
    setAnger(getAnger() + 10);
    return static_cast<int>(getPscAtk() * 0.5);
}

int Tank::specialAtk() {
    cout << "[Tank] 特殊攻擊(盾牌衝撞)!" << endl;
    // 怒氣 += 20
    setAnger(getAnger() + 20);
    // 物理攻擊 * 1
    return static_cast<int>(getPscAtk() * 1);
}

int Tank::superAtk() {
    cout << "[Tank] 終極攻擊(碾壓)! 獲得可超量治療:50%" << endl;
    setAnger(0);
    // 物攻 * 2 
    setHp(getHp() + 400 * 0.5);
    return static_cast<int>(getPscAtk() * 2);
    
}