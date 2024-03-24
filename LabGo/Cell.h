#include <iostream>
#include "Hero.h"
using namespace std;

#pragma once
class Cell {
protected:
	char val; //�������� � ���������� ��� ������������
	Hero* hero; //���� �� ������, �� ������������ �����, ���� ������, �� ������ ������ ������������
public:
	Cell(); //������ ������ �� ���������;
	Cell(char _val);  //������ �� ������� �����
	bool haveHero();  //��� �� ������ ���� �� ����� � ������
	//���������� �����
	void setHero(Hero* _hero);
	//�������� +
	virtual Cell* operator+(Hero& hero);
	//�������� -
	virtual Cell* operator-(Hero& hero);

	//����� ������� ������
	virtual void print(ostream& out) const;
	//���������� ��� ������
	virtual ~Cell() {}

	//���������� ������ ����� � ������ ��� ������
	friend istream& operator>>(istream& in, Cell*& cell);
	friend ostream& operator<<(ostream& out, const Cell& cell);

	//����� ��� �������� ������ �� ����������� ����
	bool cansethero();
};