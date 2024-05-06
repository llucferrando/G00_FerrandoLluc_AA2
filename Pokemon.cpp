#include "Pokemon.h"

Pokemon::Pokemon()
{
	elementCharacter = "P";
	pokePos = new Vector2D(0,0);
	srand(time(nullptr));
	pokePos->_x = rand() % 40; 
	pokePos->_y = rand() % 60; 
	
}

void Pokemon::OnPlayerCollision(Player* myPlayer, Vector2D* movement)
{
	movement->_x = 0;
	movement->_y = 0;
}
