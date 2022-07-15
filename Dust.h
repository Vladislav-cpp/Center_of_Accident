#pragma once
#include "Object.h"
//#include <iostream>


class Dust :public Object
{
public:
	Dust();
	virtual void shot();
	virtual void movement();
	
private:

	float destination_x = 400;
	float destination_y = 400;

};
