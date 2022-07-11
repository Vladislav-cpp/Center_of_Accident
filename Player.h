#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player 
{
public:
	Player(const char* file_name, int rectLeft, int rectTop, int rectWidth, int rectHeight, float posX, float posY, float Xp);

	virtual void shot() = 0;
	virtual void movement(float , float) = 0;

	sf::Sprite Get_Sprite()const;
	//float Get_posX() const { return position_X;}
	//float Get_posY() const { return position_Y;}

	
protected:
	sf::Texture Texture_Player;
    sf::Sprite Sprite_Player;

    unsigned int Xp=0;
	float position_X;
	float position_Y;

};

