#include "Chuck.h"


Chuck::Chuck(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count,

	float direction_X, float direction_Y, float pos_spawn_X, float pos_spawn_Y)
	:Object(t, x, y, w, h, distance_to_sprite, count)
{

	position_X = pos_spawn_X;
	position_Y = pos_spawn_Y;


	name = "Chuck";
	Sprite_Player.setScale(sf::Vector2f(0.2f, 0.2f));

	float distance = sqrt(pow(direction_X - pos_spawn_X, 2) + pow(direction_Y - pos_spawn_Y, 2));

	Sprite_Player.setOrigin(0, h/2);


	direction_movement_X = (direction_X - position_X) / distance;//( posX-400 )/ distance -
	direction_movement_Y = (direction_Y - position_Y) / distance;//нормалізіція вектора

	//якщо 1 і 2 чверть координат робимо коєф кута відємним
      int negative_angle = 1;
	if (direction_movement_X >= 0 && direction_movement_Y < 0 || direction_movement_X <= 0 && direction_movement_Y <= 0)
		negative_angle = -1;

	float angle =  acos(direction_movement_X) * radians_to_degrees;
	Sprite_Player.rotate(negative_angle * angle);

	//float a = 0; 
	//float b = 0; 
	//
	//центруєм спрайт (відносно точкі обертання ). зміщуємо в центр
	//if (direction_movement_X >= 0 && direction_movement_Y > 0) 
	//{
	//	a = sin(angle *  PI /180) * 5;
	//	b = sin((90 - angle) * PI / 180) * -5 ;
	//}
	//if (direction_movement_X > 0 && direction_movement_Y <= 0) 
	//{                      
	//	 a = sin(angle * PI / 180) * -5  ;
	//	 b = sin((90 - angle) * PI / 180) * -5 ;
	//}
	//if (direction_movement_X <= 0 && direction_movement_Y < 0)
	//{    
	//	a = sin( (90- (angle - 90)) * PI / 180) * -5 ;
	//	b = (sin ( (angle  -90) * PI / 180) * 5);
	//}
	//if (direction_movement_X < 0 && direction_movement_Y >= 0) 
	//{
	//	 a = sin( (90 - (angle - 90)) * PI / 180 ) * 5;
	//	 b = sin(  (angle - 90) * PI / 180 ) * 5 ;
	//}
	//position_X = 400 + a;
	//position_Y = 400 + b;

	Sprite_Player.setPosition(position_X, position_Y);
}

void Chuck::movement(float time)
{
	time /= speed_movement;
	
	position_X += time * direction_movement_X;
	position_Y += time * direction_movement_Y;

	if (position_X < 0 || position_X >1300) Set_life(0); //!!!!!!!!!!!!!!!!!!
	if (position_Y < 0 || position_Y >1300) Set_life(0); //!!!!!!!!!!!!!!!!!!

	Sprite_Player.setPosition(position_X, position_Y);
}

bool Chuck::collision(float x, float y)
{
	return false;
}
