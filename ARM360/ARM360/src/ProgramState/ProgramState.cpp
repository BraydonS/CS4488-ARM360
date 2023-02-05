#include "stdafx.h"
#include "Hex4Digit.h"
#include "MemoryHistorySpace.h"

//Author: Braydon Spaulding
//Date Started: 01/24

class ProgramState {

public:
	
	constexpr static int TOTAL_MEMORY_SPACES = 256;

	std::array<Hex4digit,TOTAL_MEMORY_SPACES> registers;
	Hex4digit input;
	Hex4digit output;
	std::vector<MemoryHistorySpace> pcHistory;
	std::vector<std::array<Hex4digit, TOTAL_MEMORY_SPACES>> memoryStateHistory;

	static ProgramState getInstance() {
		if (emulationState == nullptr) {
			emulationState = new ProgramState();
		}
		return *emulationState;
	}

	bool initializeState(std::array<Hex4digit,256> code) {
		bool result = false;

		if ((!code.empty()) && (code.size() > 0)) {
			MemoryHistorySpace pc = MemoryHistorySpace();
			pc.memoryLocation = 0;
			pc.value.setValue(code[0].getHexChars());
			pcHistory.push_back(pc);

			fillOutMemory(code);
			memoryStateHistory.push_back(code);

			result = true;
		}

		return result;
	}
	//TODO Finish this
	void clearProgramState() {
		for (int i = 0; i < REGISTER_COUNT; i++) {
			registers[i].setValue(0);
		}

		for (auto& h : memoryStateHistory) {
			h.clear();
		}
		memoryStateHistory.clear();
		pcHistory.clear();
	}

	std::string printableProgramState();

	Hex4digit getMemoryStateValue(int n);

private:
	constexpr static int REGISTER_COUNT = 16;

	static ProgramState* emulationState;

	void fillOutMemory(std::array<Hex4digit,256> code) {
		for (int i = code.size(); i < TOTAL_MEMORY_SPACES; i++) {
			code[i] = Hex4digit(0);
		}
	}

	ProgramState() {
		emulationState = nullptr;

		for (int i = 0; i < REGISTER_COUNT; i++) {
			registers[i] = (Hex4digit());
		}

		input = Hex4digit();
		output = Hex4digit();
		pcHistory = std::vector<MemoryHistorySpace>();
		memoryStateHistory = std::vector<std::array<Hex4digit, TOTAL_MEMORY_SPACES>>();
	}
};