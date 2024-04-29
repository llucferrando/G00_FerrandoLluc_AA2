#pragma once
#include <iostream>
#include <fstream>
#include <string>
class FileManager
{
	
public:
	static FileManager& getInstance() { static FileManager instance; return instance;}
	std::string LoadFile(const std::string& filePath);

private:
	FileManager();
};

