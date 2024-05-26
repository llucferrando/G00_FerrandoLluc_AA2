#include "Player.h"
#include "Map.h"
#include "GameManager.h"
Player::Player()
{
	pokemonsCaptured = 0;
	currentPokeballs = 99999;
	position = new Vector2D(5, 5);
	direction = new Vector2D(0, 0);
	damage = 3;
}


void Player::Update(Map* map)
{
	if (direction->x == 0 && direction->y == 0)
		return;

	Vector2D nextPosition = *position;
	nextPosition.x += direction->x;
	nextPosition.y += direction->y;

	switch (map->GetTile(nextPosition)) {
		case TileType::Enemy:
			GameManager::getInstance().gameState = GameState::Capturing;
			GameManager::getInstance().fightingPokemon = map->getPokemonFromPosition(nextPosition);
			break;
		case TileType::PokeBall:
			currentPokeballs++;
			map->ClearTile(nextPosition);
			map->SpawnPokeballRandomPosition(map->GetCuadrantFromPosition(nextPosition));
			break;
	}

	if (map->IsBlockingCollision(nextPosition))
		return;

	map->ClearTile(*position);
	position->x += direction->x;
	position->y += direction->y;
	map->UpdatePosition(*position, TileType::Player);
}


