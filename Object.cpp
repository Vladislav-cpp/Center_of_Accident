#include "Object.h"


Object::Object(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int number_frames)
	:life(1), Picture( t,  x, y,  w, h,  distance_to_sprite, number_frames)
	//,x(x),y(y),w(w),h(h), distance_to_sprite(distance_to_sprite), current_frame(0), number_frames(number_frames)
{
	//Sprite_Player.setTexture(t);
	//Sprite_Player.setTextureRect(sf::IntRect(x, y, w, h));
	//Sprite_Player.setPosition(position_X, position_Y);number_pictures
}

//void Object::animation(int time)
//{
//	current_frame += animation_speed *time;
//
//	if (current_frame >= number_frames)  current_frame = 0;
//
//	Sprite_Player.setTextureRect(sf::IntRect(x+ static_cast<int>(current_frame) * distance_to_sprite,y,w,h));
//}
//
//
//void Object::draw(sf::RenderWindow& app)
//{
//	app.draw(Sprite_Player);
//}


