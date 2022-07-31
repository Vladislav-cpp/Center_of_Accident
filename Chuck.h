#pragma once
//#include "Player.h"
#include "Object.h"




class Chuck : public Object
{
public:
	Chuck(float direction_X, float direction_Y,	float position_X, 
		float position_Y,	float windov_width, float windov_height);

	void movement(float time);
	bool collision(float x, float y);//!!!!!!!!!!!!!!

private:
	float speed_movement = 1.5;
	float direction_movement_X;
	float direction_movement_Y;
	
	static constexpr double radians_to_degrees = 57.2958;
};
