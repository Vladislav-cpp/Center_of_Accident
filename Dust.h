#pragma once
#include "Object.h"
//#include <iostream>


class Dust :public Object
{
public:
	Dust(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY);
	virtual void shot();
	virtual void movement();
	
private:

	float destination_x = 400;
	float destination_y = 400;

};
