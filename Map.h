#pragma once
#include "Box.h"
#include "GameConfigInfo.h"
#include "Player.h"
#include "Pokemon.h"
#include <vector>
#include "Walls.h"
#include "Door.h"

class Map
{
public:
	Map(GameConfigInfo* gameConfigInfo);

	int halfY=0;
	int halfX=0;
	GameConfigInfo* gi;
	
	Box ** field;
	
	std::vector<Pokemon*> pokemons;
	std::vector<MapElements*> newMapElements;
	
	
	void PrintMap(Player* myPlayer);
	void InitMap(Player * myPlayer);
	void InitMapElements();

	void PrintBoxInMap(Box* myBox);
	
};

