#include "Ufo.h"

//Ufo::ufo(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
//	int distance_animation, int number_frames, float position_x, float position_y)

	Ufo::Ufo(float pos_spawn_ufo_X, float pos_spawn_ufo_Y)

	: Player(std::string("Ufo"), std::string("images/ufo.png"),
		2, 2, 97, 97, 100, 20, pos_spawn_ufo_X, pos_spawn_ufo_Y)
{
	animation_speed = 0.04;
	//name = "Ufo";
	Sprite_Player.setOrigin(48,48);
	Sprite_Player.setPosition(position_X, position_Y);
}


void Ufo::movement(float time)
{
	time /= speed_movement;
	float tmp_X = position_X;
	float tmp_Y = position_Y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { position_X -=  time;  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { position_X +=  time;  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    { position_Y -=  time;  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { position_Y += time;   }

	if (position_X <= 0 || position_X >= 3000) position_X = tmp_X; //!!!!!!!! 3000 ³ רמ צו חא צטפנט
	if (position_Y <= 0 || position_Y >= 2000) position_Y = tmp_Y;  //!!!!!!! 2000 ?
	Sprite_Player.setPosition(position_X, position_Y);
}

bool Ufo::collision(float x, float y)
{



	if (pow(x - position_X, 2) + pow(y - position_Y, 2) <= 8000)
		return true;
	return false;
}

//float Ufo::Get_pos_Y() const
//{
//	return (position_Y);
//}
//
//float Ufo::Get_pos_X() const
//{
//	return (position_X);
//}

float Ufo::Get_pos_window_Y() const
{
	return 0.0f;
}

float Ufo::Get_pos_window_X() const
{
	return 0.0f;
}
