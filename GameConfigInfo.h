#pragma once
#include "FileManager.h"
class GameConfigInfo
{
public:
    GameConfigInfo() { Code("config.txt"); };
    int ancho, alto, pokemonsPPaleta, minPokemonsPPaleta, pokemonsBosque, minPokemonsBosque = 0;

    void Code(const std::string& filePath)
    {
        std::string data = FileManager::getInstance()->LoadFile(filePath);
        if (data.empty()) {
            std::cerr << "Error: archivo de configuración vacío" << std::endl;
            return;
        }

        std::istringstream iss(data);
        std::string token;

        // Leemos los valores de cada línea y los asignamos a las variables correspondientes del struct
        if (std::getline(iss, token, ';')) {
            ancho = std::stoi(token);
        }
        if (std::getline(iss, token, ';')) {
            alto = std::stoi(token);
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
        if (std::getline(iss, token)) {
            minPokemonsBosque = std::stoi(token);
        }
    }
};

