//Author: Braydon Spaulding

#pragma once

#include <string>
#include <fstream>
#include <regex>

class FileManager {
public:

	static FileManager* getInstance();

	bool checkFile(std::string pathString);
	std::string readFile(const std::string& path);
	bool writeFile(const std::string& path, const std::string& content);

	std::string getLastErrorMessage();

private:
	
	std::string lastErrorMessage;

	static FileManager* instance;

	FileManager();

};