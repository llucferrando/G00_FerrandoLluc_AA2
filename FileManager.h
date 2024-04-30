#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
class FileManager
{
	
public:
	static FileManager* getInstance();
	std::string LoadFile(const std::string& filePath);

private:
	FileManager() = default;
	static FileManager * instance;
};

