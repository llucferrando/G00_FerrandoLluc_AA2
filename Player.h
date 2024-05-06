#pragma once
#include "MapElements.h"
#include <set>
class Player : public MapElements
{
	public:
	Player();
	~Player();
	Vector2D* myPosition;
	//Future function to improve logic, where to spawn pokemons to avoid spawning a pokemon in the same player pos
	std::set<Vector2D*>myRadius;
	std::set<Vector2D*> CloseArea();

	int pokemonsCaptured, pokeBallsCaptured = 0;
	virtual void OnPlayerCollision(Player* myPlayer, Vector2D* movement) override;

};

