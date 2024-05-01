#pragma once
#include "Vector2D.h"
#include "Ash.h"
#include <iostream>
#include <set>
#include "MapElements.h"
class Ash : public MapElements
{
private:
	 
public:
	Ash(Vector2D * position, Ash *myplayer);
	Vector2D* myPosition;
	std::set<Vector2D*>myRadius;
	int health, score, pokemonsCaptured, pokeballsCaptured;

	std::set<Vector2D*> CloseArea() {
		std::set<Vector2D*> set{ new Vector2D(myPosition->_x, myPosition->_y),new Vector2D(myPosition->_x + 1, myPosition->_y),
			new Vector2D(myPosition->_x - 1, myPosition->_y), new Vector2D(myPosition->_x, myPosition->_y + 1), new Vector2D(myPosition->_x, myPosition->_y - 1),
		new Vector2D(myPosition->_x - 1, myPosition->_y - 1), new Vector2D(myPosition->_x - 1, myPosition->_y + 1),
			new Vector2D(myPosition->_x + 1, myPosition->_y - 1) , new Vector2D(myPosition->_x + 1, myPosition->_y + 1) };
		return set;
	}
	std::set<Vector2D*> CaptureArea() {
		std::set<Vector2D*> set{ new Vector2D(myPosition->_x + 1, myPosition->_y),new Vector2D(myPosition->_x - 1, myPosition->_y),
			new Vector2D(myPosition->_x, myPosition->_y + 1), new Vector2D(myPosition->_x, myPosition->_y - 1), };
		return set;
	}

	bool CanCollide(MapManager* myMapManager, Vector2D* movement);

	//void RecieveDamage() { lifes--; }
};

