#pragma once
#include "Object.h"



class Dust :public Object
{
public:
	Dust(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY);
	 void shot();
	 void movement();
	 bool collision(float x, float y);
	 
private:

	
	float destination_x = 400;
	float destination_y = 400;

};
