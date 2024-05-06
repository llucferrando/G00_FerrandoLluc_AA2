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
		
		
		
		/*ip->Inputs(movement, isPlaying);
		myPlayer->myPosition->_x += movement->_x;
		myPlayer->myPosition->_y += movement->_y;
		movement->_x = 0;
		movement->_y = 0;

		Render();
		
		Sleep(100);*/
		
	}
	
}

void GameManager::Render()
{
	system("cls");
	myMap->PrintMap();
}

	