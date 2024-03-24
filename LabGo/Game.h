#pragma once
#include "DynamicLab.h"
#include <iostream>
using namespace std;

enum ACTION //������������ define ���������� - ��������� ����
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Game {
	DynamicLab labirint; //�������� ������������� ������� ��� ���������
	Hero hero; //�������� ���������
	int lab_w, lab_h; //������� ���������
public:
	Game(); //����������� �� ��������� ��� �������� ����
	//void readfromfile(const string& filename); //���������� ���� �� �����
	void readfromfile2(const string& filename);
	void writeinfile(const string& filename); //������ ���� � ����
	void move(ACTION act); //������ ������������ ���������
	void setHeroPose(int i, int j); //������������ ������� ���������

	friend ostream& operator<<(ostream& out, const Game& g); //������ ���� � �������
	friend istream& operator>>(istream& in, Game& g); //���������� ���� �� �����

};