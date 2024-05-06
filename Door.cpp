#include "Door.h"

void Door::OnPlayerCollision(Player* myPlayer, Vector2D* movement)
{
	movement->_x = 0;
	movement->_y = 0;
}
