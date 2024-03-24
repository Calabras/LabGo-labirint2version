#include "Wall.h"

Wall::Wall()
{
    hero = nullptr; //����� ���
    val = '#'; //������ ������
}

Wall::Wall(char _val) {
    this->val = _val;
    this->hero = nullptr;
}
//�������� +
Cell* Wall::operator+(Hero& hero) {
    this->hero = &hero;
    return this;
}
//�������� -
Cell* Wall::operator-(Hero& hero) {
    this->hero = &hero;
    return this;
}
//����� ������ �� ������
void Wall::print(ostream& out) const {
    out << "#";
}