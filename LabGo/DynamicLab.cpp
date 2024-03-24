#include <iostream>
#include "DynamicLab.h"
using namespace std;

DynamicLab::DynamicLab(int _rows, int _cols) : rows(_rows), cols(_cols), m(nullptr) {
    m = new Cell * *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new Cell * [cols];
        for (int j = 0; j < cols; j++) {
            m[i][j] = new Cell(); // �������� ������ ��� ������ ������
        }
    }
}


//����������
DynamicLab::~DynamicLab() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            delete m[i][j]; // ����������� ������ ������ ������
        }
        delete[] m[i];
    }
    delete[] m;
}

//����������� �����������
DynamicLab::DynamicLab(const DynamicLab& second_lab) : rows(second_lab.rows), cols(second_lab.cols), m(nullptr) {
    m = new Cell * *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new Cell * [cols];
        for (int j = 0; j < cols; j++) {
            m[i][j] = new Cell(*second_lab.m[i][j]); // �������� ������ � �������� ������ ������
        }
    }
}

//���������� �������� ������������ =
DynamicLab& DynamicLab::operator=(const DynamicLab& second_lab) {
    if (this != &second_lab) { // �������� �� ����������������
        // ������������ ������� ������
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete m[i][j];
            }
            delete[] m[i];
        }
        delete[] m;

        // ����������� �������� ���������
        rows = second_lab.rows;
        cols = second_lab.cols;

        // ��������� ������ � ����������� ������
        m = new Cell * *[rows];
        for (int i = 0; i < rows; i++) {
            m[i] = new Cell * [cols];
            for (int j = 0; j < cols; j++) {
                m[i][j] = new Cell(*second_lab.m[i][j]); // �������� ����������� ������ ������
            }
        }
    }
    return *this; // ������� ������ �� ������� ������
}


//���������� ��������� []
Cell** DynamicLab::operator[](int row) const {
    if (row >= 0 && row < rows) {
        return m[row];
    }
    else {
        return nullptr; // ���������� nullptr ��� ������������ ��������
    }
}



//�������� ����� ��������� �� �����
//istream& operator>>(istream& in, DynamicLab& labirint)
//{
//    for (int i = 0; i < labirint.rows; i++) {
//        for (int j = 0; j < labirint.cols; j++) {
//            in >> noskipws >> *labirint[i][j];
//        }
//        in.ignore(); //���� ����� ��������� �������� �� ���������� �����, ���� ����� � ����� ������, �� ������ ���������������
//    }
//    return in;
//}


istream& operator>>(istream& in, DynamicLab& labirint) {
    for (int i = 0; i < labirint.getrows(); i++) {
        for (int j = 0; j < labirint.getcols(); j++) {
            // ������� ��������� ��������� �� Cell
            Cell* tempCell = nullptr;
            // ��������� ������ �� ������ �����
            in >> tempCell;
            // ������� ���������� ������, ���� ��� ����������
            delete labirint[i][j];
            // ����������� ����� ������ ������� � ���������
            labirint[i][j] = tempCell;
            if (j == labirint.getcols() - 1) {
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    return in;
}

//�������� ������ ��������� � ����
ostream& operator<<(ostream& out, DynamicLab& labirint)
{
    for (int i = 0; i < labirint.rows; i++) {
        for (int j = 0; j < labirint.cols; j++) {
            out << *labirint[i][j];
        }
        out << endl;
    }
    return out;
}
