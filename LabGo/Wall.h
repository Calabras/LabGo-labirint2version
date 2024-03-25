#include "Cell.h"
#include "Hero.h"
class Wall : public Cell {
public:
    Cell* operator+(Hero& hero);
    Cell* operator-(Hero& hero);
    Wall();
    Wall(char _val);
    //печать клетки
    virtual void print(ostream& out) const;
    //копирование стены
    Wall* copy();
};
