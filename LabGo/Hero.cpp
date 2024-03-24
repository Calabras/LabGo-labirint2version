#include "Header.h"
#include "Hero.h"
//возвращает i
int Hero::geti() const { return i; }
//возвращает j
int Hero::getj() const { return j; }
//вывод персонажа на печать
ostream& operator<<(ostream& out, const Hero& h) {
	out << "R";
    return out;
}
//увеличивает число монет
void Hero::addcoins() { coins++; }
//возвращает число монет
int Hero::getcoins() const {
	return coins;
}
//убрать жизнь
void Hero::removehealth() { health--; }
//вернуть число хп
int Hero::gethealth() const {
	return health;
}