#pragma once
#include <iostream>
using namespace std;
class Hero
{
	int i, j, coins=0, health = 3;
public:
	//������� ��������� (��������� ������� ���������)
	Hero(int _i=0, int _j=0) {
		i = _i;
		j = _j;
	}
	//���������� x
	int geti() const;
	//���������� y
	int getj() const;
	//���������� ����� �����
	int getcoins() const;
	//����������� ����� �����
	void addcoins();
	//������������ ���������
	void move(int _i = 0, int _j = 0) {
		i = _i;
		j = _j;
	}
	//������ ���������
	friend ostream& operator<<(ostream& out, const Hero& h);
	//������ �����
	void removehealth();
	//������� ����� ��
	int gethealth() const;
};