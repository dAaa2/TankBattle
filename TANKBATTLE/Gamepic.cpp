#include "Gamepic.h"

void Gamepic::showmap() {
	for (int i = 0; i < map_col; i++) {
		for (int j = 0; j < map_row; j++) {
			switch (mappic.Map_txt[i][j])
			{
			case 15:
				putimage(j * px_size, i * px_size, &mappic.Map_Pic[0]);//墙体绘制待更改
				break;
			case 16:
				putimage(j * px_size, i * px_size, &mappic.Map_Pic[1]);
				break;
			case 17:
				putimage(j * px_size, i * px_size, &mappic.Map_Pic[2]);
				break;
			case 18:
				putimage(j * px_size, i * px_size, &mappic.Map_Pic[3 + mappic.FlagSeastate()]);
				break;
			case 32:
				putimage(j * px_size, i * px_size, &mappic.Map_Pic[5]);
				break;
			case 33:
				putimage(j * px_size, i * px_size, &mappic.Map_Pic[6]);
				break;

			default:
				break;
			}
		}
	}
	
	if (p1.Is_keydown()) {
		p1.Move(mappic);
		p1.TransparentImage(NULL, p1.GetCoord_X(), p1.GetCoord_Y(), &p1.Tank_pic[0][p1.GetDir()][p1.Get_State_Flag()], BLACK);
	}
	else
		p1.TransparentImage(NULL, p1.GetCoord_X(), p1.GetCoord_Y(), &p1.Tank_pic[0][p1.GetDir()][p1.Get_State_Flag()], BLACK);

}



