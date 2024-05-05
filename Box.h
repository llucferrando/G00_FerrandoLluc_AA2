#pragma once
#include "MapElements.h"
class Box
{
public:
	Box();
	Box(Vector2D* position) :myBoxPosition(position) {};

	MapElements* myElement;
	
	Vector2D* myBoxPosition;

	void PrintBox();
	void PrintGameElements(MapElements* newMapElement);
};

