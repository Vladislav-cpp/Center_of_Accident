#pragma once
#include "Player.h"
#include <iostream>


class Dust :public Player
{
public:
	Dust();
	virtual void shot();
	virtual void movement(float destination_x, float destination_y);
	//sf::Sprite Get_Sprite()const;
private:


};
