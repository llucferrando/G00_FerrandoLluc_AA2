#include "Walls.h"

void Walls::OnPlayerCollision(Player* myPlayer, Vector2D* movement)
{
	movement->_x = 0;
	movement->_y = 0;
}
