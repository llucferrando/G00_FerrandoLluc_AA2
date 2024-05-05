#include "Map.h"

Map::Map(GameConfigInfo * gameConfig) : gi(gameConfig)
{

	field = new Box*[gi->ancho];   
	//field = new Box * [7];
	for (int i = 0; i < gi->ancho; ++i) 
	{         
		field[i] = new Box [gi->alto];     
	}
	
}
void Map::PrintBoxInMap(Box * myBox)
{
	//field*[myBox->myBoxPosition->_x][myBox->myBoxPosition->_y]->PrintBox();
}

void Map::InitMap(Player*myPlayer)
{
	field[myPlayer->myPosition->_x][myPlayer->myPosition->_y].myElement = myPlayer;
	//InitMapElements();
	PrintMap();
	
}

void Map::InitMapElements()
{
	for(int i=0; i<gi->pokemonsBosque; i++)
	{
		Pokemon*newPokemon = new Pokemon();
		field[newPokemon->pokePos->_x][newPokemon->pokePos->_y].myElement = newPokemon;
	}
		
}

void Map::PrintMap()
{

	for (int i = 0; i < gi->ancho; ++i)
	{
		for (int j = 0; j < gi->alto; ++j)
		{
			field[i][j].PrintBox();
			//std::cout <<"X";
			
		}

		std::cout << std::endl;
	}

}