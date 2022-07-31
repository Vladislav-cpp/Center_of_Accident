#pragma once
//#include "Picture.h"
#include <iostream>
#include "Object.h"



class Player :public Object
{
public:
	Player(std::string object_name, std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
		int distance_animation, int number_frames, float position_X, float position_Y)

		:Object(object_name,file_name, image_coordinate_x, image_coordinate_y, image_width, image_height, distance_animation, number_frames,
			  position_X, position_Y)	{}

  
	bool collision(float x, float y)=0;
	void movement(float time) = 0;

	virtual void set_pos_target(float target_X, float target_Y) = 0;


};



