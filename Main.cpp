#include <iostream>
#include <fstream>
#include <string>
#include "GameManager.h"


int main() {

    GameManager::getInstance().GameLoop();

    return 0;
}