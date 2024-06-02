#pragma once
#include "Vector2D.h"
#include "InputManager.h"
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
	void Inputs(InputManager* inputs);
	int pokemonsCaptured, currentPokeballs = 0;

};

