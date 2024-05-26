#pragma once
#include "GameConfigInfo.h"
#include "Player.h"
#include "Pokemon.h"
#include <vector>
#define screenDrawStartPosX 30
#define screenDrawStartPosY 7
enum class TileType {None = ' ', Player = 'A', Enemy = 'P', Wall= 'X' ,PokeBall = 'O'};
class Map
{
private:
	GameConfigInfo* config;
	TileType** tiles;
	int width;
	int height;
public:
	bool unlockedBosque;
	bool unlockedCuevaCeleste;
	bool unlockedLigaPokeEnti;

	Map(GameConfigInfo* gameConfigInfo);
	
	
	std::vector<Pokemon*> pokemons;
	
	
	void PrintMap(Player* myPlayer,int area);
	void PrintFullMap();
	void InitMap(Player * myPlayer);
	void GenWalls();
	void GenPokemons();
	void Update(float dt);
	void PrintTile(Vector2D position);
	TileType GetTile(Vector2D position);
	bool IsBlockingCollision(Vector2D position);
	void UpdatePosition(Vector2D position,TileType type);
	void ClearTile(Vector2D position);
	Vector2D* GetRandomPositionFromCuadrant(int cuadrant);
	Pokemon* getPokemonFromPosition(Vector2D position);
	int GetCuadrantFromPosition(Vector2D position);
	void SpawnPokeballRandomPosition(int cuadrant);
	Vector2D* GetCenterPositionOfCuadrant(int cuadrant);
	void BreakCuadrantWall(int cuadrant);
};

