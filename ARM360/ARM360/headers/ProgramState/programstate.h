//Author: Braydon Spaulding

#pragma once

#include <vector>
#include <memory>
#include <string>

class ProgramState {

public:
	constexpr static int TOTAL_MEMORY_SPACES = 256;

	/*std::vector<hex4digit> registers;
	 hex4digit input;
	 hex4digit output;
	 std::vector<memoryhistoryspace> pchistory;
	 std::vector<std::vector<hex4digit>> memorystatehistory;*/

	static ProgramState getInstance();
	//bool initializeState(std::vector<Hex4digit> code);

	void clearProgramState();

	std::string printableProgramState();

	// Hex4digit getMemoryStateValue(int n);

private:
	constexpr static int REGISTER_COUNT = 16;

	static ProgramState emulationState;

	// void fillOutMemory(std::vector<Hex4Digit> toFillOut);

	ProgramState();

};
