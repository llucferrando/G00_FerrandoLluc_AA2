#pragma once
#include "Vector2D.h"
extern class Map;
class Player
{
	public:
	Player();
	~Player();
	Vector2D* position;
	Vector2D* direction;
	int damage;
	void Update(Map* map);
	int pokemonsCaptured, currentPokeballs = 0;

};

