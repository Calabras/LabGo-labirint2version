#include "Cell.h"
#include "Hero.h"
class Monsters : public Cell {
private:
    int healthcount=3; // cчетчик хп
public:
    Monsters();
    Monsters(char _val);
    ~Monsters();
    //операция +
    Cell* operator+(Hero& hero);
    //операция -
    Cell* operator-(Hero& hero);
    //печтать клетки
    void print(ostream& out) const;
    //получить число хп
    int gethealths();
    //копирование стены
    Monsters* copy();
};