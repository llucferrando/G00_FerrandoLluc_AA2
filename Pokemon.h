#pragma once
#include "MapElements.h"


class Pokemon : public MapElements
{
	public:
	Pokemon();
	
	Vector2D * pokePos;
	virtual void OnPlayerCollision(Player* myPlayer, Vector2D* movement) override;

};

