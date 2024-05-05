#include "Pokemon.h"

Pokemon::Pokemon()
{
	elementCharacter = "S";
	pokePos = new Vector2D(0,0);
	srand(time(nullptr));
	pokePos->_x = rand() % 40; 
	pokePos->_y = rand() % 60; 
	
}
