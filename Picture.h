#pragma once
#include <SFML/Graphics.hpp>

class Picture
{
public:
	
	Picture(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height, int distance_animation, int number_frames);
	virtual ~Picture() {};
	 void animation(int time);
	 void draw(sf::RenderWindow& app);
	//std::string Get_name() { return name; }//-
	//float Get_position_X() { return position_X; }//-
	//float Get_position_Y() { return position_Y; }//-

	//void Set_position_XY(float pos_X, float pos_Y) { Sprite_Player.setPosition(pos_X, pos_Y); }
	sf::Sprite& Get_Sprite() { return Sprite_Player; }

	
protected:
	//float position_X = 0;//-
	//float position_Y = 0;//-
	float animation_speed = 0.02;

    //std::string name;//-
	sf::Texture Texture_Player;
	sf::Sprite Sprite_Player;
private:

	int image_coordinate_x, image_coordinate_y, image_width, image_height, distance_animation, number_frames;
	float current_frame;


};

