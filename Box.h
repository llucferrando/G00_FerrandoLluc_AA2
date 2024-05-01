#pragma once
#include "Vector2D.h"
#include "MapElements.h"
class Box
{
public:

	Box(Vector2D* position, MapElements* myElement)
	{
		this->myElement = myElement;
		myBoxPosition = position;
	}
	MapElements* myElement;
	void PrintBox();
	Vector2D* myBoxPosition;
};

