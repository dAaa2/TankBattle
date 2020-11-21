#pragma once
#include"Map.h"
#include"Player.h"
#include"Gamepic.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include"Bullet.h"






int main() {
	initgraph(map_width, map_heigh);
	setbkcolor(BLACK);
	cleardevice();
	Gamepic g1;
	
	setaspectratio(4, 4);
	BeginBatchDraw();
	g1.showmap();
	g1.p1.shoot();
	
	while (true) {
		g1.showmap();

		FlushBatchDraw();
		Sleep(35);
		cleardevice();
	}

	
	system("pause");
}
