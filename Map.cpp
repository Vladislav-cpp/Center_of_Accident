#include "Map.h"


Map::Map() :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident")
{
	//Image_map.loadFrom("Center_of_Accident\Image\clouds2.1Large.png");
	Texture_map.loadFromFile("Images\\cloudsLarge1.png");
	Sprite_map.setTexture(Texture_map);

	Sprite_map.setTextureRect(sf::IntRect(0, 0, 800, 800));
	Sprite_map.setPosition(0,0);

	
}

void Map::Draw(sf::Sprite Ob1, sf::Sprite Ob2)
{

	window.clear();
	window.draw(Sprite_map);
	window.draw(Ob1);
	window.draw(Ob2);
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