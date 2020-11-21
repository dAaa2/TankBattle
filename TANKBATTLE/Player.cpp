#include "Player.h"

//实现坦克透明贴图
void Player::TransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor) {
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// 使用 Windows GDI 函数实现透明位图
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

//加载坦克图片
void Player::Load() {
	IMAGE tmp;
	SetWorkingImage(&tmp);
	loadimage(&tmp, tank_path, 16 * 8, 16 * 8);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int z = 0; z < 2; z++) {
				int y_coord = px_size * 2 * i;
				int x_coord = px_size * 2 * (j * 2 + z);
				getimage(&Tank_pic[i][j][z], x_coord, y_coord, px_size * tank_multy, px_size * tank_multy);
			}
		}
	}

	SetWorkingImage();
}

//根据按下按键重新设置坦克位置
void Player::Move(Map mappic, keydown nowkb) {
	
		switch (nowkb)
		{
		case KEY_UP:
			SetCoord_Y(--Coord_Y);
			SetDir(Up);
			if (!Is_Collision(mappic))
				SetCoord_Y(++Coord_Y);
			else Change_State_Flag();
			
			break;
		case KEY_DOWN:
			SetCoord_Y(++Coord_Y);
			SetDir(Down);
			if (!Is_Collision(mappic))
				SetCoord_Y(--Coord_Y);
			else Change_State_Flag();
			break;
		case KEY_LEFT:
			SetCoord_X(--Coord_X);
			SetDir(Left);
			if (!Is_Collision(mappic))
				SetCoord_X(++Coord_X);
			else Change_State_Flag();
			break;
		case KEY_RIGHT:
			SetCoord_X(++Coord_X);
			SetDir(Right);
			if (!Is_Collision(mappic))
				SetCoord_X(--Coord_X);
			else Change_State_Flag();
			break;
		default:
			break;
		}

	
	
}

//移动绘制履带状态检测
bool Player::Change_State_Flag() {
	this->state_flag = !this->state_flag;
	return this->state_flag;
}

bool Player::Get_State_Flag() {
	return this->state_flag;
}

//检测键盘输入值
keydown Player::InputCheck() {
	
		keydown key;
		char ch = _getch();
		switch (ch)
		{
		case 'W':
		case 'w':
			key = KEY_UP;
			break;
		case 'A':
		case 'a':
			key = KEY_LEFT;
			break;
		case 'S':
		case 's':
			key = KEY_DOWN;
			break;
		case 'D':
		case 'd':
			key = KEY_RIGHT;
			break;
		case 'J':
		case 'j':
			key = KEY_SHOOT;
			break;
		case 'P':
		case 'p':
			key = KEY_PAUSE;
			break;
		default:
			key = KEY_NULL;
			break;
		}
		return key;
	
}

//检测键盘是否被按下
bool Player::Is_keydown() {
	if (_kbhit()) 
		return true;
	else 
		return false;
	
}

//碰撞检测
bool Player::Is_Collision(Map mappic) {
	Direction nowdir = GetDir();
	int x_topleft, y_topleft, x_topright, y_topright, x_lowerleft, y_lowerleft, x_lowerright,y_lowerright;
	bool flag = false;
	switch (nowdir)
	{
	case Up:
		if (GetCoord_Y() % px_size == 0)
			flag = true;
		x_topleft = GetCoord_X() / px_size;
		y_topleft = GetCoord_Y() / px_size;
		x_topright = (GetCoord_X() + 16) / px_size - (GetCoord_X() % px_size == 0 ? 1 : 0);
		y_topright = GetCoord_Y() / px_size;
		if ((mappic.Map_txt[y_topleft][x_topleft] == 0 || mappic.Map_txt[y_topleft][x_topleft] == 33 || flag) && (mappic.Map_txt[y_topright][x_topright] == 0 || mappic.Map_txt[y_topright][x_topright] == 33 || flag))
			return true;
		else return false;
		break;
	case Left:
		if ((GetCoord_X()) % px_size == 0)
			flag = true;
		x_topleft = GetCoord_X() / px_size;
		y_topleft = GetCoord_Y() / px_size;
		x_lowerleft = GetCoord_X() / px_size;
		y_lowerleft = (GetCoord_Y() + 16) / px_size - (GetCoord_Y() % px_size == 0 ? 1 : 0);
		if ((mappic.Map_txt[y_topleft][x_topleft] == 0 || mappic.Map_txt[y_topleft][x_topleft] == 33 || flag) && mappic.Map_txt[y_lowerleft][x_lowerleft] == 0 || mappic.Map_txt[y_lowerleft][x_lowerleft] == 33 || flag)
			return true;
		else return false;
		break;
	case Down:
		if (GetCoord_Y() % px_size == 0)
			flag = true;
		x_lowerleft = GetCoord_X() / px_size;
		y_lowerleft = (GetCoord_Y() + 16) / px_size - (GetCoord_Y() % px_size == 0 ? 1 : 0);
		x_lowerright = (GetCoord_X() + 16) / px_size - (GetCoord_X() % px_size == 0 ? 1 : 0);
		y_lowerright = (GetCoord_Y() + 16) / px_size - (GetCoord_Y() % px_size == 0 ? 1 : 0);
		if ((mappic.Map_txt[y_lowerleft][x_lowerleft] == 0 || mappic.Map_txt[y_lowerleft][x_lowerleft] == 33 || flag) && mappic.Map_txt[y_lowerright][x_lowerright] == 0 || mappic.Map_txt[y_lowerright][x_lowerright] == 33 || flag)
			return true;
		else return false;
		break;
	case Right:
		if ((GetCoord_X()) % px_size == 0)
			flag = true;
		x_topright = (GetCoord_X() + 16) / px_size - (GetCoord_X() % px_size == 0 ? 1 : 0);
		y_topright = GetCoord_Y() / px_size;
		x_lowerright = (GetCoord_X() + 16) / px_size;
		y_lowerright = (GetCoord_Y() + 16) / px_size - (GetCoord_Y() % px_size == 0 ? 1 : 0);
		if ((mappic.Map_txt[y_lowerright][x_lowerright] == 0 || mappic.Map_txt[y_lowerright][x_lowerright] == 33 || flag) && mappic.Map_txt[y_topright][x_topright] == 0 || mappic.Map_txt[y_topright][x_topright] == 33 || flag)
			return true;
		else return false;
		break;
	default:
		return false;
		break;
	}
	
}

//射击函数
void Player::shoot(){
	Bullet newbullet;
	switch (GetDir())
	{
	case Up:
		newbullet = Bullet(GetCoord_X() + px_size - Bullet_px / 2, GetCoord_Y(), GetDir());
		break;
	case Left:
		newbullet = Bullet(GetCoord_X(), GetCoord_Y() + px_size - Bullet_px / 2, GetDir());
		break;
	case Down:
		newbullet = Bullet(GetCoord_X() + px_size - Bullet_px / 2, GetCoord_Y() + px_size * 2 - Bullet_px, GetDir());
		break;
	case Right:
		newbullet = Bullet(GetCoord_X() + px_size * 2 - Bullet_px, GetCoord_Y() + px_size - Bullet_px / 2, GetDir());
		break;

	default:
		break;
	}
	BL->Push(newbullet);
}





