#include "Ufo.h"

Ufo::Ufo(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY)
	:Object(t, x, y, w, h, distance, count, posX, posY)
{
//	Sprite_Player.setScale(sf::Vector2f(0.1f, 0.1f));
	//Sprite_Player.setPosition(position_X, position_Y);
	
	name = "Ufo";
}

void Ufo::shot()
{
}

void Ufo::movement()
{
}


