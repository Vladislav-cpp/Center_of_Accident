#pragma once
#include "Object.h"



class Dust :public Object
{
public:
	Dust(std::string file_name, int x, int y, int w, int h, int distance_to_sprite,
		int count, float posX, float posY, float pos_target_X, float pos_target_Y);
	 
	 void movement(float time);
	 bool collision(float x, float y);
	 
private:

	float speed_movement = 15;
	float destination_x;
	float destination_y;

};
