#pragma once
#include <SFML/Graphics.hpp>

class Picture
{
public:
	Picture(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count);

	void animation(int time);
	void draw(sf::RenderWindow& app);
	std::string Get_name() { return name; }
	float Get_position_X() { return position_X; }
	float Get_position_Y() { return position_Y; }

	
protected:
	float position_X = 0;
	float position_Y = 0;
	float animation_speed = 0.02;

    std::string name;
	sf::Texture Texture_Player;
	sf::Sprite Sprite_Player;
private:

	int x, y, w, h, distance_to_sprite, number_frames;
	float current_frame;


};

