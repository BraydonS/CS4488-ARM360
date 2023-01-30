// Orchestrator header file
// Autumn Clark
// 01-27-2023

#pragma once
#include <string>
#include <vector>
#include "ExecutorFacade.h"
#include "FileManager/FileManager.h"
#include "Hex4digit.h"
#include "HexadecimalConvertor.h"
#include "ProgramState/ProgramState.h"
#include "TranslatorFacade.h"

class Orchestrator {
private:
	//Instance variables
	static Orchestrator* instancePtr;
	ProgramState state;
	TranslatorFacade translator;
	ExecutorFacade executor;
	FileManager fileManager;
	std::string error;

	// Private methods
	Orchestrator();
	void resetError();


public:
	// Public methods
	static Orchestrator getInstance();
	std::string getError();
	bool next();
	void clearProgram();
	ProgramState getProgramState();
	void sendInput(char input[]);
	std::vector<char> getOutput();
	bool translateAndLoad(std::string path);
	std::vector<char> convertToHexChars(short number);
	int convertToInt(char number[]);
	std::string loadFile(std::string path);

};
