#include "Unit.h"

void Unit::SetCoord_X(int Coord_X) {
	this->Coord_X = Coord_X;
}

void Unit::SetCoord_Y(int Coord_Y) {
	this->Coord_Y = Coord_Y;
}

int Unit::GetCoord_X() {
	return this->Coord_X;
}

int Unit::GetCoord_Y() {
	return this->Coord_Y;
}

void Unit::SetDir(Direction dir) {
	this->nowdir = dir;
}

Direction Unit::GetDir() {
	return this->nowdir;
}