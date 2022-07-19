#include "Game.h"


Game::Game(int number_opponents) :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident")
, number_opponents(number_opponents)
 
{
	

	Tbackground.loadFromFile("images/cloudsLarge1.png");          Tbackground.setSmooth(true);
	TDust.loadFromFile("images/Ufos.png");
	TUfo.loadFromFile("images/ufo.png");
	TChuck.loadFromFile("images/14.png");

	
	Sprite_map.setTexture(Tbackground);
	Sprite_map.setTextureRect(sf::IntRect(0, 0, 800, 800));
	Sprite_map.setPosition(0, 0);

    window.setFramerateLimit(60);
}





void Game::Run()
{

	
		//створення обєкта класа Ufo в центрі вікна 
		Ufo* u = new Ufo(TUfo, 2, 2, 97, 97, 100, 20, 352, 352);
		object.push_back(u);

	int respawn_x;
	int respawn_y;
	int number_Dust = 0;
	while (1)
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float time_recharge = clock_recharge.getElapsedTime().asMicroseconds();
	    clock.restart();

		//створення обєктив класа Dust в рандомних позиціях по окружності
		number_Dust = 0;
		for (auto i : object)
			if (i->Get_name() == "Dust") number_Dust++;

		while( number_Dust < number_opponents )
		{
			R = rand() % 360;

			respawn_x = 400 + 400 * cos(R * 180 / PI);
			respawn_y = 400 + 400 * sin(R * 180 / PI);

			Dust* d = new Dust(TDust, 0, 0, 151, 134, 151, 4, respawn_x, respawn_y);
			object.push_back(d);

			number_Dust++;
		}

		//визов фун-члена усіх обєктив які є в листі
		for (auto i = object.begin(); i != object.end();i++)
		{	
			Object* e = *i;
			//if (e->Get_name() == "Chuck")
			e->movement(time);

            // перевірка колізії обєктив Chuck і Dust
			if (e->Get_name() == "Chuck")
				for (auto i : object)
					if (i->Get_name() == "Dust")
						if (i->collision(e->Get_position_X(), e->Get_position_Y()))
						{
							i->Set_life(0);
							e->Set_life(0);
						}
		}

		//якщо нажата мишка !!!!!!!!!!!!!!!
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (time_recharge > 125000)
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				Chuck* u = new Chuck(TChuck, 29, 46, 182, 50, 0, 0, position.x, position.y);
				object.push_back(u);
				clock_recharge.restart();
			}
		}

        //видалення обєктів які знищєні
        for (auto i = object.begin(); i != object.end();)
        {
        	Object* e = *i;
        	if  (e->Get_life() == 0) { i = object.erase(i); delete e; }
        	else i++;
        }

		window.clear();
		window.draw(Sprite_map);

		//аніміровання та отрисовка всіх обєктів  які є в листі
		for (auto i : object) 
		{
			i->animation();
			i->draw(window);
        }
		
		window.display();

	}
}



