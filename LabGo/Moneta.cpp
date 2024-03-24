#include "Moneta.h"
Moneta::Moneta()
{
    coinscount++;
}

Moneta::Moneta(char _val) {
    this->val = _val;
    this->hero = nullptr;
}

Moneta::~Moneta() { coinscount--; }

//операци€ +
Cell* Moneta::operator+(Hero& hero) {
    hero.addcoins(); // ”величиваем количество монет у геро€
    cout << "Total Coins: " << hero.getcoins() << endl;

    Cell* newCell = new Cell(); // —оздаем новую пустую клетку
    newCell->setHero(&hero); // ”станавливаем геро€ в новую клетку
    return newCell; // ¬озвращаем новую клетку с героем
}


//операци€ -
Cell* Moneta::operator-(Hero& hero) {
    if (this->hero == &hero) this->hero = nullptr;
    return this;
}
//вывод монеты на печать
void Moneta::print(ostream& out) const {
    out << "$"; 
}
 int Moneta::getcoinscount() { 
    cout << "Total Coins: " << coinscount << endl;
    return coinscount; 
 }