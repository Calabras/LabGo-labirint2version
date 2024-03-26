#include "Cell.h"
#include "Hero.h"
class Moneta : public Cell {
private:
    int coinscount=0; // c������ �����
public:
    Moneta();
    Moneta(char _val);
    ~Moneta();
    //�������� +
    Cell* operator+(Hero& hero);
    //�������� -
    Cell* operator-(Hero& hero);
    //������� ������
    void print(ostream& out) const;
    //�������� ����� �����
    int getcoinscount();
    //����������� �������
    Moneta* copy();
};