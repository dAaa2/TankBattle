#include "Map.h"

//º”‘ÿµÿÕºÕº∆¨
void Map::LoadPic() {
	IMAGE tmp;
	SetWorkingImage(&tmp);
	loadimage(&tmp, map_path, 8 * 7, 8);
	for (int i = 0; i < 7; i++) {
		getimage(&Map_Pic[i], i * px_size, 0, px_size, px_size);
	}
	SetWorkingImage();
}

void Map::LoadTxt() {
	std::ifstream in;
	in.open("map.txt");
	for (int i = 0; i < map_col; i++) {
		for (int j = 0; j < map_row; j++) {
			in >> std::hex >> Map_txt[i][j];
		}
	}
	in.close();
}

bool Map::FlagSeastate() {
	this->Flag_Sea_state = !this->Flag_Sea_state;
	return this->Flag_Sea_state;
}