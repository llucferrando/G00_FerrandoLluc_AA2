#include <iostream>
#include <fstream>
#include <string>
#include "GameManager.h"



void main()
{
   
    GameManager * myManager = new GameManager();
    myManager->Init();
   myManager->GameLoop();
    myManager->Render();
  
    
}