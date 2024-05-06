#pragma once
#include "MapElements.h"
class PokeBall : public MapElements
{
public:
	PokeBall() { elementCharacter = "B"; };

	virtual void OnPlayerCollision(Player* myPlayer, Vector2D* movement)override;
};

	