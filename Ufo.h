#pragma once
#include "Object.h"


class Ufo :public Object
{
public:
	Ufo(std::string file_name, int x, int y, int w, int h, int distance_to_sprite, int count,float pos_spawn_X, float pos_spawn_Y);
	
	 void movement(float time);//!!!!!!!!!!!
     bool collision(float x, float y);
	 float Get_pos_Y()const;
	 float Get_pos_X()const;
private:
	
	
};


