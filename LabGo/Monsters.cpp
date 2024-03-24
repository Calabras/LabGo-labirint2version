#include "Monsters.h"
Monsters::Monsters()
{
    healthcount--;
}

Monsters::Monsters(char _val) {
    this->val = _val;
    this->hero = nullptr;
}

Monsters::~Monsters() { healthcount++; }

//�������� +
Cell* Monsters::operator+(Hero& hero) {
    hero.removehealth(); //������ ��
    cout << "Total Healths: " << hero.gethealth() << " hp" << endl;
    Cell* newCell = new Cell(); 
    newCell->setHero(&hero); 
    return newCell; 
}


//�������� -
Cell* Monsters::operator-(Hero& hero) {
    if (this->hero == &hero) this->hero = nullptr;
    return this;
}
//����� ������ �� ������
void Monsters::print(ostream& out) const {
    out << "^";
}
int Monsters::gethealths() {
    cout << "Total Health: " << healthcount << " hp" << endl;
    return healthcount;
}