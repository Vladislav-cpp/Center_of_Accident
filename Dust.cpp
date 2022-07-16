#include "Dust.h"


Dust::Dust(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY)
:Object(t,  x,  y,  w,  h,  distance,  count,  posX,  posY)
{
	name = "Dust";
	Sprite_Player.setScale(sf::Vector2f(0.5f,0.5f));
	Sprite_Player.setPosition(position_X - 40, position_Y - 30);
}

void Dust::shot()
{
}

void Dust::movement()
{
	float destination_x=400;
	float destination_y=400;

	float distance = sqrt( (destination_x - position_X) * (destination_x - position_X) +
		                   (destination_y - position_Y) * (destination_y - position_Y) );


	//std::cout << "distance = " << distance << "\n";
	//std::cout <<" position_X - 40(!)"<< position_X - 40 << "\n";
	//std::cout <<" position_Y - 30(!)"<< position_Y - 30 << "\n" ;
	//std::cout << "position_X <= (destination_x - 10) -> " << destination_x -10 << "\n";
	//std::cout << "position_X <= (destination_x + 10) -> " << destination_x +10<< "\n" << "\n";

	if (distance<10) return;

	//std::cout << "if (   !---------------------------------------------------------"<< "\n";
	

	position_X += 10 * ( destination_x - position_X ) / distance;
	position_Y += 10 * ( destination_y - position_Y ) / distance;

	Sprite_Player.setPosition(sf::Vector2f(position_X-40, position_Y-30));

	std::cout << position_X - 40 << "\n";
    std::cout << position_Y - 30 << "\n" << "\n";


   
}
