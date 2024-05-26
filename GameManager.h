#pragma once
#include "InputManager.h"
#include "GameConfigInfo.h"
#include "Map.h"
#include <cstdlib>
enum Option { Attack, Catch, Scape };

class GameManager {
private:
    GameManager();

    // Evitar la copia de la instancia
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

public:
    // Miembros públicos
    GameConfigInfo* config;
    Player* player;
    InputManager* inputManager;
    GameState gameState;
    Map* myMap;
    float fps;
    Option selectedOption = Attack;
    Pokemon* fightingPokemon;

    // Método estático para obtener la instancia única
    static GameManager& getInstance() {
        // Se garantiza que solo se crea una instancia
        static GameManager instance;
        return instance;
    }

    // Métodos públicos
    void GameLoop();
    void Render();
    void RenderHud();
    void RenderFigth();
    void ChangeOption(int increment);
    void ExecuteOption();
};

// Inicialización estática del puntero a nullptr
