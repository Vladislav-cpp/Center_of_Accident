#include "Picture.h"

Picture::Picture(std::string file_name, int image_coordinate_x, int image_coordinate_y, 
	int image_width, int image_height, int distance_animation, int number_frames)

	: image_coordinate_x(image_coordinate_x), image_coordinate_y(image_coordinate_y), 
	image_width(image_width), image_height(image_height), distance_animation(distance_animation), current_frame(0), number_frames(number_frames)
{
	Texture_Player.loadFromFile(file_name);
	Sprite_Player.setTexture(Texture_Player);
	Sprite_Player.setTextureRect(sf::IntRect(image_coordinate_x, image_coordinate_y, image_width, image_height));

}

void Picture::animation(int time)
{
	current_frame += animation_speed * time;

	if (current_frame >= number_frames)  current_frame = 0;

	Sprite_Player.setTextureRect(sf::IntRect(image_coordinate_x + static_cast<int>(current_frame) * distance_animation, image_coordinate_y, image_width, image_height));
}


void Picture::draw(sf::RenderWindow& app)
{
	app.draw(Sprite_Player);
}
