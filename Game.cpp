#include "Game.h"


Game::Game(int number_opponents) :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident", sf::Style::Default)
, number_opponents(number_opponents), shoot(shotBuffer), explosion(explosionBuffer)
 
{
	std::srand(time(NULL));

	

	//Tbackground.loadFromFile("images/cloudsLarge1.png");          Tbackground.setSmooth(true); bg_4096x2048.png
	Tbackground.loadFromFile("images/pngwing.com (1).png");            Tbackground.setSmooth(true);
	TDust.loadFromFile("images/Ufos.png");                      //TDust.setSmooth(true);
	TUfo.loadFromFile("images/ufo.png");                        //TUfo.setSmooth(true);
	TChuck.loadFromFile("images/14.png");                       //TChuck.setSmooth(true);

	
	Sprite_map.setTexture(Tbackground);
	Sprite_map.setTextureRect(sf::IntRect(0, 0, 4096, 2048));
	Sprite_map.setPosition(0, 0);

	shotBuffer.loadFromFile("sound and music/shot.ogg");
	explosionBuffer.loadFromFile("sound and music/explosion.ogg");
	music.openFromFile("sound and music/background music.ogg");

	window.setFramerateLimit(number_of_fps);

	cursor.loadFromSystem(sf::Cursor::Arrow);//написати прицел вместо курсора 
	window.setMouseCursor(cursor);

}





void Game::Run()
{

	
		//створення обєкта класа Ufo в центрі вікна 
		Ufo* uf = new Ufo(TUfo, 2, 2, 97, 97, 100, 20, pos_spawn_ufo_X, pos_spawn_ufo_Y);
		object.push_back(uf);


	int number_Dust = 0;

	music.play();
	music.setLoop(true);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		float recharge_time = clock_recharge.getElapsedTime().asMilliseconds();
	    clock.restart();

		//створення обєктив класа Dust в рандомних позиціях по окружності
		number_Dust = 0;
		for (auto i : object)
			if (i->Get_name() == "Dust") number_Dust++;

		while( number_Dust < number_opponents )
		{
		
			int tmp_angle_R = rand() % 360;
			respawn_dust_x = windov_width/2 + radius_spawn_dust_X * cos(tmp_angle_R * radians_to_degrees);
			respawn_dust_y = windov_height/2 + radius_spawn_dust_Y * sin(tmp_angle_R * radians_to_degrees);

			Dust* d = new Dust(TDust, 0, 0, 151, 134, 151, 4, respawn_dust_x, respawn_dust_y, uf->Get_position_X(), uf->Get_position_Y());
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
							explosion.play();
						}
		}

		//якщо нажата мишка !!!!!!!!!!!!!!!
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (recharge_time > recharge)
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				Chuck* ch = new Chuck(TChuck, 29, 46, 182, 50, 0, 0, position.x, position.y, uf->Get_position_X(), uf->Get_position_Y());
				object.push_back(ch);
				shoot.play();

				clock_recharge.restart();
			}
		}

        //видалення обєктів які знищєні
        for (auto i = object.begin(); i != object.end();)
        {
        	Object* e = *i;
        	if  (e->Get_life() == false) { i = object.erase(i); delete e; }
        	else i++;
        }

		window.clear();
		window.draw(Sprite_map);


		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//аніміровання та отрисовка всіх обєктів  які є в листі
		for (auto i : object) 
		{
			i->animation(time);
			i->draw(window);
        }
		
		window.display();

	}
}



