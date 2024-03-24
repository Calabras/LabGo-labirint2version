#include "Cell.h"
class Moneta : public Cell {
private:
    static int coinscount; // ������� ����� �� ���� ���������

public:
    Moneta() { coinscount++; }
    ~Moneta() { coinscount--; }

    Cell* operator+(Hero& hero)  {
        hero.addcoins(); // ��������� ������ �����
        return new Cell(); // ���������� ������ ������ ����� ����� ������
    }

    Cell* operator-(Hero& hero)  {
        // �������� �� ������������� ��� ������
        return this;
    }
    void print(ostream& out) const  {
        out << "$"; // �����������, ��� $ - ��� ������
    }

    static int getcoinscount() { return coinscount; }
};
int Moneta::coinscount = 0;