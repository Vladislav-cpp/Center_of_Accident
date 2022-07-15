#include "Object.h"




void Object::settings(sf::Texture& t, int x, int y, int w, int h,int count, float posX, float posY)
{

	Sprite_Player.setTexture(t);

	life = 1;
	position_X = posX;
	position_Y = posY;
	this->x	=x;
	this->y	=y;
	this->w	=w;
	this->h	=h;

}

void Object::draw(sf::RenderWindow& app)
{
	app.draw(Sprite_Player);
}

void Object::animation(int x, int y, int w, int h, int count)
{
}
