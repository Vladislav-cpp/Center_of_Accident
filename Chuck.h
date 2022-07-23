#pragma once
#include "Object.h"




class Chuck : public Object
{
public:
	Chuck(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY);

	void movement(float time);
	bool collision(float x, float y);//!!!!!!!!!!!!!!

private:
	float speed_movement = 1.5;
	float direction_movement_X;
	float direction_movement_Y;
	
	static constexpr double degrees_to_radians = 57.2958;
};

