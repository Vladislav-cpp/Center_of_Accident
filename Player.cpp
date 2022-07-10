#include "Player.h"

Player::Player(const char* file_name, int rectLeft, int rectTop, int rectWidth, int rectHeight, float posX, float posY, float Xp)
	:Xp()
{
	Texture_Player.loadFromFile(file_name);
	Sprite_Player.setTexture(Texture_Player);

	Sprite_Player.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
	Sprite_Player.setPosition(posX, posY);
}

sf::Sprite Player::Get_Sprite() const
{
	return Sprite_Player;
}
