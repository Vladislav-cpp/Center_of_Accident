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


    //створення обєктив класа Dust в рандомних позиціях по окружності
	for (int i = 0; i < number_opponents;i++)	
	{

			R = rand() % 360;

			//std::cout << "x" << 400 + 400 * cos(R * PI / 180) << std::endl;
			//std::cout << "y"<< 400 + 400 * sin(R * PI / 180) << std::endl << std::endl;

			x = 400 + 400 * cos(R * PI / 180);
			y = 400 + 400 * sin(R * PI / 180);

			Dust* d = new Dust(TDust, 0, 0, 151, 134, 151, 4, x, y);
			object.push_back(d);

	}


	//створення обєкта класа Ufo в центрі вікна 
	//Ufo* u = new Ufo(TUfo, 2, 2, 97, 97, 100, 20, 354, 354);
	//object.push_back(u);

}





void Game::Run()
{

	//sf::Clock clock;


	
		


	while (1)
	{


		//якщо нажата мишка і обєкт під мишкою (Dust) то видалити його 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			std::cout << "sf::Mouse::isButtonPressed(sf::Mouse::Left)\n";

			sf::Vector2i position = sf::Mouse::getPosition(window);

			
			for (auto i = object.begin(); i != object.end();)

            {
            	Object* e = *i;
				if (e->name == "Dust")
				{
					if(e->collision(position.x, position.y))
						std::cout << "collision " << position.x << " " << position.y << " position\n\n";
				}
            	i++;
            }

		}


		//визов фун-члена усіх обєктив які є в листі
		 
		for (auto i = object.begin(); i != object.end();)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			Object* e = *i;
			e->movement();
			i++;
		}


		window.clear();
		window.draw(Sprite_map);

		//отрисовка всіх обєктів які є в листі
		for (auto i : object) 
		{
			i->animation();
			i->draw(window);
        }
		
		window.display();
		
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



