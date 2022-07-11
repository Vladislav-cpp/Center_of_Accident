#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player 
{
public:
	Player(const char* file_name, int rectLeft, int rectTop, int rectWidth, int rectHeight, float posX, float posY, float Xp);
	virtual void shot() = 0;
	virtual void movement() = 0;
	sf::Sprite Get_Sprite()const;

	sf::Sprite Sprite_Player;
private:
	unsigned int Xp=0;
	sf::Texture Texture_Player;
	

};

