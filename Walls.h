#pragma once
#include "MapElements.h"

class Walls : public MapElements
{
public:
	Walls() { elementCharacter = "X"; };
	
	Vector2D* wallsPos;

	virtual void OnPlayerCollision(Player* myPlayer, Vector2D* movement)override;
};

