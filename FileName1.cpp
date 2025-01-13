#include<iostream>
#include"player.h"
#include"warrior.h"
#include"mage.h"
#include"tank.h"
#include"wizard.h"
#include "mainMap.h"
#include <cstdio>
#include <conio.h>

using namespace std;

void goMap(Player*);

int main() {
	Player* player = nullptr;
	bool go = true;
	Warrior warrior;
	Mage mage;
	Tank tank;
	Wizard wizard;
	while (go) {
		system("cls");
		cout << "RPG冒險開始，請選擇您的角色類型: \n1.戰士 (數值無突出點，但怒氣值累積快速，可大招速攻，傷害參考物攻)"
			<<"\n2.法師 (攻擊倍率高，但血量最薄，傷害參考魔攻)"
			<<"\n3.坦克 (血量最高，大招可回復極大血量，但攻擊偏低，可打消耗戰，傷害參考物攻)"
			<<"\n4.巫師 (數值介於戰士與法師之間，特攻與大招皆可回復微小血量，傷害參考物攻與魔攻)"<< endl;
		int choice = 0;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "你選擇了 戰士 !" << endl;
			player = &warrior;
			break;
		case 2:
			cout << "你選擇了 法師 !" << endl;
			player = &mage;
			break;
		case 3:
			cout << "你選擇了 坦克 !" << endl;
			player = &tank;
			break;
		case 4:
			cout << "你選擇了 巫師 !" << endl;
			player = &wizard;
			break;
		default:
			cout << "無效的選擇，請重新輸入。\n";
			continue;  // 跳過後續邏輯，重新選擇角色
		}
		player->print();
		cout << "\n是否開始冒險 ? (y/n)";
		char charGo;
		cin >> charGo;
		switch (charGo) {
		case 'y':
			go = false;
			goMap(player);
			break;
		case 'Y':
			go = false;
			goMap(player);
			break;
		case 'n':
			cout << "\n即將重新選擇角色" << endl;
			cout << "(按 Enter 繼續...)" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			continue;
		case 'N':
			cout << "\n即將重新選擇角色" << endl;
			cout << "(按 Enter 繼續...)" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			continue;
		default:
			cout << "\n無效輸入，即將重新選擇角色。" << endl;
			cout << "(按 Enter 繼續...)" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			continue;
		}
	}
}


void goMap(Player* PLayer) {
	// 初始化遊戲參數
	int initialX = 1;  // 玩家初始 X 座標
	int initialY = 1;  // 玩家初始 Y 座標
	char obstacle = '#';  // 障礙物符號
	char debuff = '!';  // 負面地板符號
	char side = '*';  // 邊界符號
	char interact = '@';  // 互動區域符號
	Player* player = PLayer;

	// 創建地圖物件
	mainMap gameMap(player, initialX, initialY, obstacle, debuff, side, interact);


	// 控制輸入
	char command;


	while (true) {
		// 打印地圖
		system("cls");
		//system("clear");
		cout << "歡迎來到RPG冒險遊戲!" << endl;
		gameMap.printMap();

		// 獲取玩家輸入
		cout << "請輸入指令: ";
		command = _getch();

		// 判斷是否退出遊戲
		if (command == 'q' || command == 'Q') {
			cout << "遊戲結束!" << endl;
			break;
		}

		// 移動玩家
		gameMap.setTarget(command);

	}


}