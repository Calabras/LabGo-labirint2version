#include <iostream>
#include "DynamicLab.h"
using namespace std;

DynamicLab::DynamicLab(int _rows, int _cols) : rows(_rows), cols(_cols), m(nullptr) {
    m = new Cell * *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new Cell * [cols];
        for (int j = 0; j < cols; j++) {
            m[i][j] = new Cell(); // Выделяем память для каждой клетки
        }
    }
}


//деструктор
DynamicLab::~DynamicLab() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            delete m[i][j]; // Освобождаем память каждой клетки
        }
        delete[] m[i];
    }
    delete[] m;
}

//конструктор копирования
DynamicLab::DynamicLab(const DynamicLab& second_lab) : rows(second_lab.rows), cols(second_lab.cols), m(nullptr) {
    m = new Cell * *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new Cell * [cols];
        for (int j = 0; j < cols; j++) {
            m[i][j] = new Cell(*second_lab.m[i][j]); // Выделяем память и копируем каждую клетку
        }
    }
}

//перегрузка операции присваивания =
DynamicLab& DynamicLab::operator=(const DynamicLab& second_lab) {
    if (this != &second_lab) { // Проверка на самоприсваивание
        // Освобождение текущей памяти
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete m[i][j];
            }
            delete[] m[i];
        }
        delete[] m;

        // Копирование размеров лабиринта
        rows = second_lab.rows;
        cols = second_lab.cols;

        // Выделение памяти и копирование клеток
        m = new Cell * *[rows];
        for (int i = 0; i < rows; i++) {
            m[i] = new Cell * [cols];
            for (int j = 0; j < cols; j++) {
                m[i][j] = new Cell(*second_lab.m[i][j]); // Глубокое копирование каждой клетки
            }
        }
    }
    return *this; // Возврат ссылки на текущий объект
}


//перегрузка оператора []
Cell** DynamicLab::operator[](int row) const {
    if (row >= 0 && row < rows) {
        return m[row];
    }
    else {
        return nullptr; // Возвращаем nullptr для недопустимых индексов
    }
}



//операция ввода лабиринта из файла
//istream& operator>>(istream& in, DynamicLab& labirint)
//{
//    for (int i = 0; i < labirint.rows; i++) {
//        for (int j = 0; j < labirint.cols; j++) {
//            in >> noskipws >> *labirint[i][j];
//        }
//        in.ignore(); //если хотим считывать лабиринт из нескольких строк, если хотим с одной строки, то просто закоментировать
//    }
//    return in;
//}


istream& operator>>(istream& in, DynamicLab& labirint) {
    for (int i = 0; i < labirint.getrows(); i++) {
        for (int j = 0; j < labirint.getcols(); j++) {
            // Создаем временный указатель на Cell
            Cell* tempCell = nullptr;
            // Считываем клетку из потока ввода
            in >> tempCell;
            // Удаляем предыдущую клетку, если она существует
            delete labirint[i][j];
            // Присваиваем новую клетку позиции в лабиринте
            labirint[i][j] = tempCell;
            if (j == labirint.getcols() - 1) {
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    return in;
}

//операция вывода лабиринта в файл
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
