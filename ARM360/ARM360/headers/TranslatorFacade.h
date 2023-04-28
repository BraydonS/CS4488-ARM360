// TranslatorFacade header file
// Autumn Clark
// 01-26-2023

#pragma once
#include <string>
#include "Translator.h"
#include "Hex4digit.h"

class TranslatorFacade {
private:
	// Instance variables
	Translator* translator;
public:
	// Constructor
	TranslatorFacade();

	//Methods
	bool loadFile(std::string armFile);
	void clearFile();
	bool isTranslatable();
	std::vector<Hex4digit> translateToMachine();
	std::string getLastExceptionMessage();
};
