#pragma once
#include <iostream>
#include "Player.h"
#include "Vector2D.h"
#include "Windows.h"



class InputManager
{
public:
	InputManager() = default;

	bool Inputs(Vector2D * movement, bool &isPlaying);
};

