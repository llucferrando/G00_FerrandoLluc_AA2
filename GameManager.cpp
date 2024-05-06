#include "GameManager.h"

void GameManager::Init()
{
	//INIT THE MAP
	std::cout << gi->ancho << gi->alto << gi->pokemonsBosque <<  gi->minPokemonsBosque<<std::endl;
	myMap->InitMap(myPlayer);
	
	
	
	

}

void GameManager::GameLoop()
{
	//GAME LOOP
	while(isPlaying)
	{
		Sleep(500);
		
		ip->Inputs(movement, isPlaying);
		if(myMap->field[myPlayer->myPosition->_x + movement->_x][myPlayer->myPosition->_y + movement->_y].myElement != nullptr)
		{
			myMap->field[myPlayer->myPosition->_x + movement->_x][myPlayer->myPosition->_y + movement->_y].myElement = nullptr;
			myMap->PrintBoxInMap(&myMap->field[myPlayer->myPosition->_x][myPlayer->myPosition->_y]);
		}
		myPlayer->myPosition->_x += movement->_x;
		myPlayer->myPosition->_y += movement->_y;
		myMap->field[myPlayer->myPosition->_x][myPlayer->myPosition->_y].myElement = nullptr;
		myMap->PrintBoxInMap(&myMap->field[myPlayer->myPosition->_x][myPlayer->myPosition->_y]);
		
		movement->_x = 0;
		movement->_y = 0;

		Render();
		
		
	}
	
}

void GameManager::Render()
{
	system("cls");
	myMap->PrintMap(myPlayer);
}

	