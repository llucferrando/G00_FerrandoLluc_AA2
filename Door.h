#pragma once
#include "MapElements.h"


class Door : public MapElements
{
public:
	Door() { elementCharacter = "D"; }
	virtual void OnPlayerCollision(Player* myPlayer, Vector2D* movement)override;
};

