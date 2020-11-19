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
	
	/*while (true) {
		g1.showmap();
		FlushBatchDraw();
		Sleep(20);
		cleardevice();
	}*/
	Player p1(50, 50, Up);
	BulletLink* BL = new BulletLink();
	int time = 0;
	while (true) {
		g1.showmap();
		if (p1.Is_keydown()) {
			keydown key = p1.InputCheck();
			if (key == KEY_SHOOT && time == 0) {
				p1.shoot(BL);
			}		
		}
		BulletLink* p = BL;
		while (p->next != nullptr) {
			p->next->NewBullet.move();
			putimage(p->next->NewBullet.GetCoord_X(), p->next->NewBullet.GetCoord_Y(), &p->next->NewBullet.Bullet_pic[p->next->NewBullet.GetDir()]);
			
			p = p->next;
		}
		if (time < 2)
			time++;
		else time = 0;
		FlushBatchDraw();
		Sleep(33);
		cleardevice();
	}
	
	
	
	
	_getch();
}
