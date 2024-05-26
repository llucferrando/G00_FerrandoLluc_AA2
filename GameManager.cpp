#include "GameManager.h"
#define FPS 5
GameManager::GameManager()
{
	config = new GameConfigInfo();
	gameState = GameState::Scauting;
	inputManager = new InputManager();
	myMap = new Map(config);
	player = new Player();
	//INIT THE MAP
	this->fps = FPS;
	std::cout << config->width << config->height << config->pokemonsBosque << config->minPokemonsBosque << std::endl;
	myMap->InitMap(player);
}

void GameManager::GameLoop()
{
	//GAME LOOP
	while(gameState != GameOver)
	{
		float dt = 1000 / fps;
		Sleep(dt);

		inputManager->Inputs(player, gameState);
		switch (gameState)
		{
		case Scauting:	
			player->Update(myMap);
			myMap->Update(dt);

			break;
		case Capturing:
			if (inputManager->upKeyPressed)
				ChangeOption(-1);
			if (inputManager->downKeyPressed)
				ChangeOption(1);
			if (inputManager->spaceKeyPressed)
				ExecuteOption();
			break;
		default:
			break;
		}
		Render();


	}
}

void GameManager::Render()
{
	system("cls");
	RenderHud();
	myMap->PrintMap(player,5);
	RenderFigth();
}

void GameManager::RenderHud()
{
	int TopOffset = 15;

	for (int i = 0; i < screenDrawStartPosX - TopOffset; i++)
		std::cout << " ";
	std::cout << "Pokemons Capturados [" << player->pokemonsCaptured << "]  PokeBalls  [" << player->currentPokeballs << "]\n\n";

	for (int i = 0; i < screenDrawStartPosX - TopOffset; i++)
		std::cout << " ";
	std::cout << "              Nombre ciudad";


}

void GameManager::RenderFigth()
{
	if (gameState != Capturing)
		return;
	int botOffset = 3;

	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "[" << fightingPokemon->name << "]  " << "[" << fightingPokemon->hp << "]" << "\n";

	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "Atacar";
	if(selectedOption == Attack)
		std::cout << "  <-----";
	std::cout << std::endl;


	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "Capturar";
	if (selectedOption == Catch)
		std::cout << "  <-----";
	std::cout << std::endl;


	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "Huir";
	if (selectedOption == Scape)
		std::cout << "  <-----";
	std::cout << std::endl;

}

void GameManager::ChangeOption(int increment)
{
	selectedOption = static_cast<Option>((static_cast<int>(selectedOption) + increment) % 3);
	if (selectedOption < 0)
		selectedOption = Option::Scape;
}

void GameManager::ExecuteOption()
{
	switch (selectedOption)
	{
	case Attack:
		fightingPokemon->GetDamage(player->damage);
		break;
	case Catch:
		if (player->currentPokeballs > 0)
		{
			player->currentPokeballs--;
			if (fightingPokemon->TryToCath())
			{
 				player->pokemonsCaptured += 10;
				if (player->pokemonsCaptured > config->minPokemonsPPaleta)
					myMap->BreakCuadrantWall(2);
				if (player->pokemonsCaptured > config->minPokemonsCueva)
					myMap->BreakCuadrantWall(4);
				if (player->pokemonsCaptured > config->minPokemonsBosque)
					myMap->BreakCuadrantWall(3);

				fightingPokemon->Disapear();
				myMap->ClearTile(*fightingPokemon->position);
				fightingPokemon = nullptr;
				gameState = Scauting;
			};
		}
		break;
	case Scape:
		fightingPokemon = nullptr;
		gameState = Scauting;
		break;
	default:
		break;
	}
}

	