// InstructionParser header file
// Autumn Clark
// 01-27-2023

#pragma once
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

class InstructionParser {
private:
	// Instance variables
	static InstructionParser* instancePtr;
	std::unordered_map<std::string, std::string> parser;

	// Private methods
	InstructionParser();
	void loadInstructions();
	void loadRegisters();
	void loadMemory();
	std::string convertToHexString(int decimal);

public:
	// Public Methods
	static InstructionParser* getInstance();
	std::unordered_map<std::string, std::string> getParser();

};
