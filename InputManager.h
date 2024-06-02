#pragma once
#include <iostream>
#include "Windows.h"
enum GameState { Menu,Scauting, Capturing, GameOver,Win,Exit };


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

	bool Inputs(GameState &state);
};

