#pragma once
#include "MapElements.h"
class Player : public MapElements
{
	public:

	Player();
	~Player();
	Vector2D* myPosition;
	int pokemonsCaptured, pokeBallsCaptured = 0;
	//virtual void OnPlayerCollision(Player* myPlayer, MapManager* myMapManager, Vector2D* movement) override;

};

