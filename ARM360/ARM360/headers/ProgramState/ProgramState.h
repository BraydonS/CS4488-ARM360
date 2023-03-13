//Author: Braydon Spaulding

#pragma once

#include <vector>
#include <memory>
#include <string>
#include <array>
#include "../Hex4digit.h"
#include "../MemoryHistorySpace.h"

class ProgramState {

public:
	constexpr static int TOTAL_MEMORY_SPACES= 256;
	constexpr static int REGISTER_COUNT = 16;

	 std::vector<Hex4digit> registers;
	 Hex4digit input;
	 Hex4digit output;
	 std::vector<MemoryHistorySpace> pcHistory;
	 std::vector<std::vector<Hex4digit>> memoryStateHistory;

	static ProgramState* getInstance();
	bool initializeState(std::vector<Hex4digit> code);

	void clearProgramState();

	std::string printableProgramState();

	Hex4digit getMemoryStateValue(int n);

private:

	static ProgramState* instance;

	void fillOutMemory(std::vector<Hex4digit> toFillOut);

	ProgramState();

};
