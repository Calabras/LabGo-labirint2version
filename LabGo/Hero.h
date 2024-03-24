#pragma once
#include <iostream>
using namespace std;

class Hero
{
	int i, j, coins;
public:
	//позиция персонажа (изменение позиции персонажа)
	Hero(int _i=0, int _j=0) {
		i = _i;
		j = _j;
	}
	//возвращает x
	int geti() const;
	//возвращает y
	int getj() const;
	//возвращает число монет
	int getcoins() const;
	//увеличивает число монет
	void addcoins();
	//передвижение персонажа
	void move(int _i = 0, int _j = 0) {
		i = _i;
		j = _j;
	}
	//печать персонажа
	friend ostream& operator<<(ostream& out, const Hero& h);
};