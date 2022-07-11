#include "Game.h"


Game::Game() 
{

}

void Game::Run()
{
	Ufo our_character;
	Dust enemy;

	sf::Clock clock;


	while (Game_State)
	{

			float time = clock.getElapsedTime().asMicroseconds();
			time /= 5000;
	        clock.restart();


		map.Draw(our_character.Get_Sprite(), enemy.Get_Sprite());

		enemy.movement(400,400,time);
		 
		

		//while (window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window.close(); 
		//}


	}
}



