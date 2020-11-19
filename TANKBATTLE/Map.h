#pragma once
#include "GameSetting.h"
#include<fstream>
class Map
{
public:
    IMAGE Map_Pic[7];//地图图片存储
    int Map_txt[map_col][map_row];//地图数据存储
    bool Flag_Sea_state;
    Map() {
        LoadPic();
        LoadTxt();
        Flag_Sea_state = false;
    }
    //加载地图图片
    void LoadPic();

    //加载地图文件
    void LoadTxt();

    //子弹碰撞后重新设置地图值
    void SetMaptxt(int num);

    //海洋动态绘制
    bool FlagSeastate();
};
