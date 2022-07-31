#pragma once
#include "Player.h"



class Dust :public Player
{
public:
	Dust(float position_X, float position_Y, float pos_target_X, float pos_target_Y);
	 
	 void movement(float time);
	 bool collision(float x, float y);
	 void set_pos_target(float target_X, float target_Y);
	 
private:

	float speed_movement = 15;
	float pos_target_X;
	float pos_target_Y;

};

