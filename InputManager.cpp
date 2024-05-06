#include "InputManager.h"

bool InputManager::Inputs(Vector2D * movement, bool &isPlaying)
{
    static bool upKeyPressed = false;
    static bool leftKeyPressed = false;
    static bool downKeyPressed = false;
    static bool rightKeyPressed = false;
    static bool spaceKeyPressed = false;
    static bool escKeyPressed = false;
    isPlaying = true;
    

    if (GetAsyncKeyState(VK_UP))
    {
        if (!upKeyPressed){
            upKeyPressed = true;
            movement->_y-=1;

        }
    }else{
        upKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        if (!downKeyPressed) {
            downKeyPressed = true;
            movement->_y += 1;
        }
    }
    else {
        downKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if (!rightKeyPressed) {
            rightKeyPressed = true;
            movement->_x += 1;
            
        }
    }
    else {
        rightKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        if (!leftKeyPressed) {
            leftKeyPressed = true;
             movement->_x -=1;
        }
    }
    else {
        leftKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (!spaceKeyPressed) {
            spaceKeyPressed = true;
            std::cout << "Space";
        }
    }
    else {
        spaceKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        if (!escKeyPressed) {
            escKeyPressed = true;
            isPlaying = false;
            std::cout << isPlaying;
            
        }
    }
    else {
        escKeyPressed = false;
        
    }
    return isPlaying;
}


