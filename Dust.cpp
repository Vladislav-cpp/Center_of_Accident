#include "Dust.h"


Dust::Dust() 
{
	name = "Dust";
	Sprite_Player.setScale(sf::Vector2f(0.1f,0.1f));
}

void Dust::shot()
{
}

void Dust::movement()
{
	float destination_x=400;
	float destination_y=400;

	float distance = sqrt( (destination_x - position_X) * (destination_x - position_X) +
		                (destination_y - position_Y) * (destination_y - position_X) );

	//const int step = 10;

	/*while(position_X<= (destination_x-20) || position_X >= (destination_x + 20))
	{*/

	if (   !(position_X <= (destination_x - 20) || position_X >= (destination_x + 20)) ) return; 

	//std::cout << position_X<< "\n";
	//std::cout << destination_x << "\n";

	position_X += 10 * ( destination_x - position_X ) / distance;
	position_Y += 10 * ( destination_y - position_Y ) / distance;

	Sprite_Player.setPosition(sf::Vector2f(position_X, position_Y));

    //}
}
