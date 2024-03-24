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
    return this;
}
//операци€ -
Cell* Wall::operator-(Hero& hero) {
    this->hero = &hero;
    return this;
}
//вывод стенки на печать
void Wall::print(ostream& out) const {
    out << "#";
}