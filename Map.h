#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	//sf::Image Image_map;
	//sf::Texture Texture_map;
	//sf::Sprite Sprite_map;

	const unsigned int windov_width = 700;
	const unsigned int windov_height = 700;
	sf::RenderWindow window;
	sf::CircleShape shape;

public:
	Map();
	void Draw();
};


