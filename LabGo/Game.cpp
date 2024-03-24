#include "Game.h"
#include "Cell.h"
#include "Hero.h"
#include <fstream>
//void Game::setHeroPose(int i, int j) {
//	 //Получаем размеры лабиринта
//	lab_h= labirint.getrows();
//	lab_w= labirint.getcols();
//
//	if (i < 0 || i >= lab_h || j < 0 || j >= lab_w) {
//		return;
//	}
//	if (labirint[i][j]->cansethero()) {
//		//убираем персонажа с текущей клетки
//		*labirint[hero.geti()][hero.getj()] - hero;
//		//передвигаем персонажа в новую клетку
//		*labirint[i][j] + hero;
//		hero.move(i, j);
//	}
//}
void Game::setHeroPose(int i, int j) {
	// Получаем размеры лабиринта
	lab_h = labirint.getrows();
	lab_w = labirint.getcols();

	// Проверяем, что новая позиция находится в пределах лабиринта
	if (i < 0 || i >= lab_h || j < 0 || j >= lab_w) {
		return;
	}

	// Проверяем, можно ли переместить героя в новую клетку
	if (labirint[i][j]->cansethero()) {
		// Убираем героя из текущей клетки
		Cell* oldCell = *labirint[hero.geti()][hero.getj()]-(hero);
		// Проверяем, нужно ли обновить старую клетку (например, если герой взял монету)
		if (oldCell != labirint[hero.geti()][hero.getj()]) {
			delete labirint[hero.geti()][hero.getj()]; // Удаляем старую клетку
			labirint[hero.geti()][hero.getj()] = oldCell; // Ставим новую/обновленную клетку
		}

		// Передвигаем героя в новую клетку
		Cell* newCell = *labirint[i][j]+(hero);
		// Проверяем, изменилась ли клетка после добавления героя
		if (newCell != labirint[i][j]) {
			delete labirint[i][j]; // Удаляем старую клетку
			labirint[i][j] = newCell; // Обновляем клетку на новую
		}

		// Обновляем позицию героя
		hero.move(i, j);
	}
}


//конструктор для игры по умолчанию
Game::Game() : labirint() {
	setHeroPose(2, 2);
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
		int newrows, newcols;
		file >> newrows >> newcols;
		file.ignore(); //чтобы скипнуть \n
		DynamicLab tempLab(newrows, newcols);
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
		file << labirint.getrows() <<" "<< labirint.getcols();
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