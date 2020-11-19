#pragma once
#include "Tank.h"
#include"Map.h"
class Player :
    public Tank
{
public:
   
    Player( int Coord_X, int Coord_Y, Direction dir) :Tank(Coord_X, Coord_Y, dir) {
        Load();
    }
    Player():Tank(16, 16, Up) {
        Load();
    }
    //加载图片
    void Load();

    //移动函数
    void Move(Map mappic);

    //绘制透明贴图
    void TransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
    //检测键盘是否按下
    bool Is_keydown();
    //键盘按下后检测按下的元素
    keydown InputCheck();

    //改变获取state_flag函数
    bool Change_State_Flag();
    bool Get_State_Flag();

    //碰撞检测
    bool Is_Collision(Map mappic);

    //射击函数
    void shoot(BulletLink *BL);
};

