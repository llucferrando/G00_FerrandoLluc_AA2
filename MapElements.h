#pragma once
#include "GameManager.h"
#include "Ash.h"
#include "MapManager.h"
class MapElements
{
public:
	MapElements(char myChar, Vector2D* position) :elementCharacter(myChar), mapElementPosition(position) {};

	Vector2D* mapElementPosition;
	char elementCharacter;

	virtual void OnPlayerCollision(Ash* myPlayer, MapManager* myMapManager, Vector2D* movement) = 0;

};

