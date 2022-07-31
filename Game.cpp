#include "Game.h"


Game::Game(int number_opponents) :window(sf::VideoMode(windov_width, windov_height), "Center_of_Accident", sf::Style::Default)
, number_opponents(number_opponents), shoot(shotBuffer), explosion(explosionBuffer)
 
{
	std::srand(time(NULL));

	Tbackground.loadFromFile("images/background.png");            Tbackground.setSmooth(true);
	Sprite_Tbackground.setTexture(Tbackground);
	Sprite_Tbackground.setTextureRect(sf::IntRect(0, 0, 3000, 2000));
	Sprite_Tbackground.setPosition(0, 0);

	shotBuffer.loadFromFile("sound and music/shot.ogg");
	explosionBuffer.loadFromFile("sound and music/explosion.ogg");
	music.openFromFile("sound and music/background music.ogg");

	window.setFramerateLimit(number_of_fps);

	cursor.loadFromSystem(sf::Cursor::Arrow);//написати прицел вместо курсора 
	window.setMouseCursor(cursor);

	view.reset(sf::FloatRect(0,0, windov_width, windov_height));

  uf = new Ufo(pos_spawn_ufo_X, pos_spawn_ufo_Y);
  player.push_back(uf);

}


void Game::Run()
{
	    //відкриваєио меню
	     Menu_overview();

		 clock.restart();
		 clock_recharge.restart();
		 clock_create_opponents.restart();


	music.play();
	music.setLoop(true);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		float recharge_time = clock_recharge.getElapsedTime().asMilliseconds();
		//float time_create_opponents = clock_create_opponents.getElapsedTime().asMilliseconds();

		clock.restart();

		//включаєм музику якщо та виключилась
		//if(sf::SoundStream::Status::Paused == music.getStatus()) music.play();

		//створення обєктив класа Dust по кд в рандомних позиціях по окружності 
		spawn_dust();
		

		

		//визов фун-члена movement 
		/*for (auto o = object.begin(); o != object.end(); o++)
			{
			   Object* tmp_o = *o;
			   tmp_o->movement(time);
			}

		for (auto p = player.begin(); p != player.end(); p++)
		{
			Player* tmp_p = *p;

			if (tmp_p->Get_name() == "Dust")
			tmp_p->set_pos_target(uf->Get_position_X(), uf->Get_position_Y());

			tmp_p->movement(time);
		}*/
		updata(time);

		//рухаєм вікно	
		float tmp_viev_X = uf->Get_position_X();
		float tmp_viev_Y = uf->Get_position_Y();

		if ( uf->Get_position_X() < (windov_width / 2) )
			tmp_viev_X= windov_width / 2;

		if ( uf->Get_position_X() > (3000 - windov_width / 2) )
			tmp_viev_X = (3000 - windov_width / 2);


	    if ( uf->Get_position_Y() < (windov_height / 2) ) 
			tmp_viev_Y= windov_height / 2;

		if ( uf->Get_position_Y() > (2000 - windov_height / 2) ) 
			tmp_viev_Y = (2000 - windov_height / 2);

        Set_coord_viev(tmp_viev_X, tmp_viev_Y);


		// перевірка колізії 
		collision();

		//якщо нажата мишка !!!!!!!!!!!!!!!
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (recharge_time > recharge)
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);

				Chuck* ch = new Chuck(position.x, position.y, uf->Get_position_X(), uf->Get_position_Y(),windov_width/2,  windov_height/2);
				object.push_back(ch);
				shoot.play();

				clock_recharge.restart(); 
			}
		}

        //видалення обєктів які знищєні та підрахунок очків класа Iw
        for (auto o = object.begin(); o != object.end();)
        {
			Object* tmp_o = *o;
        	if  ( false == tmp_o->Get_life() )
			{ 							
				if (tmp_o->Get_name() == "Dust")
				Iw.add_points();

				o = object.erase(o); delete tmp_o;

			}
        	else o++;
        }

		for (auto p = player.begin(); p != player.end();)
		{
			Player* tmp_p = *p;
			if (false == tmp_p->Get_life())
			{
				if (tmp_p->Get_name() == "Dust")
					Iw.add_points();

				p = player.erase(p); delete tmp_p;

			}
			else p++;
		}


		//рухаєм камеру
		window.setView(view);

		//очистка вікна
		window.clear();

		window.draw(Sprite_Tbackground);

		//закриття вікна і виход з циклу
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//аніміровання та отрисовка всіх обєктів 
		for (auto o : object) 
		{
			o->animation(time);
			o->draw(window);
        }

		for (auto p : player)
		{
			p->animation(time);
			p->draw(window);
		}

		//аніміровання та отрисовка інформаційного вікнa
		Iw.animation(time);
		Iw.draw(window);

		window.display();

	}
}

void Game::Menu_overview()
{
	sf::Texture TMenu;	TMenu.loadFromFile("images/menu/game__menu.png");            TMenu.setSmooth(true);
	sf::Sprite Smenu;	Smenu.setTexture(TMenu);
	Smenu.setTextureRect(sf::IntRect(0, 0, 1000, 563));
	Smenu.setPosition(0, 0);

	sf::Texture TMenu_option;	TMenu_option.loadFromFile("images/menu/option.png");            TMenu_option.setSmooth(true);
	sf::Sprite Smenu_option;	Smenu_option.setTexture(TMenu_option);
	Smenu_option.setTextureRect(sf::IntRect(0, 0, 227, 152));
	Smenu_option.setPosition(427, 130);

	sf::Texture TMenu_start;	TMenu_start.loadFromFile("images/menu/start.png");            TMenu_start.setSmooth(true);
	sf::Sprite SMenu_start;	SMenu_start.setTexture(TMenu_start);
	SMenu_start.setTextureRect(sf::IntRect(0, 0, 227, 152));
	SMenu_start.setPosition(427, 130);

	sf::Music music_for_the_menu;
	music_for_the_menu.openFromFile("sound and music/music for the menu.ogg");
	music_for_the_menu.play();
	music_for_the_menu.setLoop(true);

	bool start = false;
	bool option = false;
	bool menu_is_open = true;

	while (menu_is_open)
	{

		start = false;
		option = false;

		if (sf::IntRect(435, 146, 191, 49).contains(sf::Mouse::getPosition(window))) { start = true; }
		if (sf::IntRect(451, 216, 159, 49).contains(sf::Mouse::getPosition(window))) { option = true; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (sf::IntRect(435, 146, 191, 49).contains(sf::Mouse::getPosition(window))) { menu_is_open = false;}
		}
		

		//закриття вікна і виход з циклу
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Smenu);
		if (start)  window.draw(SMenu_start);
		if (option) window.draw(Smenu_option);
		window.display();
	}
}


//створення обєктив класа Dust в рандомних позиціях по окружності
void Game::spawn_dust()
{
	float time_create_opponents = clock_create_opponents.getElapsedTime().asMilliseconds();
	


		if (time_create_opponents > create_opponents) {
			int tmp_angle_R = rand() % 360;
			respawn_dust_x = windov_width /2 + radius_spawn_dust_X * cos(tmp_angle_R * radians_to_degrees);
			respawn_dust_y = windov_height/2 + radius_spawn_dust_Y * sin(tmp_angle_R * radians_to_degrees);


			Dust* d = new Dust(respawn_dust_x, respawn_dust_y, uf->Get_position_X(), uf->Get_position_Y());
			player.push_back(d);
			clock_create_opponents.restart();
		}
	

}

void Game::updata(float time)
{
	for (auto o = object.begin(); o != object.end(); o++)
	{
		Object* tmp_o = *o;
		tmp_o->movement(time);
	}

	for (auto p = player.begin(); p != player.end(); p++)
	{
		Player* tmp_p = *p;

		if (tmp_p->Get_name() == "Dust")
			tmp_p->set_pos_target(uf->Get_position_X(), uf->Get_position_Y());

		tmp_p->movement(time);
	}
}

void Game::collision()
{
	// перевірка колізії обєктив Ufo і Dust
	for (auto p = player.begin(); p != player.end(); p++)
	{
		Player* tmp_pu = *p;
		if (tmp_pu->Get_name() == "Dust")
			if (uf->collision(tmp_pu->Get_position_X(), tmp_pu->Get_position_Y()))
			{
				Iw.change_life();//віднiмаєм хп убиваєм портивника
				tmp_pu->Set_life(false);//
				explosion.play();
			}
	}


	// перевірка колізії обєктив Chuck і Dust
	for (auto o = object.begin(); o != object.end(); o++)
		for (auto p = player.begin(); p != player.end(); p++)
		{
			Object* tmp_o = *o;
			Player* tmp_p = *p;

			if (tmp_o->Get_name() == "Chuck")
				for (auto i : object)
					if (tmp_p->Get_name() == "Dust")
						if (tmp_p->collision(tmp_o->Get_position_X(), tmp_o->Get_position_Y()))
						{
							tmp_o->Set_life(false);
							tmp_p->Set_life(false);
							explosion.play();
						}
		}


}


