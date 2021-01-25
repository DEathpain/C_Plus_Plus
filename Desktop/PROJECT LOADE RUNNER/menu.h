#pragma once
#include <iostream>
#include <string>
#include <vector> // резиновый массив
#include<conio.h>
//#include <array>
#include "Win10.h"
using namespace std;
typedef char** TPole; // тип для поля

void TitleShow() {
	CursorHide();
	SetPos(45, 14);
	cout << "Press any button to go to menu\n";
	while (!_kbhit())
	{
	}
	cin.ignore();
}
class Menu {
private:
	int*ID;
	// координаты экрана вывода меню
	int X, Y;
	// цвета фона и симолов не активных пунктов меню
	int defColFon, defColSym;
	// цвета фона и симолов для активного пункта меню
	int selColFon, selColSym;
	// индекс активного пункта меню
	int Select;
	// кол-во пунктов меню
	int Size;
	// строковые пункты меню
	string*strMenu;
	// массив указателей на функции пунктов меню
	// int MenuFunction(); возвращает код:
	//   1 - меню продолжает работу;
	//   0 - меню должно завершить работу;
	//int(**pfMenuArr)();

	// Объявление методов структуры Menu
public:
	Menu() :ID(), X(15), Y(7), Select(), Size(), strMenu() {
		defColFon = 0; defColSym = 7;
		selColFon = 9; selColSym = 12;
		ID = new int[10];
		strMenu = new string[10];
	}
	void Add(int id, const string& strItem, int pos = 0) {
		for (int i = 0; i < Size; i++) {
			if (ID[i] == id)return;
		}
		ID[Size] = id;
		string* temp = new string[Size + 1];
		memcpy(temp, strMenu, Size * sizeof(strMenu[0]));
		temp[Size] = new char[strItem.size() + 1];
		temp[pos] = strItem;
		strMenu = temp;
		Size++;
	}
	void Insert(int id, const string& strItem, int pos = 0,int c=0) {
		for (int i = 0; i < Size; i++) {
			if (ID[i] == id)return;
		}
		ID[pos] = id;
		string* temp = new string[Size];
		memcpy(temp, strMenu, Size * sizeof(strMenu[0]));
		temp[pos] = strItem;
		strMenu = temp;
	}
	int Show(int StartItem) {
		system("cls");
		if (!Size)return-1;
		Select = StartItem;
		static int amount = 0;
		if (Size > 10) {
			for (int i = 0; i < 10; i++) {
				SetPos(X, Y + i);
				if (Select == i) {
					SetColor(selColFon, selColSym);
				}
				else {
					SetColor(defColFon, defColSym);
				}
				if (i + amount >= 0) {
					cout << strMenu[i + amount];
					SetColor(defColFon, defColSym);
				}
			}
		}
		else {
			for (int i = 0; i < Size; i++) {
				SetPos(X, Y + i);
				if (Select == i) {
					SetColor(selColFon, selColSym);
				}
				else {
					SetColor(defColFon, defColSym);
				}

				cout << strMenu[i];
				SetColor(defColFon, defColSym);
			}
		}
		int key;
		bool redraw = false;
		while (1) {
			key = _getch();
			if (key == 224 || key == 0)
				key = _getch();
			switch (key) {
			case KEY::UP:
				Select--;
				redraw = true;
				if (Select == 0 - 1) {
					Select = Size - 1;
				}
				break;
			case KEY::DOWN:
				if (Select != 10)
					Select++;
				redraw = true;
				if (Select == Size) Select = 0;

				if (Select == 10 && Size > 10) {
					Select--;
					amount++;
				}
				break;
			case KEY::ENTER:
				return ID[Select];
				break;
			case KEY::ESC:
				return 0;
			}
			if (redraw == true) {
				redraw = false;
				return Show(Select);
			}
		}
		return 0;
	}
};