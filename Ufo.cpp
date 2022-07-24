#include "Ufo.h"

Ufo::Ufo(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float pos_spawn_X, float pos_spawn_Y)
	:Object(t, x, y, w, h, distance_to_sprite, count)
{
	position_X = pos_spawn_X;
	position_Y = pos_spawn_Y;
	animation_speed = 0.04;
	name = "Ufo";
	Sprite_Player.setPosition(position_X-48, position_Y-48);
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

float Ufo::Get_pos_Y() const
{
	return (position_Y);
}

float Ufo::Get_pos_X() const
{
	return (position_X);
}


