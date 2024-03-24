#include <iostream>
#include "Hero.h"
using namespace std;

#pragma once
class Cell {
protected:
	char val; //значение с клавиатуры для передвижения
	Hero* hero; //если не пустой, то отображается герой, если пустой, то ячейка просто отображается
public:
	Cell(); //пустая клетка по умолчанию;
	Cell(char _val);  //клекта со значком героя
	bool haveHero();  //так мы узнаем есть ли герой в клетке
	//установить героя
	void setHero(Hero* _hero);
	//операция +
	virtual Cell* operator+(Hero& hero);
	//операция -
	virtual Cell* operator-(Hero& hero);

	//вывод символа клетки
	virtual void print(ostream& out) const;
	//деструктор для клетки
	virtual ~Cell() {}

	//перегрузка функий ввода и вывода для клеток
	friend istream& operator>>(istream& in, Cell*& cell);
	friend ostream& operator<<(ostream& out, const Cell& cell);

	//метод для проверки клетки на возможность хода
	bool cansethero();
};