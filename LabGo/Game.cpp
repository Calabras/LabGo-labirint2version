#include "Game.h"
#include "Cell.h"
#include "Hero.h"
#include <fstream>
//void Game::setHeroPose(int i, int j) {
//	 //�������� ������� ���������
//	lab_h= labirint.getrows();
//	lab_w= labirint.getcols();
//
//	if (i < 0 || i >= lab_h || j < 0 || j >= lab_w) {
//		return;
//	}
//	if (labirint[i][j]->cansethero()) {
//		//������� ��������� � ������� ������
//		*labirint[hero.geti()][hero.getj()] - hero;
//		//����������� ��������� � ����� ������
//		*labirint[i][j] + hero;
//		hero.move(i, j);
//	}
//}
void Game::setHeroPose(int i, int j) {
	// �������� ������� ���������
	lab_h = labirint.getrows();
	lab_w = labirint.getcols();

	// ���������, ��� ����� ������� ��������� � �������� ���������
	if (i < 0 || i >= lab_h || j < 0 || j >= lab_w) {
		return;
	}

	// ���������, ����� �� ����������� ����� � ����� ������
	if (labirint[i][j]->cansethero()) {
		// ������� ����� �� ������� ������
		Cell* oldCell = *labirint[hero.geti()][hero.getj()]-(hero);
		// ���������, ����� �� �������� ������ ������ (��������, ���� ����� ���� ������)
		if (oldCell != labirint[hero.geti()][hero.getj()]) {
			delete labirint[hero.geti()][hero.getj()]; // ������� ������ ������
			labirint[hero.geti()][hero.getj()] = oldCell; // ������ �����/����������� ������
		}

		// ����������� ����� � ����� ������
		Cell* newCell = *labirint[i][j]+(hero);
		// ���������, ���������� �� ������ ����� ���������� �����
		if (newCell != labirint[i][j]) {
			delete labirint[i][j]; // ������� ������ ������
			labirint[i][j] = newCell; // ��������� ������ �� �����
		}

		// ��������� ������� �����
		hero.move(i, j);
	}
}


//����������� ��� ���� �� ���������
Game::Game() : labirint() {
	setHeroPose(2, 2);
} 

//������������ �����
void Game::move(ACTION act)
{
	int ip = 0;
	int jp = 0;

	ip = hero.geti();
	jp = hero.getj();

	//������������ ���������
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

//���������� ������ << ����
ostream& operator<<(ostream& out, const Game& g) {

	//������� �����
	int ip = g.hero.geti();
	int jp = g.hero.getj();

	//������� ���������
	int lab_height = g.labirint.getrows();
	int lab_width = g.labirint.getcols();


	//����������� ������ ������ ��������� (�������)
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

//���������� ���������� �� ����� ���������
void Game::readfromfile2(const string& filename) {
	ifstream file(filename);
	if (file) {
		int newrows, newcols;
		file >> newrows >> newcols;
		file.ignore(); //����� �������� \n
		DynamicLab tempLab(newrows, newcols);
		this->labirint = tempLab; //������������� � ���������� ������������
		file >> this->labirint;
	}
	else {
		cerr << "Error with opening of file: " << filename << endl;
	}
}

//����� ��������� � ����
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