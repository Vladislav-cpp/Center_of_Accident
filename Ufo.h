#pragma once
#include "Object.h"


class Ufo :public Object
{
public:
	Ufo(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY);
	virtual void shot();
	virtual void movement();
private:
	
	
};


