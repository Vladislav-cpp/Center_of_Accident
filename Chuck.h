#pragma once
//#include "Player.h"
#include "Object.h"




class Chuck : public Object
{
public:
	Chuck(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
		int distance_animation, int number_frames, float direction_X, float direction_Y, float position_X, float position_Y);

	void movement(float time);
	bool collision(float x, float y);//!!!!!!!!!!!!!!

private:
	float speed_movement = 1.5;
	float direction_movement_X;
	float direction_movement_Y;
	
	static constexpr double radians_to_degrees = 57.2958;
};

//class Chuck : public Player
//{
//public:
//	Chuck(std::string file_name, int x, int y, int w, int h, int distance_to_sprite, int count,
//		float direction_X, float direction_Y, float pos_spawn_X, float pos_spawn_Y);
//
//	void movement(float time);
//	bool collision(float x, float y);//!!!!!!!!!!!!!!
//
//private:
//	float speed_movement = 1.5;
//	float direction_movement_X;
//	float direction_movement_Y;
//
//	static constexpr double radians_to_degrees = 57.2958;
//};
