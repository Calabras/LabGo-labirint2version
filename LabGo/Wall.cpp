#include "Wall.h"

Wall::Wall()
{
    hero = nullptr; //геро€ нет
    val = '#'; //€чейка пуста€
}

Wall::Wall(char _val) {
    this->val = _val;
    this->hero = nullptr;
}
//операци€ +
Cell* Wall::operator+(Hero& hero) {
    this->hero = &hero;
    return new Cell;
}
//операци€ -
Cell* Wall::operator-(Hero& hero) {
    this->hero = &hero;
    return new Cell;
}
//вывод стенки на печать
void Wall::print(ostream& out) const {
    out << "#";
}
//копирование объекта
Wall* Wall::copy() {
    return new Wall(*this);
}