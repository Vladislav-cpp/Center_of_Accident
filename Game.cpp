#include "Game.h"


Game::Game(int number_opponents) :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident")
 
{
	

	Tbackground.loadFromFile("images/cloudsLarge1.png");          Tbackground.setSmooth(true);
//	TDust.loadFromFile("images/meteorite.png");
	TDust.loadFromFile("images/Ufos.png");
	TUfo.loadFromFile("images/ufo.png");

	Sprite_map.setTexture(Tbackground);
	Sprite_map.setTextureRect(sf::IntRect(0, 0, 800, 800));
	Sprite_map.setPosition(0, 0);

    window.setFramerateLimit(60);

	int x;
	int y;

	for (int i = 0; i < number_opponents;i++)
	{

			R = rand() % 360;
		//R = 90;
			//std::cout << R << std::endl;
			std::cout << "x" << 400 + 400 * cos(R * PI / 180) << std::endl;
			std::cout << "y"<< 400 + 400 * sin(R * PI / 180) << std::endl << std::endl;
			x = 400 + 400 * cos(R * PI / 180);
			y = 400 + 400 * sin(R * PI / 180);

					Dust* d = new Dust(TDust, 0, 0, 151, 134, 151, 4, x, y);
					//Dust* d = new Dust(TDust, 0, 0, 151, 134, 151, 4, x - 80 / 2, y - 60 / 2);
					object.push_back(d);


	}



	//Ufo* u = new Ufo(TUfo, 2, 2, 97, 97, 100, 20, 354, 354);
	//object.push_back(u);

}





void Game::Run()
{

	//sf::Clock clock;


	while (1)
	{

		//std::cout << "45" << "\n";
		for (auto i = object.begin(); i != object.end();)
		{
			Object* e = *i;

			e->movement();
			i++;
		}

		//std::cout << "53" << "\n";

		window.clear();
		window.draw(Sprite_map);

		for (auto i : object) 
		{
			i->animation();
			i->draw(window);
			
        }
		window.display();
		//std::cout << "61" << "\n";









			//float time = clock.getElapsedTime().asMicroseconds();
			//time /= 5000;
	       // clock.restart();
		//map.Draw(our_character.Get_Sprite(), enemy.Get_Sprite());
		//enemy.movement(400,400,time);
		//while (window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window.close(); 
		//}



	}
}



