#pragma once

#include "Picture.h"
#include <iostream>


class Object :public Picture
{
public:
	Object(std::string file_name, int x, int y, int w, int h, int distance_to_sprite, int number_frames)
		:life(1), Picture(file_name, x, y, w, h, distance_to_sprite, number_frames)	{}
	
   // virtual ~Object() {};//????
    
	virtual bool collision(float x, float y)=0;
	virtual void movement(float time) = 0;

	//void animation(int time);
	//void draw(sf::RenderWindow& app) ;


	bool Get_life()        { return life; }
	void Set_life(bool life) { this->life = life; }

private:
	bool life;

};

