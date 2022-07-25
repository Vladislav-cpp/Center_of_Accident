#include "Game.h"


Game::Game(int number_opponents) :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident", sf::Style::Default)
, number_opponents(number_opponents), shoot(shotBuffer), explosion(explosionBuffer)
 
{
	std::srand(time(NULL));

	


	Tbackground.loadFromFile("images/pngwing.com (1).png");            Tbackground.setSmooth(true);


	Sprite_Tbackground.setTexture(Tbackground);
	Sprite_Tbackground.setTextureRect(sf::IntRect(0, 0, 4096, 2048));
	Sprite_Tbackground.setPosition(0, 0);

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
		Ufo* uf = new Ufo(Ufo_nam, 2, 2, 97, 97, 100, 20, pos_spawn_ufo_X, pos_spawn_ufo_Y);
		object.push_back(uf);

		//створення обєктив класа Dust в рандомних позиціях по окружності
		for (int number_Dust = 0; number_Dust < number_opponents; number_Dust++)
		{

			int tmp_angle_R = rand() % 360;
			respawn_dust_x = windov_width / 2 + radius_spawn_dust_X * cos(tmp_angle_R * radians_to_degrees);
			respawn_dust_y = windov_height / 2 + radius_spawn_dust_Y * sin(tmp_angle_R * radians_to_degrees);

			Dust* d = new Dust(Dust_name, 0, 0, 151, 134, 151, 4, respawn_dust_x, respawn_dust_y, uf->Get_position_X(), uf->Get_position_Y());
			object.push_back(d);

		}

		//створення обєктив класа Picture  (інформаційного вікна)
		//Picture life_ufo();
	//	Picture coin_ufo(Tcoin,0,0,15,15,16,8);
        // coin_ufo.Set_position_XY(10,10);
         

	music.play();
	music.setLoop(true);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		float recharge_time = clock_recharge.getElapsedTime().asMilliseconds();
		float time_create_opponents = clock_create_opponents.getElapsedTime().asMilliseconds();

	    clock.restart();

		//включаєм музику якщо та виключилась
		//if(sf::SoundStream::Status::Paused == music.getStatus()) music.play();

		//створення обєктив класа Dust по кд в рандомних позиціях по окружності 
			if (time_create_opponents > create_opponents) {
				
				int tmp_angle_R = rand() % 360;
				respawn_dust_x = windov_width / 2 + radius_spawn_dust_X * cos(tmp_angle_R * radians_to_degrees);
				respawn_dust_y = windov_height / 2 + radius_spawn_dust_Y * sin(tmp_angle_R * radians_to_degrees);

				Dust* d = new Dust(Dust_name, 0, 0, 151, 134, 151, 4, respawn_dust_x, respawn_dust_y, uf->Get_position_X(), uf->Get_position_Y());
				object.push_back(d);
				
				clock_create_opponents.restart();
			}
			

		

		//визов фун-члена movement та перевірка колізії усіх обєктив які є в листі
		for (auto i = object.begin(); i != object.end();i++)
		{	
			Object* e = *i;
			//if (e->Get_name() == "Chuck")
			e->movement(time);

			// перевірка колізії обєктив Ufo і Dust
			if (e->Get_name() == "Ufo")
				for (auto i : object)
					if (i->Get_name() == "Dust")
						if (e->collision(i->Get_position_X(), i->Get_position_Y()))
						{
							Iw.change_life();//віднвмаєм хп убиваєм портивника
							i->Set_life(false);
							//e->Set_life(0);//!!!!!!!!!!!!!!!!
							//explosion.play(); !!!!!!!!!!!!!!!
						}

            // перевірка колізії обєктив Chuck і Dust
			if (e->Get_name() == "Chuck")
				for (auto i : object)
					if (i->Get_name() == "Dust")
						if (i->collision(e->Get_position_X(), e->Get_position_Y()))
						{
							i->Set_life(false);
							e->Set_life(false);
							explosion.play();
						}
		}

		//якщо нажата мишка !!!!!!!!!!!!!!!
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (recharge_time > recharge)
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				Chuck* ch = new Chuck(Chuck_nam, 29, 46, 182, 50, 0, 0, position.x, position.y, uf->Get_position_X(), uf->Get_position_Y());
				object.push_back(ch);
				shoot.play();

				clock_recharge.restart();
			}
		}

        //видалення обєктів які знищєні та підрахунок очків класа Iw
        for (auto i = object.begin(); i != object.end();)
        {
        	Object* e = *i;
        	if  ( false == e->Get_life() )
			{ 							
				if (e->Get_name() == "Dust")
				Iw.add_points();

				i = object.erase(i); delete e;

			}
        	else i++;
        }

		window.clear();
		window.draw(Sprite_Tbackground);


		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//аніміровання та отрисовка всіх обєктів 
		for (auto i : object) 
		{
			i->animation(time);
			i->draw(window);
        }
		//аніміровання та отрисовка інформаційного вікнa
		Iw.animation(time);
		Iw.draw(window);



		window.display();

	}
}



