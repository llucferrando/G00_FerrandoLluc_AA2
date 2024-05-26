#pragma once
#include "Vector2D.h"
#include <string> 
extern class Map;
class Pokemon
{
private:
	int minTimeToMove;
	int maxTimeToMove;
	float currentTimeToMove;
	float timeToMove;
	DirectionType directionType;

public:
	Pokemon(int min,int max);
	Vector2D* direction;
	Vector2D* position;
	std::string name;
	int hp;
	bool canMove;

	int maxHp;
	bool alive;
	void Update(Map* map,float dt);
	bool TryToCath();
	void Disapear();
	void GetDamage(float damage);
};

