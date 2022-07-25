#include "Picture.h"

Picture::Picture(std::string file_name, int x, int y, int w, int h, int distance_to_sprite, int number_frames)
	: x(x), y(y), w(w), h(h), distance_to_sprite(distance_to_sprite), current_frame(0), number_frames(number_frames)
{
	Texture_Player.loadFromFile(file_name);
	Sprite_Player.setTexture(Texture_Player);
	Sprite_Player.setTextureRect(sf::IntRect(x, y, w, h));

}

void Picture::animation(int time)
{
	current_frame += animation_speed * time;

	if (current_frame >= number_frames)  current_frame = 0;

	Sprite_Player.setTextureRect(sf::IntRect(x + static_cast<int>(current_frame) * distance_to_sprite, y, w, h));
}


void Picture::draw(sf::RenderWindow& app)
{
	app.draw(Sprite_Player);
}