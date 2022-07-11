#pragma once
#include "Player.h"



class Dust :public Player
{
public:
	Dust();
	virtual void shot();
	virtual void movement();
	//sf::Sprite Get_Sprite()const;
private:


};
