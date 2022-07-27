#include "Ufo.h"

Ufo::Ufo(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
	int distance_animation, int number_frames, float position_X, float position_Y)

	:Player(file_name, image_coordinate_x, image_coordinate_y, image_width, image_height, distance_animation, number_frames,
		position_X, position_Y)
{
	animation_speed = 0.04;
	name = "Ufo";
	Sprite_Player.setOrigin(48,48);
	Sprite_Player.setPosition(position_X, position_Y);
}


void Ufo::movement(float time)
{
	time /= speed_movement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { position_X -=  time;  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { position_X +=  time;  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    { position_Y -=  time;  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { position_Y += time;   }

	Sprite_Player.setPosition(position_X, position_Y);
}

bool Ufo::collision(float x, float y)
{



	if (pow(x - position_X, 2) + pow(y - position_Y, 2) <= 8000)
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


//Ufo::Ufo(std::string file_name, int x, int y, int w, int h, int distance_to_sprite, int count, float pos_spawn_X, float pos_spawn_Y)
//	:Player(file_name, x, y, w, h, distance_to_sprite, count)
//{
//	position_X = pos_spawn_X;
//	position_Y = pos_spawn_Y;
//	animation_speed = 0.04;
//	name = "Ufo";
//	Sprite_Player.setOrigin(48, 48);
//	Sprite_Player.setPosition(position_X, position_Y);
//}
//
//
//void Ufo::movement(float time)
//{
//	time /= speed_movement;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { position_X -= time; }
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { position_X += time; }
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { position_Y -= time; }
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { position_Y += time; }
//
//	Sprite_Player.setPosition(position_X, position_Y);
//}
//
//bool Ufo::collision(float x, float y)
//{
//
//
//
//	if (pow(x - position_X, 2) + pow(y - position_Y, 2) <= 8000)
//		return true;
//	return false;
//}
//
//float Ufo::Get_pos_Y() const
//{
//	return (position_Y);
//}
//
//float Ufo::Get_pos_X() const
//{
//	return (position_X);
//}