#pragma once
#include "GameSetting.h"
#include<fstream>
class Map
{
public:
    IMAGE Map_Pic[7];//��ͼͼƬ�洢
    int Map_txt[map_col][map_row];//��ͼ���ݴ洢
    bool Flag_Sea_state;
    Map() {
        LoadPic();
        LoadTxt();
        Flag_Sea_state = false;
    }
    //���ص�ͼͼƬ
    void LoadPic();

    //���ص�ͼ�ļ�
    void LoadTxt();

    //�ӵ���ײ���������õ�ͼֵ
    void SetMaptxt(int num);

    //����̬����
    bool FlagSeastate();
};
