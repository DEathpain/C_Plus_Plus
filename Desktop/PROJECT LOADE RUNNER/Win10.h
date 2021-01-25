/*
  Win10.h
*/
#pragma once
#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

// ������������ ��� ����� ������ ����������
enum KEY { // ������������ ������������ 
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
// ������� ��� �������/����������� �������
//  � ��������� ������� �������
// ���������:
//   bVisible = 0/1 - ������/�������� ������
//   dwSize = �� 1 �� 100 - ������ ������� � %
//
// ����� ������ ������ �� ������ ���� �������:
//  CursorHide();
// ����� ���������� ������ �� ������ ���� �������:
//  CursorHide(1);
// ���
//  CursorHide(1, 20); 
//     20 - ��� ������ ������� � %
//         20% �� ������� ������� ���������� �������
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
// ������� ��������� ����� ��������� ��������
//   wAttributes - �������� �������� �������
//    ��������, ��� � ���������� ������� COLOR
void SetColor(WORD wAttributes) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}
// ��������� ����� ������� ���������� ����������
//  ��� ���� � �������
void SetColor(int colBkgr, int colSym) {
	SetColor(colBkgr * 16 + colSym);
}

//------------------------------------------------------
// ������� ��� ��������� ������� ������� �� �����������
void SetPos(int x, int y) {
	COORD cd{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

//------------------------------------------------------
// ������� ���������/��������� ����������
//   ����������� ���� ���������, ����������
// ���������:
//  row - ������ ����������� ���� � �������
//        �� ��������� 25 �����
//  col - ������ ����������� ���� � ��������
//        �� ��������� 80 ��������, �������
// ���� ������� � ����:
//  start();
// �� ���������� ���� ����� �������� 25 ����� �� 80 ��������
//
void SetConsoleSize(int row = 25, int col = 80) {
	char str[100];
	sprintf(str, "mode con cols=%d lines=%d", col, row);
	system(str);
	//system("mode con cols=50 lines=24");
	system("cls");
	//CursorHide();  // ������ ������
}
