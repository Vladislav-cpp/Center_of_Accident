#include "Chuck.h"


Chuck::Chuck(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY)
	:Object(t, x, y, w, h, distance_to_sprite, count, posX, posY)
{
	name = "Chuck";
	Sprite_Player.setScale(sf::Vector2f(0.2f, 0.2f));

	float distance = sqrt(pow(posX - 400, 2) + pow(posY - 400, 2));
	direction_movement_X = (posX - 400) / distance;
	direction_movement_Y = (posY - 400) / distance;

	//direction_movement_X = posX / (sqrt(pow(posX, 2) + pow(posY, 2))) ;
	//direction_movement_Y = posY / (sqrt(pow(posY, 2) + pow(posY, 2)));
	//
	std::cout << "direction_movement_X  " << direction_movement_X << "\n";
	std::cout << "direction_movement_Y  " << direction_movement_Y << "\n";

	//std::cout << direction_movement_X << "\n";
	std::cout << "acos(direction_movement_X)* 57.296)  "<< acos(direction_movement_X) * 180/ PI << "\n" << "\n";
	int negative_angle = 1;
	if ( direction_movement_X >= 0 && direction_movement_Y < 0
	                                                               ||
	     direction_movement_X <= 0 && direction_movement_Y <= 0 )
		negative_angle = -1;
	//if (direction_movement_Y > 0) negative_angle = -1;

	//Sprite_Player.setRotation(negative_angle*acos(direction_movement_X) * 180 / PI);//* PI / 180
	Sprite_Player.rotate(negative_angle * acos(direction_movement_X) * 180 / PI);
	//Sprite_Player.rotate(340);

	Sprite_Player.setPosition(400, 400);//!!!!!
	


}

void Chuck::movement()
{
	position_X += 10 * direction_movement_X; //( posX-400 )/ distance 
	position_Y += 10 * direction_movement_Y; //нормалізіція вектора/ 10 замінити на time /!!!!!!

	
	if (position_X < 0 || position_X >800) return; //!!!!!
	if (position_Y < 0 || position_Y >800) return; //!!!!!

	Sprite_Player.setPosition(position_X, position_Y);
		std::cout << "if (   !---------------------------------------------------------"<< "\n";
}

bool Chuck::collision(float x, float y)
{
	return false;
}
