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
    // Miembros p�blicos
    GameConfigInfo* config;
    Player* player;
    InputManager* inputManager;
    GameState gameState;
    Map* myMap;
    float fps;
    Option selectedOption = Attack;
    Pokemon* fightingPokemon;

    // M�todo est�tico para obtener la instancia �nica
    static GameManager& getInstance() {
        // Se garantiza que solo se crea una instancia
        static GameManager instance;
        return instance;
    }

    // M�todos p�blicos
    void GameLoop();
    void Render();
    void RenderHud();
    void RenderMenu();
    void RenderFigth();
    void ChangeOption(int increment,int options);
    void ExecuteOption();
    void ExecuteOptionMenu();
    void GameOverScreen();
    void WinScreen();
    bool Playing();
};

// Inicializaci�n est�tica del puntero a nullptr
