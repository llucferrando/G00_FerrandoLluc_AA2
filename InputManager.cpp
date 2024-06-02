#include "InputManager.h"

bool InputManager::Inputs(Player* player, GameState &state)
{
    player->direction = new Vector2D(0, 0);

    if (GetAsyncKeyState(VK_UP))
    {
        if (!upKeyPressed){
            upKeyPressed = true;
            player->direction->y = -1;
        }
    }else{
        upKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_DOWN)) // Verifica si la tecla DOWN está presionada en este momento
    {
        if (!downKeyPressed) {
            downKeyPressed = true; // Se establece como true solo si no estaba presionada previamente
            player->direction->y = +1;
        }
    }
    else {
        downKeyPressed = false; // Se establece como false cuando la tecla se suelta
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if (!rightKeyPressed) {
            rightKeyPressed = true;
            player->direction->x = +1;
        }
    }
    else {
        rightKeyPressed = false;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        if (!leftKeyPressed) {
            leftKeyPressed = true;
            player->direction->x = -1;
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


