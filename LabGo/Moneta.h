#include "Cell.h"
class Moneta : public Cell {
private:
    static int coinscount; // Счетчик монет во всем лабиринте

public:
    Moneta() { coinscount++; }
    ~Moneta() { coinscount--; }

    Cell* operator+(Hero& hero)  {
        hero.addcoins(); // Добавляем монету герою
        return new Cell(); // Возвращаем пустую клетку после сбора монеты
    }

    Cell* operator-(Hero& hero)  {
        // Операция не предусмотрена для монеты
        return this;
    }
    void print(ostream& out) const  {
        out << "$"; // Предположим, что $ - это монета
    }

    static int getcoinscount() { return coinscount; }
};
int Moneta::coinscount = 0;