#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	//sf::Image Image_map;
	sf::Texture Texture_map;
	sf::Sprite Sprite_map;

	const unsigned int windov_width = 800;
	const unsigned int windov_height = 800;
	sf::RenderWindow window;
	

public:
	Map();
	void Draw(sf::Sprite, sf::Sprite);
};


