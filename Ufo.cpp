#include "Ufo.h"

Ufo::Ufo(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count)
	:Object(t, x, y, w, h, distance_to_sprite, count)
{
	position_X = 352;
	position_Y = 352;
	animation_speed = 0.04;
	name = "Ufo";
	Sprite_Player.setPosition(position_X, position_Y);
}


void Ufo::movement(float time)
{
}

bool Ufo::collision(float x, float y)
{
	if (pow(x - position_X, 2) + pow(y - position_Y, 2) <= 95)
		return true;
	return false;
}


