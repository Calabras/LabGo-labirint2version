#include "Cell.h"
#include "Hero.h"
class Moneta : public Cell {
private:
    int coinscount=0; // cчетчик монет
public:
    Moneta();
    Moneta(char _val);
    ~Moneta();
    //операция +
    Cell* operator+(Hero& hero);
    //операция -
    Cell* operator-(Hero& hero);
    //печтать клетки
    void print(ostream& out) const;
    //получить число монет
    int getcoinscount();
    //копирование объекта
    Moneta* copy();
};