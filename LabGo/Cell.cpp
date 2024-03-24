#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
Cell::Cell()
{
	hero = nullptr; //героя нет
	val = ' '; //ячейка пустая
}

//конструкторы для героя и значеняи клетки
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

////добавление героя в клетку
//Cell& Cell::operator+ (Hero& h) {
//	this->hero = &h; // Присваиваем указатель на героя текущей клетке
//	return *this; // Возвращаем ссылку на текущую клетку
//}
//
//// Удаление героя из клетки
//Cell& Cell::operator- (Hero& h) {
//	if (this->hero == &h) {
//		this->hero = nullptr; // Удаляем героя из клетки
//	}
//	return *this; // Возвращаем ссылку на текущую клетку
//}

//узнать состояние текущей клетки
bool Cell::cansethero() {
	return val == ' ';
}

//перегрузка вывода на печать для клеток
//ostream& operator<<(ostream& out, const Cell& cell) {
//	if (cell.hero != nullptr) {
//		out << *(cell.hero);  //указываем на клетку с героем
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

////перегрузка операции ввода клеток
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
    in >>noskipws>>symbol;// Читаем символ

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

