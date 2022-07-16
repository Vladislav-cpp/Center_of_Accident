#include "Dust.h"


Dust::Dust(sf::Texture& t, int x, int y, int w, int h, int distance, int count, float posX, float posY)
:Object(t,  x,  y,  w,  h,  distance,  count,  posX,  posY)
{
	name = "Dust";
	Sprite_Player.setScale(sf::Vector2f(0.5f,0.5f));
	Sprite_Player.setPosition(position_X - 37.5, position_Y - 37.5);//(position_X - 40, position_Y - 30)

	
	//polygon.setPointCount(12);
	//polygon.setPoint(0, sf::Vector2f(70, 40));
	//polygon.setPoint(1, sf::Vector2f(70, 20));
	//polygon.setPoint(2, sf::Vector2f(50, 20));
	//polygon.setPoint(3, sf::Vector2f(50, 40));
	//polygon.setPoint(4, sf::Vector2f(20, 40));
	//polygon.setPoint(5, sf::Vector2f(20, 60));
	//polygon.setPoint(6, sf::Vector2f(50, 60));
	//polygon.setPoint(7, sf::Vector2f(50, 70));
	//polygon.setPoint(8, sf::Vector2f(70, 70));
	//polygon.setPoint(9, sf::Vector2f(70, 60));
	//polygon.setPoint(10, sf::Vector2f(100, 60));
	//polygon.setPoint(11, sf::Vector2f(100, 40));


	//polygon.setOutlineColor(sf::Color::Red);
	//polygon.setOutlineThickness(5);
	//polygon.setPosition(position_X - 60, position_Y - 50);

	//window.draw(polygon); ФУнкцію драв треба перегрузити з базового класу
}

void Dust::shot()
{
}

void Dust::movement()
{

	float distance = sqrt( (destination_x - position_X) * (destination_x - position_X) +
		                   (destination_y - position_Y) * (destination_y - position_Y) );


	//std::cout << "distance = " << distance << "\n";
	//std::cout <<" position_X - 40(!)"<< position_X - 40 << "\n";
	//std::cout <<" position_Y - 30(!)"<< position_Y - 30 << "\n" ;
	//std::cout << "position_X <= (destination_x - 10) -> " << destination_x -10 << "\n";
	//std::cout << "position_X <= (destination_x + 10) -> " << destination_x +10<< "\n" << "\n";

	if (distance<10) return;

	//std::cout << "if (   !---------------------------------------------------------"<< "\n";
	

	position_X += 10 * ( destination_x - position_X ) / distance;
	position_Y += 10 * ( destination_y - position_Y ) / distance;
	
	Sprite_Player.setPosition(sf::Vector2f(position_X- 37.5, position_Y- 37.5));//(position_X-40, position_Y-30)

	//std::cout << position_X - 40 << "\n";
 //   std::cout << position_Y - 30 << "\n" << "\n";


   
}

bool Dust::collision(float x, float y)//є баг колізія дирява
{
	if ( 
		 ( pow(x - position_X , 2) / 1406.25 + pow(y - position_Y , 2) / 81 <= 1.3 &&
		   pow(x - position_X , 2) / 1406.25 + pow(y - position_Y , 2) / 81 >= 0.3 )
	                                                                                               ||
		 ( pow(x - position_X , 2) / 210.25  + pow(y - position_Y+5, 2) / 900  <= 1.3 &&
		   pow(x - position_X , 2) / 210.25  + pow(y - position_Y+5 , 2) / 900  >= 0.3 )
		)
		return true;
	return false;
}

//void Dust::draw(sf::RenderWindow& app)
//{
//	Object::draw(app);
//	app.draw(polygon);
//}
