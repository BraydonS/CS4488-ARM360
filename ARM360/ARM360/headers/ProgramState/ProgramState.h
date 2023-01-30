//Author: Braydon Spaulding

#pragma once

#include <vector>
#include <memory>
#include <string>
#include <array>
#include "Hex4digit.h"
#include "MemoryHistorySpace.h"

class ProgramState {

public:
	constexpr static int TOTAL_MEMORY_SPACES = 256;

	 std::array<Hex4digit,256> registers;
	 Hex4digit input;
	 Hex4digit output;
	 std::vector<MemoryHistorySpace> pcHistory;
	 std::vector<std::array<Hex4digit, TOTAL_MEMORY_SPACES>> memoryStateHistory;

	static ProgramState getInstance();
	bool initializeState(std::vector<Hex4digit> code);

	void clearProgramState();

	std::string printableProgramState();

	Hex4digit getMemoryStateValue(int n);

private:
	constexpr static int REGISTER_COUNT = 16;

	static ProgramState emulationState;

	void fillOutMemory(std::vector<Hex4digit> toFillOut);

	ProgramState();

};
