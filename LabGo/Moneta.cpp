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

//операция +
Cell* Moneta::operator+(Hero& hero) {
    hero.addcoins(); 
    cout << "Total Coins: " << hero.getcoins() << endl;

    Cell* newCell = new Cell(); 
    newCell->setHero(&hero); 
    return newCell; 
}


//операция -
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