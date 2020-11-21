#include "Bullet.h"

//子弹图片加载函数
void Bullet::Load() {
	IMAGE tmp;
	SetWorkingImage(&tmp);
	loadimage(&tmp, bulet_path, Bullet_px * 4, Bullet_px);
	for (int i = 0; i < 4; i++) {
		getimage(&this->Bullet_pic[i], i * Bullet_px, 0, Bullet_px, Bullet_px);
	}
	SetWorkingImage();
}

//子弹移动函数
void Bullet::move() {
	Direction dir = this->GetDir();
	switch (dir)
	{
	case Up:
		this->SetCoord_Y(Coord_Y - 2);
		break;
	case Left:
		this->SetCoord_X(Coord_X - 2);
		break;
	case Down:
		this->SetCoord_Y(Coord_Y + 2);
		break;
	case Right:
		this->SetCoord_X(Coord_X + 2);
		break;
	default:
		break;
	}
}

bool Bullet::Is_Collision(Map mappic) {
	Direction nowdir = GetDir();
	int x_topleft, y_topleft, x_topright, y_topright, x_lowerleft, y_lowerleft, x_lowerright, y_lowerright;
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



//链尾加一颗子弹
void BulletLink::Push( Bullet newbullet) {
	BulletLink* newBL = this;
	while (newBL->next != nullptr) {
		newBL = newBL->next;
	}
	BulletLink* p = new BulletLink(newbullet);
	newBL->next = p;
}

void BulletLink::show()
{
	BulletLink* p = this->next;
	while (p != nullptr) {
		putimage(p->NewBullet.GetCoord_X(), p->NewBullet.GetCoord_Y(), &p->NewBullet.Bullet_pic[p->NewBullet.GetDir()]);
		p = p->next;
	}
}

void BulletLink::move()
{
	BulletLink* p = this->next;
	while (p != nullptr) {
		p->NewBullet.move();
		p = p->next;
	}
}



//每次访问当前下一颗子弹，如果发生碰撞，就释放该内存空间并且删除；
void BulletLink::Del_next() {
	BulletLink* p = this->next;
	this->next = this->next->next;
	delete p;
}

