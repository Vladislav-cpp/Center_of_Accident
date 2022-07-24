#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
#include "Ufo.h"
#include "Dust.h"
#include "Map.h"
#include "Chuck.h"

#include <list>
#include <cmath>
#include <ctime>

class Game
{
private:

	

	sf::Texture Tbackground, TDust, TUfo, TChuck;
	sf::Texture Texture_map;
	sf::Sprite Sprite_map;

	sf::Clock clock;
	sf::Clock clock_recharge;
	sf::Cursor cursor;

	sf::SoundBuffer shotBuffer;
	sf::Sound shoot;

	sf::SoundBuffer explosionBuffer;
	sf::Sound explosion;
	sf::Music music;

	std::list<Object*> object;

	static constexpr double radians_to_degrees = 57.2958;// зробити доступним усім класам
	const unsigned int windov_width = 1300;
	const unsigned int windov_height = 900;
    int number_opponents=0;
	int recharge = 300;
	int number_of_fps = 60;


	float pos_spawn_ufo_X= windov_width/2;
	float pos_spawn_ufo_Y= windov_height/2;

	float respawn_dust_x;
	float respawn_dust_y;

	float radius_spawn_dust_X= 450;
	float radius_spawn_dust_Y= 450;

	sf::RenderWindow window;

public:
	Game(int number_opponents=5);
	void Run();
};




