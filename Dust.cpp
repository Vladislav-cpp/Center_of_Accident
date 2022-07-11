#include "Dust.h"


Dust::Dust() :Player("Images\\spritesheet.png", 161, 131, 904, 873, 10, 10, 100)
{
	Sprite_Player.setScale(sf::Vector2f(0.1f,0.1f));
}

void Dust::shot()
{
}

void Dust::movement(float destination_x, float destination_y, float time)
{
	float distance = sqrt( (destination_x - position_X) * (destination_x - position_X) +
		                (destination_y - position_Y) * (destination_y - position_X) );

	//const int step = 10;

	/*while(position_X<= (destination_x-20) || position_X >= (destination_x + 20))
	{*/

	if (   !(position_X <= (destination_x - 20) || position_X >= (destination_x + 20)) ) return; 
	std::cout << position_X<< "\n";
	std::cout << destination_x << "\n";

	position_X += time * ( destination_x - position_X ) / distance;
	position_Y += time * ( destination_y - position_Y ) / distance;

	Sprite_Player.setPosition(sf::Vector2f(position_X, position_Y));

    //}
}
