#pragma once
#include "DynamicLab.h"
#include <iostream>
using namespace std;

enum ACTION //перечисление define переменных - возможные ходы
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Game {
	DynamicLab labirint; //создание динамического массива для лабиринта
	Hero hero; //создание персонажа
	int lab_w, lab_h; //размеры лабиринта
public:
	Game(); //конструктор по умолчанию для создания игры
	//void readfromfile(const string& filename); //считывание игры из файла
	void readfromfile2(const string& filename);
	void writeinfile(const string& filename); //запись игры в файл
	void move(ACTION act); //задать передвижение персонажа
	void setHeroPose(int i, int j); //установление позиции персонажа

	friend ostream& operator<<(ostream& out, const Game& g); //печать игры в консоль
	friend istream& operator>>(istream& in, Game& g); //считывание игры из файла

};