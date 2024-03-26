#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
#include "Monsters.h"

Cell::Cell()
{
	hero = nullptr; //����� ���
	val = ' '; //������ ������
}

//������������ ��� ����� � �������� ������
Cell::Cell(char _val) : hero(nullptr), val(_val) {
}

//���� �� ����� � ������
bool Cell::haveHero() {
	return hero != nullptr;
}
//���������� ����� � ������
void Cell::setHero(Hero* _hero) {
    hero = _hero;
}
//����� ������� ������
void Cell::print(ostream& out) const {
    out << " ";
}
//�������� -
Cell* Cell:: operator-(Hero& hero) {
    if (this->hero == &hero) this->hero = nullptr;
    return this;
}
//�������� +
Cell* Cell::operator+(Hero& hero) {
    this->hero = &hero;
    return this;
}

//������ ��������� ������� ������
bool Cell::cansethero() {
	return val == ' ';
}
//������ ������ � �����
ostream& operator<<(ostream& out, const Cell& cell) {
    if (cell.hero != nullptr) {
        out << *(cell.hero);
    }
    else {
        cell.print(out);
    }
	return out;
}

//���� ������
istream& operator>>(istream& in, Cell*& cell) {
    char symbol;
    in >>noskipws>>symbol; // ������ ������

    switch (symbol) {
    case '#':
        cell = new Wall();
        break;
    case '$':
        cell = new Moneta();
        break;
    case '^':
        cell = new Monsters();
        break;
    default:
        cell = new Cell(); 
        break;
    }
    return in;
}

//����������� �������
Cell* Cell::copy() {
    return new Cell(*this);
}
