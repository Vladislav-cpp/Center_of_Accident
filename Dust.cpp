#include "Dust.h"


Dust::Dust(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY)
:Object(t,  x,  y,  w,  h,  distance,  count,  posX,  posY)
{
	name = "Dust";
	Sprite_Player.setScale(sf::Vector2f(0.5f,0.5f));
	Sprite_Player.setPosition(position_X - 37.5, position_Y - 37.5);
}

void Dust::shot()
{
}

void Dust::movement()
{
	float distance = sqrt( pow (destination_x - position_X ,2) +pow(destination_y - position_Y,2)  );

	//std::cout << "distance = " << distance << "\n";
	//std::cout <<" position_X - 40(!)"<< position_X - 40 << "\n";
	//std::cout <<" position_Y - 30(!)"<< position_Y - 30 << "\n" ;
	//std::cout << "position_X <= (destination_x - 10) -> " << destination_x -10 << "\n";
	//std::cout << "position_X <= (destination_x + 10) -> " << destination_x +10<< "\n" << "\n";

	if (distance<5) return;
	//std::cout << "if (   !---------------------------------------------------------"<< "\n";
	
	position_X += 10 * ( destination_x - position_X ) / distance;
	position_Y += 10 * ( destination_y - position_Y ) / distance;
	
	Sprite_Player.setPosition(sf::Vector2f(position_X- 37.5, position_Y- 37.5));

	//std::cout << position_X - 40 << "\n";
 //   std::cout << position_Y - 30 << "\n" << "\n";
}

bool Dust::collision(float x, float y)//є баг колізія дирява
{
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


