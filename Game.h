#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
#include "Ufo.h"
#include "Dust.h"
#include "Chuck.h"

#include <list>
#include <cmath>
#include <ctime>
#include <SFML/Audio.hpp>
#include "Information_window.h"

class Game
{
private:


	sf::Texture Tbackground;
	sf::Sprite Sprite_Tbackground;


	std::string Dust_name = ("images/Ufos.png");
	std::string Ufo_nam = ("images/ufo.png");
	std::string Chuck_nam = ("images/14.png");

	sf::Clock clock;
	sf::Clock clock_recharge;
	sf::Clock clock_create_opponents;

	sf::Cursor cursor;

	sf::SoundBuffer shotBuffer;
	sf::Sound shoot;

	sf::SoundBuffer explosionBuffer;
	sf::Sound explosion;
	sf::Music music;

	std::list<Object*> object;

	static constexpr double radians_to_degrees = 57.2958;// ������� ��������� ��� ������
	const unsigned int windov_width = 1300;
	const unsigned int windov_height = 900;

    int number_opponents=0;
	int recharge = 300;
	int create_opponents = 1000; 
	int number_of_fps = 60;


	float pos_spawn_ufo_X= windov_width/2;
	float pos_spawn_ufo_Y= windov_height/2;

	float respawn_dust_x=0;
	float respawn_dust_y=0;

	float radius_spawn_dust_X= 450;
	float radius_spawn_dust_Y= 450;

	sf::RenderWindow window;

	Information_window Iw{};

public:
	Game(int number_opponents=5);
	void Run();
};




