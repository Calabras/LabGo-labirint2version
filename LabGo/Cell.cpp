#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
Cell::Cell()
{
	hero = nullptr; //����� ���
	val = ' '; //������ ������
}

//������������ ��� ����� � �������� ������
Cell::Cell(Hero* _hero) : hero(_hero), val(' ') {
}
Cell::Cell(char _val) : hero(nullptr), val(_val) {
}

void Cell::setHero(Hero* _hero) {
	hero = _hero;
}

bool Cell::haveHero() {
	return hero != nullptr;
}

////���������� ����� � ������
//Cell& Cell::operator+ (Hero& h) {
//	this->hero = &h; // ����������� ��������� �� ����� ������� ������
//	return *this; // ���������� ������ �� ������� ������
//}
//
//// �������� ����� �� ������
//Cell& Cell::operator- (Hero& h) {
//	if (this->hero == &h) {
//		this->hero = nullptr; // ������� ����� �� ������
//	}
//	return *this; // ���������� ������ �� ������� ������
//}

//������ ��������� ������� ������
bool Cell::cansethero() {
	return val == ' ';
}

//���������� ������ �� ������ ��� ������
//ostream& operator<<(ostream& out, const Cell& cell) {
//	if (cell.hero != nullptr) {
//		out << *(cell.hero);  //��������� �� ������ � ������
//	}
//	else {
//		out << cell.val;
//	}
//	return out;
//}
ostream& operator<<(ostream& out, const Cell& cell) {
	cell.print(out); 
	return out;
}

////���������� �������� ����� ������
//istream& operator>>(istream& in, Cell& cell) {
//	char symbol;
//	in >> std::noskipws >> symbol;
//
//	if (symbol == '#') {
//		cell = Cell('#');
//	}
//	else if (symbol == ' ') {
//		cell = Cell(' ');
//	}
//	return in;
//}
istream& operator>>(istream& in, Cell*& cell) {
    char symbol;
    in >>noskipws>>symbol;// ������ ������

    switch (symbol) {
    case '#':
        cell = new Wall();
        break;
    case '$':
        cell = new Moneta();
        break;
    default:
        cell = new Cell(); 
        break;
    }
    return in;
}

