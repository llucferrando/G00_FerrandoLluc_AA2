#include "Map.h"

Map::Map(GameConfigInfo * gameConfig) : gi(gameConfig)
{
	field = new Box*[gi->ancho];   
	for (int i = 0; i < gi->ancho; ++i) 
	{   
		field[i] = new Box [gi->alto];     
	}
}
void Map::PrintBoxInMap(Box * myBox)
{
	field[myBox->myBoxPosition->_x][myBox->myBoxPosition->_y].PrintBox();
}

void Map::InitMap(Player*myPlayer)
{
	field[myPlayer->myPosition->_x][myPlayer->myPosition->_y].myElement = myPlayer;
	InitMapElements();
	PrintMap(myPlayer);
}

void Map::InitMapElements()
{
	for(int i=0; i<gi->pokemonsBosque; i++)
	{
		Pokemon*newPokemon = new Pokemon();
		field[newPokemon->pokePos->_x][newPokemon->pokePos->_y].myElement = newPokemon;
	}
		
}

void Map::PrintMap(Player* myPlayer)
{
	field[myPlayer->myPosition->_x][myPlayer->myPosition->_y].myElement = myPlayer;
	halfY = gi->alto / 2;
	halfX = gi->ancho / 2;
	for (int i = 0; i < gi->alto; ++i)
	{
		for (int j = 0; j < gi->ancho; ++j)
		{
			if ((i == 7 && j == 15)|| (i == 15 && j == 22) || (i == 22 && j == 15))
			{

				field[j][i].myElement = new Door;
			}
			else if (i == 0 || j == 0 || i == 0 || j == gi->ancho - 1 || i == gi->alto - 1 || i==halfY || j==halfX)
			{
				field[j][i].myElement = new Walls;
			}
			
			field[j][i].PrintBox();
			
		}

		std::cout << std::endl;
	}

}