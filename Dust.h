#pragma once
#include "Player.h"



class Dust :public Player
{
public:
	Dust(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
		int distance_animation, int number_frames, float position_X, float position_Y, float pos_target_X, float pos_target_Y);
	 
	 void movement(float time);
	 bool collision(float x, float y);
	 void set_pos_target(float target_X, float target_Y);
	 
private:

	float speed_movement = 15;
	float pos_target_X;
	float pos_target_Y;

};


//
//class Dust :public Player
//{
//public:
//	Dust(std::string file_name, int x, int y, int w, int h, int distance_to_sprite,
//		int count, float posX, float posY, float pos_target_X, float pos_target_Y);
//
//	void movement(float time);
//	bool collision(float x, float y);
//	void set_pos_target(float target_X, float target_Y);
//
//private:
//
//	float speed_movement = 15;
//	float pos_target_X;
//	float pos_target_Y;
//
//};