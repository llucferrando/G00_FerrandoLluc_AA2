#pragma once
#include "FileManager.h"
#include "InputManager.h"
#include "Vector2D.h"
#include "Map.h"
#include "GameConfigInfo.h"
#include "Player.h"
#include <cstdlib>


class GameManager
{
	public:
        GameManager() {};
		GameConfigInfo * gi = new GameConfigInfo;
        Player* myPlayer = new Player();
        Vector2D* movement = new Vector2D(0, 0);
        InputManager* ip = new InputManager();
        
       
        Map* myMap = new Map(gi);
        bool isPlaying = true;

        void Init();
        void GameLoop();
        void Render();
	
};

