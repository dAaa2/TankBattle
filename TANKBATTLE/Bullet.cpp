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

