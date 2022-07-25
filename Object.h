#pragma once
//#include <SFML/Graphics.hpp>
#include "Picture.h"
//#include <SFML/Audio.hpp>//!!!!!!!!! to game
#include <iostream>
#include <string>

class Object :public Picture
{
public:
	Object(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count);
		
    virtual ~Object() {};
    
	virtual bool collision(float x, float y)=0;
	virtual void movement(float time) = 0;
	//void animation(int time);
    //void draw(sf::RenderWindow& app);
 
	//std::string Get_name() { return name; }
	//float Get_position_X() { return position_X; }
	//float Get_position_Y() { return position_Y; }
	bool Get_life()        { return life; }

	void Set_life(bool life) { this->life = life; }
protected:	

   // std::string name;

	//sf::Texture Texture_Player;
    //sf::Sprite Sprite_Player;

	//float position_X=0;
	//float position_Y=0;
	//float animation_speed = 0.02;
private:
	bool life;
	//int x, y, w, h, distance_to_sprite, number_frames;
	//float current_frame;

};

