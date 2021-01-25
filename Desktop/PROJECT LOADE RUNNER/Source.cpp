#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <Windows.h> // WinAPI: GetOpenFileName()/GetSaveFileName()
#include "menu.h"
#include "Game.h"
using namespace std; // STL
#pragma warning(disable:4996)
struct LC { LC() { system("chcp 866>nul"); srand((int)time(0)); TitleShow(); }~LC() { cin.get(); cin.get();/*system("pause");*/ } }l;

#define EXIT_ID 0
#define BEGIN_ID 1
#define LOAD_ID 3
#define ABOUT_ID 4

int main(int argc,char**argv) {
	Game game;
	system("cls");
	menu.Add(BEGIN_ID, "Start game",0);
	menu.Add(LOAD_ID, "Load game",1);
	menu.Add(ABOUT_ID, "About game",2);
	menu.Add(EXIT_ID, "Exit",3);

	bool isExit = false;
	while (!isExit) {
		int select = menu.Show(0);
		switch (select)
		{
		case CONTINUE_ID: case BEGIN_ID: {
			isStart = true;
			game.Start();
			break;
		}
		case LOAD_ID: {
			game.LoadGame(); break;
		}
		case SAVE_ID: {
			game.SaveGame(); break;
		}
		case EXIT_ID: {
			system("cls");
			SetPos(10, 7);
			cout << "Are you sure you want to quite the game?(y/n): ";
			char ans;
			cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				system("cls");
				SetPos(10, 7);
				cout << "GoodBye!\n";
				isExit = true;
			}break;
		}
		default:
			break;
		}
	}
}