#pragma once
//#include "Picture.h"
#include <iostream>
#include "Object.h"



class Player :public Object
{
public:
	Player(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height, 
		int distance_animation, int number_frames, float position_X, float position_Y)

		:Object(file_name, image_coordinate_x, image_coordinate_y, image_width, image_height, distance_animation, number_frames,
			  position_X, position_Y)	{}

  
	bool collision(float x, float y)=0;
	void movement(float time) = 0;

	virtual void set_pos_target(float target_X, float target_Y) = 0;


};



/*
class Player :public Picture
{
public:
	Player(std::string file_name, int x, int y, int w, int h, int distance_to_sprite, int number_frames)
		:life(1), Picture(file_name, x, y, w, h, distance_to_sprite, number_frames) {}

	// virtual ~Object() {};//????

	virtual bool collision(float x, float y) = 0;
	virtual void movement(float time) = 0;

	//void animation(int time);
	//void draw(sf::RenderWindow& app) ;


	bool Get_life() { return life; }
	void Set_life(bool life) { this->life = life; }

private:
	bool life;

};
*/