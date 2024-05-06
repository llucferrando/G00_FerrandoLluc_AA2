#include "PokeBall.h"

void PokeBall::OnPlayerCollision(Player* myPlayer, Vector2D* movement)
{
	movement->_x = 0;
	movement->_y = 0;

}
