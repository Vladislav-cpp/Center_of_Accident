#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Object
{
public:
	Object(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY);

	virtual void movement() = 0;

    void draw(sf::RenderWindow& app);
	virtual bool collision(float x, float y)=0;
	
	void animation();//   animation(time)  !!!!!!!!

    std::string name;//   get_name !!!!!!!!

protected:
	sf::Texture Texture_Player;
    sf::Sprite Sprite_Player;

	int x, y, w, h,distance, frame, count;

	float position_X;
	float position_Y;
	bool life;
	

};

