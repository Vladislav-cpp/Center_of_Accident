#include "Game.h"


Game::Game() 
{

}

void Game::Run()
{
	Ufo our_character;
	Dust enemy;

	while (Game_State)
	{
		map.Draw(our_character.Get_Sprite(), enemy.Get_Sprite());
		 
		//while (window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window.close(); 
		//}


	}
}



