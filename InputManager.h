#pragma once
#include <iostream>
#include "Player.h"
#include "Windows.h"
enum GameState { Scauting, Capturing, GameOver };


class InputManager
{
public:
	InputManager() = default;
    bool upKeyPressed;
    bool leftKeyPressed;
    bool downKeyPressed;
    bool rightKeyPressed;
    bool spaceKeyPressed;
    bool escKeyPressed;

	bool Inputs(Player* player, GameState &state);
};

