#pragma once
#include "Player.h"


class Ufo :public Player
{
public:
	//Ufo(std::string file_name, int image_coordinate_x, int image_coordinate_y, int image_width, int image_height,
	//	int distance_animation, int number_frames, float position_X, float position_Y);
	
	Ufo(float pos_spawn_ufo_X, float pos_spawn_ufo_Y);



	 void movement(float time);//!!!!!!!!!!!
     bool collision(float x, float y);
	 //float Get_pos_Y()const;
	 //float Get_pos_X()const;

	 float Get_pos_window_Y()const;
	 float Get_pos_window_X()const;

	 void set_pos_target(float target_X, float target_Y) {};////!!!!! ошибка виправити
private:
	
	float speed_movement = 15;
};


