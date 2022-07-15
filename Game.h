#pragma once
#include <SFML/Graphics.hpp>
#include "Ufo.h"
#include "Dust.h"
#include "Map.h"
#include <iostream>
#include <list>


class Game
{
private:

	sf::Texture Tbackground, TDust, TUfo;
	std::list<Object*> object;

	//enum State{		game_over=0,		game_is_on 		};
	//State Game_State = game_is_on;

	//Map map;

	sf::Texture Texture_map;
	sf::Sprite Sprite_map;

	const unsigned int windov_width = 800;
	const unsigned int windov_height = 800;
	sf::RenderWindow window;

	

public:
	Game(int number_opponents=1);
	void Run();
};




