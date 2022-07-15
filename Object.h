#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Object
{
public:
	Object(){};

	void settings(sf::Texture& t, int x, int y, int w, int h, int count, float posX, float posY);

	virtual void movement() = 0;

	void draw(sf::RenderWindow& app);
	
	void animation( int x, int y, int w, int h, int count);//!!!!!!!

protected:
	sf::Texture Texture_Player;
    sf::Sprite Sprite_Player;

	int x, y, w, h;

	float position_X;
	float position_Y;
	bool life;
	std::string name;

};

