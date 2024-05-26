#pragma once
#include "FileManager.h"
class GameConfigInfo
{
public:
    GameConfigInfo() { Code("config.txt"); };
    int width, height, pokemonsPPaleta, minPokemonsPPaleta, pokemonsBosque, minPokemonsBosque, pokemonsCueva, minPokemonsCueva;
    int minTimeToMove, maxTimeToMove;
    int vidaMew;

    void Code(const std::string& filePath)
    {
        std::string data = FileManager::getInstance()->LoadFile(filePath);
        if (data.empty()) {
            std::cerr << "Error: archivo de configuración vacío" << std::endl;
            return;
        }

        std::istringstream iss(data);
        std::string token;

        
        if (std::getline(iss, token, ';')) {
            width = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            height = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            pokemonsPPaleta = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            minPokemonsPPaleta = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            pokemonsBosque = std::stoi(token);
        }
        if (std::getline(iss, token,';')) {
            minPokemonsBosque = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            pokemonsCueva = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            minPokemonsCueva = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            minTimeToMove = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            maxTimeToMove = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            vidaMew = std::stoi(token);
        }
    }
};

