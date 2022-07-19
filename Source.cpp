#include <ctime>
#include <SFML/Graphics.hpp>//чому тут?
#include <iostream>
#include "Game.h"



int main()
{
std::srand(time(NULL));//чому тут?

      Game Cyber_Game;
   	  Cyber_Game.Run();

	 return 0;
}

