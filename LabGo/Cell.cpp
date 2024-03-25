#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
#include "Monsters.h"

Cell::Cell()
{
	hero = nullptr; //геро€ нет
	val = ' '; //€чейка пуста€
}

//конструкторы дл€ геро€ и значен€и клетки
Cell::Cell(char _val) : hero(nullptr), val(_val) {
}

//есть ли герой в клетке
bool Cell::haveHero() {
	return hero != nullptr;
}
//установить геро€ в клетку
void Cell::setHero(Hero* _hero) {
    hero = _hero;
}
//вывод символа клетки
void Cell::print(ostream& out) const {
    out << " ";
}
//операци€ -
Cell* Cell:: operator-(Hero& hero) {
    if (this->hero == &hero) this->hero = nullptr;
    return this;
}
//операци€ +
Cell* Cell::operator+(Hero& hero) {
    this->hero = &hero;
    return this;
}

//узнать состо€ние текущей клетки
bool Cell::cansethero() {
	return val == ' ';
}
//печать клеток и геро€
ostream& operator<<(ostream& out, const Cell& cell) {
    if (cell.hero != nullptr) {
        out << *(cell.hero);
    }
    else {
        cell.print(out);
    }
	return out;
}

//ввод клеток
istream& operator>>(istream& in, Cell*& cell) {
    char symbol;
    in >>noskipws>>symbol; // „итаем символ

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

//копирование объекта
Cell* Cell::copy() {
    return new Cell(*this);
}
