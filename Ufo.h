#pragma once
#include "Player.h"


class Ufo :public Player
{
public:
	Ufo();
	virtual void shot();
	virtual void movement(float destination_x, float destination_y);
	//sf::Sprite Get_Sprite()const;
private:
	
	
};


