#pragma once
#include<iostream>
#include<time.h>
#include<fstream>
#include <string> 
#include "List.h"
#define RND(min,max) (rand()%((max)-(min)+1)+(min))
using namespace std;
template<class T>
class Queue_Prior {
private:
	List<T> mas;
	List<T> Priority;
	int size;
public:
	Queue_Prior(int c = 0, int s = 0) :mas(), Priority(), size(s) {}
	Queue_Prior(const T*ma, const  T*prir, int sz = 0) :mas(ma, sz), Priority(prir, sz), size(sz) {}
	void Add(T&&m, int&&p) {
		Add(m, p);
	}
	void Add(T&m, int p) {
		int i = 0;
		if (!mas.pHead || !mas.pTail) {
			mas.Add_Head(m);
			Priority.Add_Head(p);
			size++;
		}
		else {
			List<T> temp = Priority;
			while (temp.pTail&&temp.pTail->data < p) {
				if (!temp.pTail->pPrev) {
					if (temp.pTail->data > p) {
						i++;
						Priority.Add(p);
						mas.Add(m);
						size++;
						break;
					}
					i++;
					Priority.Add_Head(p);
					mas.Add_Head(m);
					size++;
					break;
				}
				else {
					if (temp.pTail->pPrev->data >= p) {
						i++;
						Priority.Insert(size - i, p);
						mas.Insert(size - i, m);
						size++;
						break;
					}

					//if (temp.pTail->pPrev->data < p) {
					//	Priority.Insert(i, p);
					//	mas.Insert(i, m);
					//	size++;

					//	break;
					//}
				}
				temp.pTail = temp.pTail->pPrev;
				i++;
			}
			if (!i) {
				Priority.Add(p);
				mas.Add(m);
				size++;
			}
		}
	}
	void pop() {
		mas.Delete(0);
		Priority.Delete(0);
		size--;
	}
	void Show() {
		cout << "Array: " << "    " << mas << endl
			<< "Priority: " << Priority << endl;
	}
};
typedef Queue_Prior<int> MyQint;
typedef List<MyQint> MyQList;
template<class T>
void InitMas(T*m, int*p) {
	int size = RND(1, 20);
	for (int i = 0; i < size; i++) {
		m[i] = RND(0, 20);
		p[i] = RND(0, 9);
	}
}

void AddQueueToList(MyQList& lst, int Min = 10, int Max = 20) {
	int sz = 10;
	int*mas = new int[sz];
	int*Prir = new int[sz];
	InitMas(mas, Prir);
	MyQint q2;
	for (int j = 0; j < sz; j++) {
		q2.Add(mas[j], Prir[j]);
	}
	q2.Show();
	lst.Add(q2);
}