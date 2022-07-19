#pragma once
#include "Object.h"




class Chuck : public Object
{
public:
	Chuck(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY);

	void movement(float time);
	bool collision(float x, float y);//убрать колізцю !!!!!!!!!!!!!!!!!!!!

private:

	float direction_movement_X;
	float direction_movement_Y;
	static constexpr double PI = 3.141592653589793;
};

