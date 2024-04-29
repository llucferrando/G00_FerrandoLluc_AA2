#pragma once
#include "FileManager.h"
struct GameInfo
{
	GameInfo(std::string filePath){};
	int anchco, alto, pokemonsPPaleta, minPokemonsPPaleta, pokemonsBosque, minPokemonsBosque;

	void Code(const std::string&filePath)
	{
		std::string data = FileManager::getInstance().LoadFile(filePath);
	
	}
};
class GameManager
{
	public:
		GameInfo gi;

		
	
};

