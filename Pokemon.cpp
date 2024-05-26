#include "Pokemon.h"
#include <stdlib.h>
#include "Map.h"
#include "GameManager.h"

Pokemon::Pokemon(int min,int max)
{
	directionType = static_cast<DirectionType>(rand() % 3);
	name = "Pokemon";
	maxHp = 10;
	hp = maxHp;
	alive = true;
	minTimeToMove = min;
	canMove = true;
	maxTimeToMove = max;
}

void Pokemon::Update(Map* map,float dt)
{
	if (!canMove)
		return;
	currentTimeToMove += dt;
	if (currentTimeToMove <= timeToMove * 1000)
		return;
	currentTimeToMove = 0;
	timeToMove = (rand() % (maxTimeToMove - minTimeToMove)) + minTimeToMove;

	direction = Vector2D::GetDirectionFromType(directionType);

	direction->x = (rand() % 2) == 0 ? direction->x : -direction->x;
	direction->y = (rand() % 2) == 0 ? direction->y : -direction->y;

	if (direction->x == 0 && direction->y == 0)
		return;

	Vector2D nextPosition = *position;
	nextPosition.x += direction->x;
	nextPosition.y += direction->y;

	switch (map->GetTile(nextPosition)) {
	case TileType::Player:
		GameManager::getInstance().gameState = GameState::Capturing;
		GameManager::getInstance().fightingPokemon = this;
		break;
	}

	if (map->IsBlockingCollision(nextPosition))
		return;

	map->ClearTile(*position);
	position->x += direction->x;
	position->y += direction->y;
	map->UpdatePosition(*position, TileType::Enemy);
}

bool Pokemon::TryToCath()
{
	// 50% base + 50% en funcion de la vida que le falte
	float hpPercentage = hp / maxHp;
	float chance = 50 * (1 -hpPercentage) + 50;
	return rand() % 100 <= chance;
}

void Pokemon::Disapear()
{
	alive = false;
}

void Pokemon::GetDamage(float damage)
{
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}


