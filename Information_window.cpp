#include "Information_window.h"



Information_window::Information_window()
	: coin_(std::string("images/Full Coins.png"),0,0,15,16,16,8)
	,life_(std::string("images/Sprite Sheet.png"), 0, 0, 35, 32, 0, 0)
{
	front.loadFromFile("type/Mistral.ttf");

	coin_.Get_Sprite().setPosition(10, 10);
	coin_.Get_Sprite().setScale(2, 2);
	text_coin_.setFont(front);
	//text.setFillColor(sf::Color::Black);
	text_coin_.setStyle(sf::Text::Bold);
	text_coin_.setCharacterSize(35);
	text_coin_.setPosition(50,2);
	text_coin_.setString("x"+ std::to_string(number_points));
	
	life_.Get_Sprite().setPosition(8, 45);
	text_life_.setFont(front);
	text_life_.setStyle(sf::Text::Bold);
	text_life_.setCharacterSize(35);
	text_life_.setPosition(50, 37);
	text_life_.setString("x" + std::to_string(number_life));
}

void Information_window::animation(int time)
{
	
	coin_.animation(time);
	//life_.animation(time);
}

void Information_window::draw(sf::RenderWindow& app)
{
	life_.draw(app);
	app.draw(text_life_);

	coin_.draw(app);
	app.draw(text_coin_);
}


void Information_window::add_points(int points)
{
	number_points += points;
	text_coin_.setString("x" + std::to_string(number_points));
	text_coin_.setPosition(50, 2);
	
}

void Information_window::change_life(int life)
{
	number_life += life;
	text_life_.setString("x" + std::to_string(number_life));
	text_life_.setPosition(50, 37);

}
