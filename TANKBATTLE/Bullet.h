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

//�ӵ����ṹ������һ���ӵ�����һ���ӵ���ַ 
struct BulletLink
{
    Bullet NewBullet;
    BulletLink* next;
    BulletLink(Bullet NewBullet) :NewBullet(NewBullet), next(nullptr) {}
    BulletLink():next(nullptr),NewBullet() {}
    void Del_next();//ɾ����ǰλ���ӵ�
    void Push(Bullet newbullet);//��β��һ���ӵ�
    void show();
    void move();
    
};




