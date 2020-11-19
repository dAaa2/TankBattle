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
    //����ͼƬ
    void Load();

    //�ƶ�����
    void Move(Map mappic);

    //����͸����ͼ
    void TransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
    //�������Ƿ���
    bool Is_keydown();
    //���̰��º��ⰴ�µ�Ԫ��
    keydown InputCheck();

    //�ı��ȡstate_flag����
    bool Change_State_Flag();
    bool Get_State_Flag();

    //��ײ���
    bool Is_Collision(Map mappic);

    //�������
    void shoot(BulletLink *BL);
};

