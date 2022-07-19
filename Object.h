#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Object
{
public:
	Object(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY);
	virtual ~Object() {};
	virtual void movement(float time) = 0;//   movement(time)  !!!!!!!!

    void draw(sf::RenderWindow& app);
	virtual bool collision(float x, float y)=0;
	
	void animation();//   animation(time)  !!!!!!!!

 

	std::string Get_name() { return name; }
	float Get_position_X() { return position_X; }
	float Get_position_Y() { return position_Y; }
	bool Get_life() { return life; }

	void Set_life(bool life) { this->life = life; }
	

protected:

    std::string name;
	sf::Texture Texture_Player;
    sf::Sprite Sprite_Player;

	int x, y, w, h, distance_to_sprite, frame, count;

	float position_X;
	float position_Y;
private:
	bool life;
	

};

