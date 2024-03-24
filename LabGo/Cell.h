#include <iostream>
#include "Hero.h"
using namespace std;

#pragma once
class Cell {
	char val; //значение с клавиатуры дл€ передвижени€
	Hero* hero; //если не пустой, то отображаетс€ герой, если пустой, то €чейка просто отображаетс€
public:
	Cell(); //пуста€ клетка по умолчанию;
	Cell(Hero* _hero); //конструктор геро€

	Cell(char _val);  //клекта со значком геро€

	void setHero(Hero* _hero);  //установить геро€
	bool haveHero();  //так мы узнаем есть ли герой в клетке

	//методы дл€ действи€ с клетками 
	/* Cell& operator+ (Hero& h);
	Cell& operator- (Hero& h);*/

	// ѕредполагаетс€, что оператор+ добавл€ет геро€ в клетку, но дл€ базовой клетки это может быть пустой операцией
	virtual Cell* operator+(Hero& hero) {
		// Ѕазова€ реализаци€ может просто возвращать this
		return this;
	}

	// јналогично, оператор- удал€ет геро€ из клетки, но дл€ базовой клетки это также может быть пустой операцией
	virtual Cell* operator-(Hero& hero) {
		// Ѕазова€ реализаци€ может просто возвращать this
		return this;
	}
	// ћетод дл€ вывода символа клетки
	virtual void print(ostream& out) const {
		// ƒл€ пустой клетки можно выводить пробел или другой символ
		out << " ";
	}
	virtual ~Cell() {}

	//перегрузка функий ввода и вывода дл€ клеток
	/*friend ostream& operator<<(ostream& out, const Cell& cell);
	friend istream& operator>>(istream& in, Cell& cell);*/

	friend istream& operator>>(istream& in, Cell*& cell);
	friend ostream& operator<<(ostream& out, const Cell& cell);

	//метод дл€ проверки клетки на возможность хода
	bool cansethero();
};