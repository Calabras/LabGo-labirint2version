#include "Header.h"
#include "Game.h"
#include <fstream>
using namespace std;

int main() {
    Game g;
    //считывание лабиринта из файла и обработка ошибки
    //g.readfromfile("labirint.txt"); //считывание лабиринта из строки  (файл)
    g.readfromfile2("labirint2.txt"); //считывание лабиринта из многострочного файла

    //начальная позиция
    g.setHeroPose(2, 2);
    unsigned int val = 0;
    cout << g;

    val = _getch();
    while (val != 27) { //esc
        system("cls"); 

        if (val == 224) {
            val = _getch(); 
        }
        switch (val) {
        case 80:
            g.move(DOWN);
            break;
        case 72:
            g.move(UP);
            break;
        case 75:
            g.move(LEFT);
            break;
        case 77:
            g.move(RIGHT);
            break;
        }

        cout << g;
        val = _getch();
    }
    if (val == 27) {
        g.writeinfile("labirintend.txt"); //сохранили лабиринт в конце программы
    }
    return 0;
}
