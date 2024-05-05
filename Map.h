#pragma once
#include "Box.h"
#include "GameConfigInfo.h"
#include "Player.h"
#include "Pokemon.h"
#include <vector>

class Map
{
public:
	Map(GameConfigInfo* gameConfigInfo);

	int mapID;
	GameConfigInfo* gi;
	
	Box ** field;
	
	std::vector<Pokemon*> pokemons;
	std::vector<MapElements*> newMapElements;
	

	void PrintMap();
	void InitMap(Player * myPlayer);
	void InitMapElements();

	void PrintBoxInMap(Box* myBox);
	
};

