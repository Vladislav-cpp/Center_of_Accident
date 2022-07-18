#pragma once
#include "Object.h"


class Ufo :public Object
{
public:
	Ufo(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY);
	
	 void movement();
	bool collision(float x, float y);
private:
	
	
};


