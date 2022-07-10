#pragma once
#include "Player.h"


class Ufo :public Player
{
public:
	Ufo();
	virtual void shot();
	virtual void movement();
	//sf::Sprite Get_Sprite()const;
private:
	
	
};


