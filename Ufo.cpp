#include "Ufo.h"

Ufo::Ufo(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY)
	:Object(t, x, y, w, h, distance_to_sprite, count, posX, posY)
{
//	Sprite_Player.setScale(sf::Vector2f(0.1f, 0.1f));
	Sprite_Player.setPosition(position_X, position_Y);
	
	name = "Ufo";
}


void Ufo::movement()
{
}

bool Ufo::collision(float x, float y)
{
	return false;
}


