#include "Dust.h"


Dust::Dust(sf::Texture& t, int x, int y, int w, int h, int distance_to_sprite, int count, float posX, float posY)
:Object(t,  x,  y,  w,  h, distance_to_sprite,  count,  posX,  posY)
{
	name = "Dust";
	Sprite_Player.setScale(sf::Vector2f(0.5f,0.5f));
	Sprite_Player.setPosition(position_X - 37.5, position_Y - 37.5);
}



void Dust::movement(float time)
{
	time /= 7000;

	//������� �� ����� ����� �� ��������
	float distance = sqrt( pow (destination_x - position_X ,2) +pow(destination_y - position_Y,2)  );

	if (distance<5) return; //����� ����������� �� ��� ���������
	
	position_X += time  * ( destination_x - position_X ) / distance;//( destination_x - position_X ) / distance 
	position_Y += time  * ( destination_y - position_Y ) / distance;//���������� �������/ 10 ������� �� time /!!!!!!
	
	Sprite_Player.setPosition(sf::Vector2f(position_X- 37.5,  position_Y- 37.5));
}

bool Dust::collision(float x, float y)
{
	//�� ��������� 2 ����� ���������� ����� 
	if ( 
		 ( pow(x - position_X , 2) / 1406.25 + pow(y - position_Y-2.5 , 2) / 121 <= 1 &&
		   pow(x - position_X , 2) / 1406.25 + pow(y - position_Y -2.5, 2) / 121 >= 0 )
	                                                                                               ||
		 ( pow(x - position_X , 2) / 210.25  + pow(y - position_Y+5, 2) / 900  <= 1 &&
		   pow(x - position_X , 2) / 210.25  + pow(y - position_Y+5 , 2) / 900  >= 0 )


		)
		return true;
	return false;
}


