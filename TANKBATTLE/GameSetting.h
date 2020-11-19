#pragma once
#pragma comment(lib,"Winmm.lib")
#include<graphics.h>
#include<conio.h>

//������⣬����Ϊ���̵ļ�ֵ����ĳ����������ʱ���ط�0ֵ
#define KEY_DOWN(VK_NONAME) (GetAsyncKeyState(VK_NONAME) & 0x8000)	

//��ͼ��С����
const int px_size = 8; // ����ͼƬ�洢�������ش�С 8px��
const int map_px = px_size * 4; //��ͼÿһ��ͼƬ���ش�С 32px
const int Bullet_px = 4; //�ӵ����ش�С
const int map_col = 30;//��ͼ����
const int map_row = 32;//��ͼ����
const int map_heigh = map_px * map_col;//��ͼ�߶�����
const int map_width = map_px * map_row;//��ͼ�������
const int tank_multy = 2;//̹�˷Ŵ���
//��ͼ��С����

//Ŀ���ַ����
const wchar_t tank_path[] = _T("Res\\Image\\tank.png");//̹��ͼƬ�زĵ�ַ
const wchar_t map_path[] = _T("Res\\Image\\map.png");//��ͼͼƬ�زĵ�ַ
const wchar_t bulet_path[] = _T("Res\\Image\\bullet.png");//�ӵ�ͼƬ�زĵ�ַ
const char MapTxt_path[] = ("map.txt");
//Ŀ���ַ����

const int FPX = 60;//��Ϸÿ�����60��
const int Bullet_max = 10;//ÿ�����һ�����ӵ��10���ӵ�����ײ������һ��
const int Shoot_interval = 3;//������

//��ͼ����
typedef enum {
	EMPTY,//�յ�
	WALL = 0x0F,//שǽ
	IRON,//������
	BORDER,//��ͼ�߽�
	SEA,//����
	ICE = 0x20,//����
	JUNGLE,//����
}map_type;
//��ͼ����

//���˵ȼ�
typedef enum {
	simple,//��
	normol,//��ͨ
	hard,//����
	extreme // ����
}enemy_level;
//���˵ȼ�

//���������ַ�
typedef enum {
	KEY_UP = 'W',
	KEY_DOWN = 'S',
	KEY_LEFT = 'A',
	KEY_RIGHT = 'D',
	KEY_SHOOT = 'J',
	KEY_PAUSE = 'P',
	KEY_NULL = 0
}keydown;
//���������ַ�


