#include <iostream>
#include "Hero.h"
using namespace std;

#pragma once
class Cell {
	char val; //�������� � ���������� ��� ������������
	Hero* hero; //���� �� ������, �� ������������ �����, ���� ������, �� ������ ������ ������������
public:
	Cell(); //������ ������ �� ���������;
	Cell(Hero* _hero); //����������� �����

	Cell(char _val);  //������ �� ������� �����

	void setHero(Hero* _hero);  //���������� �����
	bool haveHero();  //��� �� ������ ���� �� ����� � ������

	//������ ��� �������� � �������� 
	/* Cell& operator+ (Hero& h);
	Cell& operator- (Hero& h);*/

	// ��������������, ��� ��������+ ��������� ����� � ������, �� ��� ������� ������ ��� ����� ���� ������ ���������
	virtual Cell* operator+(Hero& hero) {
		// ������� ���������� ����� ������ ���������� this
		return this;
	}

	// ����������, ��������- ������� ����� �� ������, �� ��� ������� ������ ��� ����� ����� ���� ������ ���������
	virtual Cell* operator-(Hero& hero) {
		// ������� ���������� ����� ������ ���������� this
		return this;
	}
	// ����� ��� ������ ������� ������
	virtual void print(ostream& out) const {
		// ��� ������ ������ ����� �������� ������ ��� ������ ������
		out << " ";
	}
	virtual ~Cell() {}

	//���������� ������ ����� � ������ ��� ������
	/*friend ostream& operator<<(ostream& out, const Cell& cell);
	friend istream& operator>>(istream& in, Cell& cell);*/

	friend istream& operator>>(istream& in, Cell*& cell);
	friend ostream& operator<<(ostream& out, const Cell& cell);

	//����� ��� �������� ������ �� ����������� ����
	bool cansethero();
};