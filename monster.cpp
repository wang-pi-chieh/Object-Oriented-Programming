#include "monster.h"

// 設定血量，並檢查是否超過上限
void Monster::setHealth(int h) {
    health = h;
    // 你也可以在這裡加入邏輯，例如檢查上限或負值
    // if (health > maxHp) health = maxHp;
}


