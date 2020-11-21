#pragma once
#include<iostream>
#include"Map.h"
#include<easyx.h>
#include"GameSetting.h"

//��ǰ������
typedef enum {
	Up, Left, Down, Right
}Direction;

class Unit
{
public:
	int Coord_X, Coord_Y; // X��Y����
	Direction nowdir;
	Unit(Direction dir) :nowdir(dir) {};
	Unit(int Coord_X, int Coord_Y) :Coord_X(Coord_X), Coord_Y(Coord_Y) {};
	Unit(int Coord_X, int Coord_Y, Direction dir) :Coord_X(Coord_X), Coord_Y(Coord_Y), nowdir(dir) {}
	Unit():Coord_X(0), Coord_Y(0) {};
	~Unit() {};

	//	��������
	void SetCoord_X(int Coord_X);
	void SetCoord_Y(int Coord_Y);

	//��ȡ����
	int GetCoord_X();

	int GetCoord_Y();

	void SetDir(Direction dir);

	Direction GetDir();

	

};

