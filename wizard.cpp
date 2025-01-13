#include "wizard.h"
#include <iostream>
using namespace std;

Wizard::Wizard() {
    setHp(250);
    setMp(100);
    setAnger(0);
    setDef(50);
    setPscAtk(30);
    setMgAtk(70);
    setMoney(0);

    setDodgeRate(0.9f);//§Å®v¸}·Æ
    setEscapeRate(0.7f);
}

// ====== §ðÀ»¤èªk ======
int Wizard::normalAtk() {
    cout << "[Wizard] ´¶³q§ðÀ»(ÅXÅ]¼u)!" << endl;
    // «ã®ð += 10
    setAnger(getAnger() + 10);
    return static_cast<int>(getMgAtk() * 0.4+getPscAtk()*0.1);
}

int Wizard::specialAtk() {
    cout << "[Wizard] ¯S®í§ðÀ»(²b¤Æ³N)! ¦^´_¦å¶q:5% " << endl;
    // «ã®ð += 20
    setAnger(getAnger() + 20);
    setHp(getHp() + 270 * 0.05);
    // Å]§ð * 1
    return static_cast<int>(getMgAtk() * 0.8 + getPscAtk() * 0.2);
}

int Wizard::superAtk() {
    cout << "[Wizard] ²×·¥§ðÀ»(¯«¸t¼f§P)! ¦^´_¦å¶q:20%" << endl;
    // Å]§ð * 2
    setAnger(0);
    setHp(getHp() + 270 * 0.2);
    return static_cast<int>(getMgAtk() * 1.5+getPscAtk() * 0.5);
}