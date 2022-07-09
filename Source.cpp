#include <SFML/Graphics.hpp>

int main()
{

	const unsigned int windov_width = 200;
	const unsigned int windov_height = 200;
	sf::RenderWindow window(sf::VideoMode(windov_width,windov_height), "Center_of_Accident");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);




	while (window.isOpen())
	{
		sf::Event event;


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}