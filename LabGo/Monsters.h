#include "Cell.h"
#include "Hero.h"
class Monsters : public Cell {
private:
    int healthcount=3; // c������ ��
public:
    Monsters();
    Monsters(char _val);
    ~Monsters();
    //�������� +
    Cell* operator+(Hero& hero);
    //�������� -
    Cell* operator-(Hero& hero);
    //������� ������
    void print(ostream& out) const;
    //�������� ����� ��
    int gethealths();
    //����������� �����
    Monsters* copy();
};