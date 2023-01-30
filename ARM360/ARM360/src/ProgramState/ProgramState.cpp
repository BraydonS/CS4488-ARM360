#include "stdafx.h"
#include "Hex4Digit.h"
#include "MemoryHistorySpace.h"

//Author: Braydon Spaulding
//Date Started: 01/24

class ProgramState {
	
	constexpr static int TOTAL_MEMORY_SPACES = 256;

	std::vector<Hex4digit> registers;
	Hex4digit input;
	Hex4digit output;
	std::vector<MemoryHistorySpace> pchistory;
	std::vector<std::vector<Hex4digit>> memorystatehistory;

	static ProgramState getInstance() {
		if (emulationState == nullptr) {
			emulationState = new ProgramState();
		}
		return *emulationState;
	}

	bool initializeState(std::vector<Hex4digit> code);

	void clearProgramState() {

	}

	std::string printableProgramState();

	Hex4digit getMemoryStateValue(int n);

private:
	constexpr static int REGISTER_COUNT = 16;

	static ProgramState *emulationState;

	void fillOutMemory(std::vector<Hex4digit> toFillOut);

	ProgramState() {
		registers = std::vector<Hex4digit>(REGISTER_COUNT);
	}
};