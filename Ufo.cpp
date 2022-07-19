#include "Ufo.h"

Ufo::Ufo(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY)
	:Object(t, x, y, w, h, distance_to_sprite, count, posX, posY)
{
	name = "Ufo";
	Sprite_Player.setPosition(position_X, position_Y);
}


void Ufo::movement(float time)
{
}

bool Ufo::collision(float x, float y)
{
	if (pow(x - 400, 2) + pow(y - 400, 2) <= 95)
		return true;
	return false;
}


