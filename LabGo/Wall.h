#include "Cell.h"
class Wall : public Cell {
public:
    Cell* operator+(Hero& hero) {
        // ����� �� ��������� ����� ���������, ���������� ����
        return this;
    }

    Cell* operator-(Hero& hero) {
        // �������� ����� �� ����� �� �������������, ���������� ����
        return this;
    }

    void print(ostream& out) const override {
        out << "#"; // �����������, ��� # - ��� �����
    }
};
