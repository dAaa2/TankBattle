#pragma once
#include "Unit.h"
#include"Map.h"
#include"GameSetting.h"
#include"Bullet.h"
#pragma comment( lib, "MSIMG32.LIB")
class Tank :
    public Unit
{
public:
    IMAGE Tank_pic[4][4][2];//���ֵȼ� * ���ַ��� * ������̬
    bool state_flag;//��ǰ�Ĵ�״̬ falseΪͼ1�� trueΪͼ2
    Tank(int Coord_X, int Coord_Y, Direction dir) :Unit(Coord_X, Coord_Y, dir),state_flag(false) {}
    Tank(Direction dir):Unit(dir), state_flag(false) {}
    Tank():Unit(Up), state_flag(false) {}
    ~Tank() {}
    virtual void Move(Map mappic) = 0;
    virtual void Load() = 0;
    virtual keydown InputCheck() = 0;
    virtual bool Change_State_Flag() = 0;
    virtual bool Get_State_Flag() = 0;
    virtual bool Is_Collision(Map mappic) = 0;
    virtual void shoot(BulletLink *BL) = 0;
    
};
