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
    return new Cell;
}
//�������� -
Cell* Wall::operator-(Hero& hero) {
    this->hero = &hero;
    return new Cell;
}
//����� ������ �� ������
void Wall::print(ostream& out) const {
    out << "#";
}
//����������� �������
Wall* Wall::copy() {
    return new Wall(*this);
}