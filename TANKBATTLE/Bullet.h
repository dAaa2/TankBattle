#pragma once
#include "Unit.h"


class Bullet :
    public Unit
{
public:
    IMAGE Bullet_pic[4];
    Bullet(int Coord_X, int Coord_Y, Direction dir) :Unit(Coord_X, Coord_Y, dir) {
        Load();
    }
    Bullet(Bullet &bl):Unit(bl.Coord_X, bl.Coord_Y, bl.nowdir) {
        Load();
    }
    Bullet() {
        Load();
    }
    void move();
    void Load();
    bool Is_Collision(Map mappic);
};

//子弹链结构，包含一颗子弹和下一颗子弹地址 
struct BulletLink
{
    Bullet NewBullet;
    BulletLink* next;
    BulletLink(Bullet NewBullet) :NewBullet(NewBullet), next(nullptr) {}
    BulletLink():next(nullptr),NewBullet() {}
    void Del_next();//删除当前位置子弹
    void Push(Bullet newbullet);//链尾加一颗子弹
    void show();
    void move();
    
};




