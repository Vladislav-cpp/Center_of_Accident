#include "Map.h"


Map::Map() :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident"), shape(100.f)
{
	//Image_map.loadFromFile("F:\VS\Center_of_Accident\Image\clouds2.1Large.png");
	//Texture_map.loadFromImage(Image_map);
	//Sprite_map.setTexture(Texture_map);

	shape.setFillColor(sf::Color::Green);
}

void Map::Draw()
{

	window.clear();
	window.draw(shape);
	window.display();
}

//while (window.isOpen())
//{
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window.close();
//	}
//
//	window.clear();
//	window.draw(shape);
//	window.display();
//}