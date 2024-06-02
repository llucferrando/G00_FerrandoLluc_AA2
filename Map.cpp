#include "Map.h"

Map::Map(GameConfigInfo * gameConfig) : config(gameConfig)
{
	tiles = new TileType*[config->width]; 
	width = config->width;
	height = config->height;
	for (int i = 0; i < config->width; ++i) 
	{   
		tiles[i] = new TileType[config->height];
	}
}
void Map::PrintTile(Vector2D position)
{
	TileType type = tiles[position.x][position.y];
	char c = static_cast<char>(type);
	std::cout << c;
}

TileType Map::GetTile(Vector2D position)
{
	return tiles[position.x][position.y];
}

bool Map::IsBlockingCollision(Vector2D position)
{
	switch (GetTile(position))
	{
	case TileType::None:
		return false;
		break;
	case TileType::Player:
		return true;
		break;
	case TileType::Mew:
	case TileType::Enemy:
		return true;
		break;
	case TileType::Wall:
		return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}

void Map::UpdatePosition(Vector2D position, TileType type)
{
	tiles[position.x][position.y] = type;
}

void Map::ClearTile(Vector2D position)
{
	tiles[position.x][position.y] = TileType::None;
}
void Map::InitMap(Player*myPlayer)
{
	for (int y = 0; y < config->height; ++y)
	{
		for (int x = 0; x < config->width; ++x)
		{
			tiles[x][y] = TileType::None;
		}
	}
	tiles[myPlayer->position->x][myPlayer->position->y] = TileType::Player;
	GenWalls();
	GenPokemons();
	PrintMap(myPlayer,4);
	SpawnPokeballRandomPosition(1);
	SpawnPokeballRandomPosition(2);
	SpawnPokeballRandomPosition(3);
	SpawnPokeballRandomPosition(4);

}
Vector2D* Map::GetRandomPositionFromCuadrant(int cuadrant) {
	int startX, endX, startY, endY;

	int halfWidth = width / 2;
	int halfHeight = height / 2;

	switch (cuadrant) {
	case 1: // Top-left
		startX = 1;
		endX = halfWidth - 1;
		startY = 1;
		endY = halfHeight - 1;
		break;
	case 2: // Top-right
		startX = halfWidth + 1;
		endX = width - 2;
		startY = 1;
		endY = halfHeight - 1;
		break;
	case 4: // Bottom-left
		startX = 1;
		endX = halfWidth - 1;
		startY = halfHeight + 1;
		endY = height - 2;
		break;
	case 3: // Bottom-right
		startX = halfWidth + 1;
		endX = width - 2;
		startY = halfHeight + 1;
		endY = height - 2;
		break;
	default:
		return new Vector2D(-1, -1); // Cuadrante inválido
	}

	Vector2D* position = new Vector2D(0,0);
	do {
		position->x = startX + rand() % (endX - startX + 1);
		position->y = startY + rand() % (endY - startY + 1);
	} while (tiles[position->x][position->y] != TileType::None);

	return position;
}
Vector2D* Map::GetCenterPositionOfCuadrant(int cuadrant) {
	int startX, endX, startY, endY;

	int halfWidth = width / 2;
	int halfHeight = height / 2;

	switch (cuadrant) {
	case 1: // Top-left
		startX = 1;
		endX = halfWidth - 1;
		startY = 1;
		endY = halfHeight - 1;
		break;
	case 2: // Top-right
		startX = halfWidth + 1;
		endX = width - 2;
		startY = 1;
		endY = halfHeight - 1;
		break;
	case 4: // Bottom-left
		startX = 1;
		endX = halfWidth - 1;
		startY = halfHeight + 1;
		endY = height - 2;
		break;
	case 3: // Bottom-right
		startX = halfWidth + 1;
		endX = width - 2;
		startY = halfHeight + 1;
		endY = height - 2;
		break;
	default:
		return new Vector2D(-1, -1); // Cuadrante inválido
	}

	int centerX = (startX + endX) / 2;
	int centerY = (startY + endY) / 2;

	return new Vector2D(centerX, centerY);
}
void Map::BreakCuadrantWall(int cuadrant) {
	if (cuadrant == 3) {
		for (int x = config->width / 2 + 1; x < config->width - 1; ++x) {
			tiles[x][config->height / 2] = TileType::None;
		}
	}
	if (cuadrant == 2) {
		for (int y = 1; y < config->height / 2; ++y) {
			tiles[config->width / 2][y] = TileType::None;
		}
	}
	if (cuadrant == 4) {
		for (int y = config->height / 2 + 1; y < config->height - 1; ++y) {
			tiles[config->width / 2][y] = TileType::None;
		}
	}
}
bool Map::isMewAlive()
{
	return mew->alive;
}
bool Map::isPositionInCuadrant(Vector2D _position, int cuadrant) {
	int startX, endX, startY, endY;

	int halfWidth = width / 2;
	int halfHeight = height / 2;

	switch (cuadrant) {
	case 1: // Top-left
		startX = 1;
		endX = halfWidth - 1;
		startY = 1;
		endY = halfHeight - 1;
		break;
	case 2: // Top-right
		startX = halfWidth + 1;
		endX = width - 2;
		startY = 1;
		endY = halfHeight - 1;
		break;
	case 4: // Bottom-left
		startX = 1;
		endX = halfWidth - 1;
		startY = halfHeight + 1;
		endY = height - 2;
		break;
	case 3: // Bottom-right
		startX = halfWidth + 1;
		endX = width - 2;
		startY = halfHeight + 1;
		endY = height - 2;
		break;
	default:
		return false; // Cuadrante inválido
	}

	if (_position.x >= startX && _position.x <= endX &&
		_position.y >= startY && _position.y <= endY) {
		return true;
	}
	else {
		return false;
	}
}
Pokemon* Map::getPokemonFromPosition(Vector2D position)
{
	for (Pokemon* pokemon : pokemons)
	{
		if (pokemon->position->x == position.x &&
			pokemon->position->y == position.y)
				return pokemon;
	}
	return nullptr;
}
int Map::GetCuadrantFromPosition(Vector2D position)
{
	int halfWidth = width / 2;
	int halfHeight = height / 2;

	if (position.x >= 1 && position.x <= halfWidth && position.y >= 1 && position.y <= halfHeight)
	{
		return 1;
	}
	else if (position.x >= halfWidth + 1 && position.x <= width - 2 && position.y >= 1 && position.y <= halfHeight)
	{
		return 2;
	}
	else if (position.x >= 1 && position.x <= halfWidth && position.y >= halfHeight + 1 && position.y <= height - 2)
	{
		return 4;
	}
	else if (position.x >= halfWidth + 1 && position.x <= width - 2 && position.y >= halfHeight + 1 && position.y <= height - 2)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
void Map::SpawnPokeballRandomPosition(int cuadrant)
{
	Vector2D* randPosition;
	do
	{
		randPosition = GetRandomPositionFromCuadrant(cuadrant);
	
	} while (GetTile(*randPosition) != TileType::None);

	tiles[randPosition->x][randPosition->y] = TileType::PokeBall;

}



void Map::GenWalls()
{
	for (int x = 0; x < config->width; ++x)
	{
		tiles[x][0] = TileType::Wall;
		tiles[x][config->height - 1] = TileType::Wall;
	}
	//wall apertura cuadrante 2 -> 3
	if (!unlockedLigaPokeEnti)
		for (int x = config->width / 2; x < config->width; ++x)
		tiles[x][config->height / 2] = TileType::Wall;

	//wall apertura cuadrante 1 -> 4
	for (int x = 0; x < config->width / 2; ++x)
		tiles[x][config->height / 2] = TileType::Wall;



	for (int y = 0; y < config->height; ++y)
	{
		tiles[0][y] = TileType::Wall;
		tiles[config->width - 1][y] = TileType::Wall;
	}


	//wall apertura cuadrante 1 -> 2
	if(!unlockedBosque)
		for (int y = 0; y < config->height / 2; ++y)
			tiles[config->width / 2][y] = TileType::Wall;
	//wall apertura cuadrante 3-> 4
	if (!unlockedLigaPokeEnti)
		for (int y = config->height / 2; y < config->height; ++y)
		tiles[config->width / 2][y] = TileType::Wall;
}
void Map::GenPokemons()
{
	for (int i = 0; i < config->minPokemonsPPaleta; i++)
	{
		Pokemon* newPokemon = new Pokemon(config->minTimeToMove,config->maxTimeToMove);
		newPokemon->position = GetRandomPositionFromCuadrant(1);
		newPokemon->cuadrant = 1;
		pokemons.push_back(newPokemon);
	}
	for (int i = 0; i < config->pokemonsBosque; i++)
	{
		Pokemon* newPokemon = new Pokemon(config->minTimeToMove, config->maxTimeToMove);
		newPokemon->position = GetRandomPositionFromCuadrant(2);
		newPokemon->cuadrant = 2;
		pokemons.push_back(newPokemon);
	}
	for (int i = 0; i < config->pokemonsCueva; i++)
	{
		Pokemon* newPokemon = new Pokemon(config->minTimeToMove, config->maxTimeToMove);
		newPokemon->position = GetRandomPositionFromCuadrant(3);
		newPokemon->cuadrant = 3;
		pokemons.push_back(newPokemon);
	}

	mew = new Pokemon(config->minTimeToMove, config->maxTimeToMove);
	mew->name = "Mew";
	mew->canMove = false;
	mew->maxHp = config->vidaMew;
	mew->position = GetCenterPositionOfCuadrant(3);
	mew->cuadrant = 3;
	pokemons.push_back(mew);
	UpdatePosition(*mew->position, TileType::Mew);

}
void Map::Update(float dt)
{
	for (Pokemon* pokemon : pokemons)
	{
		if(pokemon->alive)
			pokemon->Update(this,dt);
	}
}
void Map::PrintMap(Player* myPlayer, int area)
{
	
	Vector2D playerPos = *myPlayer->position;

	
	int startX = playerPos.x - area;
	int endX = playerPos.x + area;
	int startY = playerPos.y - area;
	int endY = playerPos.y + area;

	
	if (startX < 0) startX = 0;
	if (endX >= config->width) endX = config->width - 1;
	if (startY < 0) startY = 0;
	if (endY >= config->height) endY = config->height - 1;

	
	int width = endX - startX + 1;
	int height = endY - startY + 1;

	
	for (int i = 0; i < screenDrawStartPosY; i++)
		std::cout << "\n";

	
	for (int i = 0; i < screenDrawStartPosX; i++)
		std::cout << " ";
	std::cout << " ";
	for (int i = 0; i < width; i++)
		std::cout << "_";
	std::cout << " \n";

	
	for (int y = startY; y <= endY; ++y)
	{
		
		for (int i = 0; i < screenDrawStartPosX; i++)
			std::cout << " ";
		std::cout << "|";

		for (int x = startX; x <= endX; ++x)
		{
			PrintTile(Vector2D{ x, y });
		}
		std::cout << "|\n";
	}

	
	for (int i = 0; i < screenDrawStartPosX; i++)
		std::cout << " ";

	
	std::cout << " ";
	for (int i = 0; i < width; i++)
		std::cout << "-";
	std::cout << " \n";
}
void Map::PrintFullMap()
{
	for (int y = 0; y < config->height; ++y)
	{
		for (int x = 0; x < config->width; ++x)
		{
			PrintTile(Vector2D(x, y));
		}
		std::cout << std::endl;
	}
}