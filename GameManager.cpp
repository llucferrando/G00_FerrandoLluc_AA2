#include "GameManager.h"
#define FPS 5
GameManager::GameManager()
{
	config = new GameConfigInfo();
	gameState = GameState::Menu;
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
	while(Playing())
	{
		float dt = 1000 / fps;
		Sleep(dt);

		inputManager->Inputs(gameState);
		switch (gameState)
		{
		case Menu:
			if (inputManager->upKeyPressed)
				ChangeOption(-1, 2);
			if (inputManager->downKeyPressed)
				ChangeOption(1, 2);
			if (inputManager->spaceKeyPressed)
				ExecuteOptionMenu();
			break;
		case Scauting:	
			player->Inputs(inputManager);
			player->Update(myMap);
			myMap->Update(dt);

			break;
		case Capturing:
			if (inputManager->upKeyPressed)
				ChangeOption(-1,3);
			if (inputManager->downKeyPressed)
				ChangeOption(1,3);
			if (inputManager->spaceKeyPressed)
				ExecuteOption();
			break;
		default:
			break;
		}
		if(Playing())
			Render();
	}
	if (gameState == Win)
		WinScreen();
	if (gameState == GameOver)
		GameOverScreen();
}

void GameManager::Render()
{
	system("cls");
	if (gameState == Menu) 
	{
		RenderMenu();
		return;
	}
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

	switch (myMap->GetCuadrantFromPosition(*player->position))
	{
	case 1:
		std::cout << "              Pueblo Paleta";
		break;
	case 2:
		std::cout << "              Bosque";
		break;
	case 3:
		std::cout << "              Cueva Celeste";
		break;
	case 4:

		std::cout << "              Liga PokeEnti";
		if (!myMap->isMewAlive()) 
		{
			gameState = Win;
		}else
			gameState = GameOver;

		break;
	}
}

void GameManager::RenderMenu()
{
	int botOffset = 3;

	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "Menu " << "\n";

	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "Play";
	if (selectedOption == Attack)
		std::cout << "  <-----";
	std::cout << std::endl;


	for (int i = 0; i < screenDrawStartPosX - botOffset; i++)
		std::cout << " ";
	std::cout << "Quit";
	if (selectedOption == Catch)
		std::cout << "  <-----";
	std::cout << std::endl;
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

void GameManager::ChangeOption(int increment,int options)
{
	selectedOption = static_cast<Option>((static_cast<int>(selectedOption) + increment) % options);
	if (selectedOption < 0)
		selectedOption = static_cast<Option>((static_cast<int>(options - 1)));
	if(selectedOption > static_cast<Option>((static_cast<int>(options))))
		selectedOption = static_cast<Option>((static_cast<int>(0)));
}

void GameManager::ExecuteOption()
{
	switch (selectedOption)
	{
	case Attack:
		fightingPokemon->GetDamage(player->damage);
		if(!fightingPokemon->alive)
			gameState = Scauting;
		break;
	case Catch:
		if (player->currentPokeballs > 0)
		{
			player->currentPokeballs--;
			if (fightingPokemon->TryToCath())
			{
 				player->pokemonsCaptured += 1;
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

void GameManager::ExecuteOptionMenu()
{
	switch (selectedOption)
	{
	case Attack:
		gameState = Scauting;
		break;
	case Catch:
		gameState = Exit;
		break;
	}
}

void GameManager::GameOverScreen()
{
	system("cls");
	int TopOffset = 15;
	for (int i = 0; i < 5; i++)
		std::cout << "\n";
	for (int i = 0; i < screenDrawStartPosX - TopOffset; i++)
		std::cout << " ";

	std::cout << "Pokemons Capturados [" << player->pokemonsCaptured << "]  PokeBalls  [" << player->currentPokeballs << "]\n\n";

	for (int i = 0; i < screenDrawStartPosX - TopOffset; i++)
		std::cout << " ";
	std::cout << "Perdiste, has llegado a liga POKEenti sin capturar a MEWTWO" << std::endl;

	for (int i = 0; i < 20; i++)
		std::cout << "\n";
}

void GameManager::WinScreen()
{
	system("cls");
	int TopOffset = 15;
	for (int i = 0; i < 5; i++)
		std::cout << "\n";
	for (int i = 0; i < screenDrawStartPosX - TopOffset; i++)
		std::cout << " ";

	std::cout << "Pokemons Capturados [" << player->pokemonsCaptured << "]  PokeBalls  [" << player->currentPokeballs << "]\n\n";

	for (int i = 0; i < screenDrawStartPosX - TopOffset; i++)
		std::cout << " ";
	std::cout << "Has ganado! Llegaste a la liga POKEenti derrotando a MEWTWO" << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << "\n";
}

bool GameManager::Playing()
{
	return gameState != GameOver && gameState != Win && gameState != Exit;
}

	