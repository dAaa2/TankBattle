#pragma once
#include "Unit.h"
#include"Map.h"
#include"Player.h"
#include"Bullet.h"
class Gamepic
{
public:
    Map mappic;
    Player p1;
   
    Gamepic(){}
    //���Ƶ�ͼ
    void showmap();

    //��ײ���
    bool Is_Collision();
};

