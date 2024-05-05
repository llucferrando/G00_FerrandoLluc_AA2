#pragma once
#include "Vector2D.h"
#include <iostream>



class MapElements
{
public:
	MapElements() = default;
	MapElements(std::string myChar, Vector2D* position) : elementCharacter(myChar), mapElementPosition(position) {};

	Vector2D* mapElementPosition = new Vector2D(0,0);
	std::string elementCharacter;
	
	//virtual void OnPlayerCollision(Player* myPlayer, MapManager* myMapManager, Vector2D* movement) = 0;

};

