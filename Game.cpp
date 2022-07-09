#include "Game.h"


Game::Game() 
{

}

void Game::Run()
{
	
	while (Game_State)
	{
		map.Draw();
		//while (window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window.close(); 
		//}


	}
}



