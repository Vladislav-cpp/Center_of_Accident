#pragma once
#include "Picture.h"





class Object :public Picture
{
public:
	Object(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
		int distance_animation, int number_frames,float position_X, float position_Y)

		:life(true), position_X(position_X), position_Y(position_Y), 
		Picture(file_name, image_coordinate_x, image_coordinate_y,  image_width, image_height, distance_animation, number_frames)
	{}


	virtual bool collision(float x, float y) = 0;
	virtual void movement(float time) = 0;

	std::string Get_name() { return name; }
	float Get_position_X() { return position_X; }
	float Get_position_Y() { return position_Y; }

	bool Get_life() { return life; }
	void Set_life(bool life) { this->life = life; }
protected:
	float position_X;
	float position_Y;

	std::string name;

private:
	bool life;

};






