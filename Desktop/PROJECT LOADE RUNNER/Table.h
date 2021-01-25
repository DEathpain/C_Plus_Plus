#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>     // class vector<T>
#include <map>        // class map<>/multimap<>
#include "Win10.h"       // class map<>/multimap<>
#include <iterator>   // class iterator
#include <algorithm>  // begin()/end(), swap(), move()
#include <time.h>     // C
#define MAX_TABLE_WIDTH 110
#define MAX_TABLE_HIGH 23
char table[MAX_TABLE_HIGH][MAX_TABLE_WIDTH] = {
	"=================================",
	"||¹ |NickName   ||Points|Level || ",
	"=================================",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"||  |           ||      |      ||",
	"================================="
};
using namespace std;
typedef char** Pole;
multimap<int, string> tablescore;
typedef multimap<int, string> MyMap;
typedef MyMap::iterator Myit;
typedef MyMap::reverse_iterator MyRit;
#pragma warning(disable:4996)
struct Table {
	int point;
	//int X, Y;
	string NickName;
};
void Add(Table&tp) {
	tablescore.emplace(tp.point, tp.NickName);
}
void Print() {
	MyRit rit = tablescore.rbegin();
	SetPos(0, 5);
	//for (int i = 3; i < MAX_TABLE_HIGH - 1; i++) {
	//	for (int j = 2; j < 4; j++) {
	//		table[i][j] = ' ';
	//	}
	//	for (int j = 5; j < 15; j++) {
	//		table[i][j] = ' ';
	//	}
	//	for (int j = 5; j < 15; j++) {
	//		table[i][j] = ' ';
	//	}
	//	//cout << endl;
	//}
	for (int i = 0; i < MAX_TABLE_HIGH; i++) {
		for (int j = 0; j < MAX_TABLE_WIDTH; j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
	int e = 0;
	for (; rit != tablescore.rend(); ++rit) {
		SetPos(2, 8+e);
		cout << e + 1;
		SetPos(25, 8+e);
		cout << 1;
		SetPos(5, 8+e);
		cout << rit->second;
		SetPos(18, 8+e);
		cout<< rit->first << '\n';
		e++;
	}
}
