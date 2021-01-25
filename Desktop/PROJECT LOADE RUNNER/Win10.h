/*
  Win10.h
*/
#pragma once
#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

// Перечисление для кодов кнопок клавиатуры
enum KEY { // Именнованное перечисление 
	ESC = 27,    // const int ESC = 27;
	SPACE = 32,
	ENTER = 13,
	Z = 122,
	X = 120,

	CURSOR1 = 0, CURSOR2 = 224,
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,

	HOME = 71,
	END = 79,
	PG_UP = 73,
	PG_DOWN = 81,
};

//------------------------------------------------------
// Функция для скрытия/отображения каретки
//  и установки размера курсора
// Параметры:
//   bVisible = 0/1 - скрыть/показать курсор
//   dwSize = от 1 до 100 - размер курсора в %
//
// Чтобы скрыть курсор на экране надо вызвать:
//  CursorHide();
// Чтобы отобразить курсор на экране надо вызвать:
//  CursorHide(1);
// или
//  CursorHide(1, 20); 
//     20 - это размер курсора в %
//         20% от размера полного знакоместа символа
//
void CursorHide(BOOL bVisible = 0, DWORD dwSize = 10) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	// Get console handle
	hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	// Hide console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = dwSize;
	cursorInfo.bVisible = bVisible;
	SetConsoleCursorInfo(hOUTPUT, &cursorInfo);
}

//------------------------------------------------------
// функция установки цвета выводимых символов
//   wAttributes - цветовой аттрибут символа
//    значения, как у консольной команды COLOR
void SetColor(WORD wAttributes) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}
// установка цвета символа отдельными значениями
//  для фона и символа
void SetColor(int colBkgr, int colSym) {
	SetColor(colBkgr * 16 + colSym);
}

//------------------------------------------------------
// Функция для установки позиции каретки по координатам
void SetPos(int x, int y) {
	COORD cd{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

//------------------------------------------------------
// Функция установки/настройки параметров
//   консольного окна программы, приложения
// Параметры:
//  row - высота консольного окна в строках
//        по умолчанию 25 строк
//  col - ширина консольного окна в символах
//        по умолчанию 80 символов, колонок
// Если вызвать в коде:
//  start();
// то консольное окно будет размером 25 строк на 80 символов
//
void SetConsoleSize(int row = 25, int col = 80) {
	char str[100];
	sprintf(str, "mode con cols=%d lines=%d", col, row);
	system(str);
	//system("mode con cols=50 lines=24");
	system("cls");
	//CursorHide();  // Скрыть курсор
}
