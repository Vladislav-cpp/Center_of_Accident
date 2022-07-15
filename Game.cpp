#include "Game.h"


Game::Game(int number_opponents) :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident")
{
	

	Tbackground.loadFromFile("images/cloudsLarge1.png");          Tbackground.setSmooth(true);
	TDust.loadFromFile("images/DustCreatureSpritesheet.png");
	TUfo.loadFromFile("images/Ufo.png");

	Sprite_map.setTexture(Tbackground);
	Sprite_map.setTextureRect(sf::IntRect(0, 0, 800, 800));
	Sprite_map.setPosition(0, 0);

    window.setFramerateLimit(60);

	for (int i = 0; i < number_opponents; i++)
	{
		Dust* d = new Dust();

		d->settings(TDust, 161, 131, 904, 873, 10, 10, 10);//!!!!("Dust", 161, 131, 904, 873, 10,??? , ??? );

		object.push_back(d);
	}

	Ufo* u = new Ufo();
	u->settings(TUfo, 3, 3, 92, 92, 25, 400 - 92 / 2, 400 - 92 / 2);
	object.push_back(u);

}

//:Object("Images\\Ufo.png", 3, 3, 92, 92, 400 - 92 / 2, 400 - 92 / 2, 1000)
//:Object("Images\\spritesheet.png", 161, 131, 904, 873, 10, 10, 100)



void Game::Run()
{

	//sf::Clock clock;


	while (1)
	{

		std::cout << "45" << "\n";
		for (auto i = object.begin(); i != object.end();)
		{
			Object* e = *i;

			e->movement();
			i++;
		}

		std::cout << "53" << "\n";

		window.clear();
		window.draw(Sprite_map);

		for (auto i : object) i->draw(window);

		window.display();
		std::cout << "61" << "\n";









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



