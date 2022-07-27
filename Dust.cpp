#include "Dust.h"


Dust::Dust(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
	int distance_animation, int number_frames, float position_X, float position_Y, float pos_target_X, float pos_target_Y)

	:pos_target_X(pos_target_X), pos_target_Y(pos_target_Y), Player(file_name, image_coordinate_x, image_coordinate_y, image_width, image_height, distance_animation, number_frames,
		position_X, position_Y) 
{
	name = "Dust";
	Sprite_Player.setScale(sf::Vector2f(0.5f,0.5f));
	Sprite_Player.setOrigin(75, 75);
	Sprite_Player.setPosition(position_X , position_Y );

}



void Dust::movement(float time)
{
	time /= speed_movement;

	//відстань до обєкта якого ми рухаємось
	float distance = sqrt( pow (pos_target_X - position_X ,2) +pow(pos_target_Y - position_Y,2)  );

	if (distance<5) return; //задля забагуавння на місті огранічцєм
	
	position_X += time  * (pos_target_X - position_X ) / distance;//( destination_x - position_X ) / distance 
	position_Y += time  * (pos_target_Y - position_Y ) / distance;//нормалізіція вектора/ 10 замінити на time /!!!!!!
	
	Sprite_Player.setPosition(sf::Vector2f(position_X,  position_Y));
}

bool Dust::collision(float x, float y)
{
	//за допомогою 2 еліпсів перевіряємо колізію  .1406.25 , 121 , 210.25 , 900 коефіцієнти еліпса !!!!!!! замінити на змінні
	if ( 
		 ( pow(x - position_X , 2) / 1406.25 + pow(y - position_Y-2.5 , 2) / 121 <= 1 &&
		   pow(x - position_X , 2) / 1406.25 + pow(y - position_Y -2.5, 2) / 121 >= 0 )
	                                                                                               ||
		 ( pow(x - position_X , 2) / 210.25  + pow(y - position_Y+5, 2) / 900  <= 1 &&
		   pow(x - position_X , 2) / 210.25  + pow(y - position_Y+5 , 2) / 900  >= 0 )


		)
		return true;
	return false;
}

void Dust::set_pos_target(float target_X, float target_Y)
{
	pos_target_X= target_X;
	pos_target_Y= target_Y;
}








//Dust::Dust(std::string file_name, int x, int y, int w, int h, int distance_to_sprite,
//	int count, float posX, float posY, float pos_target_X, float pos_target_Y)
//
//	:(file_name, image_coordinate_x, image_coordinate_y, image_width, image_height, distance_animation, number_frames,
//		position_X, position_Y)
//{
//	position_X = posX;
//	position_Y = posY;
//
//	name = "Dust";
//	Sprite_Player.setScale(sf::Vector2f(0.5f, 0.5f));
//	Sprite_Player.setOrigin(75, 75);
//	Sprite_Player.setPosition(position_X, position_Y);
//
//}
//
//
//void Dust::movement(float time)
//{
//	time /= speed_movement;
//
//	//відстань до обєкта якого ми рухаємось
//	float distance = sqrt(pow(pos_target_X - position_X, 2) + pow(pos_target_Y - position_Y, 2));
//
//	if (distance < 5) return; //задля забагуавння на місті огранічцєм
//
//	position_X += time * (pos_target_X - position_X) / distance;//( destination_x - position_X ) / distance 
//	position_Y += time * (pos_target_Y - position_Y) / distance;//нормалізіція вектора/ 10 замінити на time /!!!!!!
//
//	Sprite_Player.setPosition(sf::Vector2f(position_X, position_Y));
//}
//
//bool Dust::collision(float x, float y)
//{
//	//за допомогою 2 еліпсів перевіряємо колізію  .1406.25 , 121 , 210.25 , 900 коефіцієнти еліпса !!!!!!! замінити на змінні
//	if (
//		(pow(x - position_X, 2) / 1406.25 + pow(y - position_Y - 2.5, 2) / 121 <= 1 &&
//			pow(x - position_X, 2) / 1406.25 + pow(y - position_Y - 2.5, 2) / 121 >= 0)
//		||
//		(pow(x - position_X, 2) / 210.25 + pow(y - position_Y + 5, 2) / 900 <= 1 &&
//			pow(x - position_X, 2) / 210.25 + pow(y - position_Y + 5, 2) / 900 >= 0)
//
//
//		)
//		return true;
//	return false;
//}
//
//void Dust::set_pos_target(float target_X, float target_Y)
//{
//	pos_target_X = target_X;
//	pos_target_Y = target_Y;
//}
