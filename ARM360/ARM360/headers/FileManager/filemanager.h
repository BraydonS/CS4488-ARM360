//Author: Braydon Spaulding

#pragma once

#include <string>
#include <fstream>

class FileManager {
public:

	static FileManager getInstance();
	bool checkFile(std::string pathString);

	std::string fileToString(std::string path);
	std::string readFile(std::string file);
	std::string getLastErrorMessage();

	bool saveFile(std::string path, std::string content);

private:
	
	std::string defaultMessage;
	std::string lastErrorMessage;
	std::ofstream writer;

	static FileManager instance;

	FileManager();

	bool setWriteFile(std::string path);
	void write(std::string toWrite);
	void closeWrite();

};