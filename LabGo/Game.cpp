#include "Game.h"
#include "Cell.h"
#include "Hero.h"
#include <fstream>
#include "Wall.h"
#include "Moneta.h"
void Game::setHeroPose(int i, int j) {
	lab_h = labirint.getrows();
	lab_w = labirint.getcols();
	lab_health = labirint.gethealth();

	if (i < 0 || i >= lab_h || j < 0 || j >= lab_w) {
		return;
	}
	if (labirint[i][j]->cansethero()) {
		Cell* oldCell = *labirint[hero.geti()][hero.getj()] - hero; //убрал героя из клетки
		if (oldCell != labirint[hero.geti()][hero.getj()]) { //обновление старой клетки
			delete labirint[hero.geti()][hero.getj()];
			labirint[hero.geti()][hero.getj()] = oldCell;
		}
		Cell* newCell = *labirint[i][j] + hero; //идем в новую клетку
		if (newCell != labirint[i][j]) { //обновление новой клетки
			delete labirint[i][j];
			labirint[i][j] = newCell;
		}
		hero.move(i, j);
	}
	else return;
}

//конструктор для игры по умолчанию
Game::Game() {
	setHeroPose(1, 1);
} 

//передвижение героя
void Game::move(ACTION act)
{
	int ip = 0;
	int jp = 0;

	ip = hero.geti();
	jp = hero.getj();

	//передвижение персонажа
	switch (act) {
	case UP:
		ip--;
		break;
	case DOWN:
		ip++;
		break;
	case LEFT:
		jp--;
		break;
	case RIGHT:
		jp++;
		break;
	}
	setHeroPose(ip, jp);
}

//перегрузка вывода << игры
ostream& operator<<(ostream& out, const Game& g) {

	//позиция героя
	int ip = g.hero.geti();
	int jp = g.hero.getj();

	//размеры лабиринта
	int lab_height = g.labirint.getrows();
	int lab_width = g.labirint.getcols();


	//отображение клеток вокруг персонажа (крайние)
	int start_i;
	if (ip-1>0) start_i = ip-1; else start_i = 0;
	int end_i;
	if (ip+1<lab_height - 1) end_i = ip+1; else end_i = lab_height - 1;
	int start_j;
	if (jp-1>0) start_j = jp-1; else start_j = 0;
	int end_j;
	if (jp+1<lab_width - 1) end_j = jp+1; else end_j = lab_width - 1;

	for (int i = start_i-2; i <= end_i+2; i++) {
		for (int j = start_j-2; j <= end_j+2; j++) {
			if (i < 0 || i >= lab_height || j < 0 || j >= lab_width) {
				out << "/";
			}
			else {
				*(g.labirint[0][0]) = '#';
				out << *(g.labirint[i][j]);
			}
		}
		out << endl;
	}
	return out;
}

//реализация считывания из файла лабиринта
void Game::readfromfile2(const string& filename) {
	ifstream file(filename);
	if (file) {
		int newrows, newcols, counthealth;
		file >> newrows >> newcols >> counthealth;
		hero.health = counthealth;
		file.ignore(); //чтобы скипнуть \n
		DynamicLab tempLab(newrows, newcols, counthealth);
		this->labirint = tempLab; //использование и перегрузка присваивания
		file >> this->labirint;
	}
	else {
		cerr << "Error with opening of file: " << filename << endl;
	}
}

//вывод лабиринта в файл
void Game::writeinfile(const string& filename) {
	ofstream file(filename);
	if (file) {
		file << labirint.getrows() << " " << labirint.getcols() << " " << labirint.gethealth();
		file << endl;
		int ih = hero.geti();
		int ij = hero.getj();
		*labirint[ih][ij] = ' ';
		file << this->labirint;
	}
	else {
		cerr << "Error with opening of file: " << filename << endl;
	}

}
//выводить число монеток
void Game::displayCoins() const {
	cout << "Total Coins of hero: " << hero.getcoins() << endl;
}
//выводить число хп
void Game::displayHealth() const {
	cout << "Your Heath:  " << hero.gethealth() <<  " hp" << endl;
}