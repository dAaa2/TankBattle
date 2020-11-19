#pragma once
#include "Unit.h"
#include"Map.h"
#include"Player.h"
#include"Bullet.h"
class Gamepic
{
public:
    Map mappic;
    Player p1;
   
    Gamepic(){}
    //»æÖÆµØÍ¼
    void showmap();

    //Åö×²¼ì²â
    bool Is_Collision();
};

