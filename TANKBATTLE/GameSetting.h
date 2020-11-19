#pragma once
#pragma comment(lib,"Winmm.lib")
#include<graphics.h>
#include<conio.h>

//按键监测，参数为键盘的键值，当某按键被按下时返回非0值
#define KEY_DOWN(VK_NONAME) (GetAsyncKeyState(VK_NONAME) & 0x8000)	

//地图大小变量
const int px_size = 8; // 绘制图片存储基本像素大小 8px；
const int map_px = px_size * 4; //地图每一个图片加载大小 32px
const int Bullet_px = 4; //子弹像素大小
const int map_col = 30;//地图行数
const int map_row = 32;//地图列数
const int map_heigh = map_px * map_col;//地图高度像素
const int map_width = map_px * map_row;//地图宽度橡树
const int tank_multy = 2;//坦克放大倍率
//地图大小变量

//目标地址变量
const wchar_t tank_path[] = _T("Res\\Image\\tank.png");//坦克图片素材地址
const wchar_t map_path[] = _T("Res\\Image\\map.png");//地图图片素材地址
const wchar_t bulet_path[] = _T("Res\\Image\\bullet.png");//子弹图片素材地址
const char MapTxt_path[] = ("map.txt");
//目标地址变量

const int FPX = 60;//游戏每秒绘制60次
const int Bullet_max = 10;//每个玩家一次最多拥有10颗子弹，碰撞后销毁一颗
const int Shoot_interval = 3;//射击间隔

//地图类型
typedef enum {
	EMPTY,//空地
	WALL = 0x0F,//砖墙
	IRON,//防爆门
	BORDER,//地图边界
	SEA,//海面
	ICE = 0x20,//冰面
	JUNGLE,//丛林
}map_type;
//地图类型

//敌人等级
typedef enum {
	simple,//简单
	normol,//普通
	hard,//困难
	extreme // 极端
}enemy_level;
//敌人等级

//键盘输入字符
typedef enum {
	KEY_UP = 'W',
	KEY_DOWN = 'S',
	KEY_LEFT = 'A',
	KEY_RIGHT = 'D',
	KEY_SHOOT = 'J',
	KEY_PAUSE = 'P',
	KEY_NULL = 0
}keydown;
//键盘输入字符


