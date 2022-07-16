#include "Object.h"




//void Object::settings(sf::Texture& t, int x, int y, int w, int h,int distance, int count, float posX, float posY)
//{
//
//	Sprite_Player.setTexture(t);
//
//	life = 1;
//	position_X = posX;
//	position_Y = posY;
//	this->x	=x;
//	this->y	=y;
//	this->w	=w;
//	this->h	=h;
//	this->distance = distance;
//}
Object::Object(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY)
	:life(1), position_X(posX),position_Y(posY),x(x),y(y),w(w),h(h), distance(distance), frame(0), count(count)
{
	Sprite_Player.setTexture(t);
	Sprite_Player.setTextureRect(sf::IntRect(x, y, w, h));
	//Sprite_Player.setPosition(position_X, position_Y);
}

void Object::animation()
{
	// x y w h distance count
	frame++;
	if (frame >= count)  frame = 0;
	
	Sprite_Player.setTextureRect(sf::IntRect(x+ frame* distance,y,w,h));
	
}



void Object::draw(sf::RenderWindow& app)
{
	app.draw(Sprite_Player);
}


