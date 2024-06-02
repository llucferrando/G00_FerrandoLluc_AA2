#include "InputManager.h"

bool InputManager::Inputs(GameState &state)
{
    if (GetAsyncKeyState(VK_UP))
    {
        if (!upKeyPressed){
            upKeyPressed = true;
        }
    }else{
        upKeyPressed = false;
       
    }

    if (GetAsyncKeyState(VK_DOWN)) // Verifica si la tecla DOWN está presionada en este momento
    {
        if (!downKeyPressed) {
            downKeyPressed = true; // Se establece como true solo si no estaba presionada previamente
        }
    }
    else {
        downKeyPressed = false; // Se establece como false cuando la tecla se suelta
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if (!rightKeyPressed) {
            rightKeyPressed = true;
        }
    }
    else {
        rightKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        if (!leftKeyPressed) {
            leftKeyPressed = true;
        }
    }
    else {
        leftKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (!spaceKeyPressed) {
            spaceKeyPressed = true;
        }
    }
    else {
        spaceKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        if (!escKeyPressed) {
            escKeyPressed = true;
            state = GameOver;
        }
    }
    else {
        escKeyPressed = false;
        
    }
    return  state != GameOver;
}


