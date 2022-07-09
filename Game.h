#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"



class Game
{
private:
	enum State
	{
		game_over=0,
		game_is_on 
		
		
	};
	State Game_State = game_is_on;
	Map map;
public:
	void Run();
    Game();
};




