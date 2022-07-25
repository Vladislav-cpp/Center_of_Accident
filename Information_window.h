#pragma once
#include "Picture.h"



class Information_window
{
public:
	Information_window();
	void animation(int time);
	void draw(sf::RenderWindow& app);
	void add_points(int points = 1);
	void change_life(int life = -1);

private:
	Picture life_;
	Picture coin_;
	int number_points = 0;
	int number_life = 3;

	sf::Font front;
	sf::Text text_coin_;
	sf::Text text_life_;
	
};

