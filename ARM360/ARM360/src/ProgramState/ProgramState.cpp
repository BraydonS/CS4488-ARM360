#include "stdafx.h"
#include "ProgramState/programstate.h"


/// <summary>
/// The ProgramState singleton is a data class operated on by the executor, which stores the machine state in a vector of state arrays
/// </summary>
/// <version>
/// 0.1
/// </version>
/// <author>
/// Traae Bloxham, transpiled and updated by Braydon Spaulding
/// </author>

// Instance Variables

ProgramState* ProgramState::instance;

// Public Methods

/// <summary>
/// Memory size is currently static, could be potentially be passed into constructor in future
/// </summary>

ProgramState* ProgramState::getInstance() {
	if (instance == nullptr) {
		ProgramState::instance = new ProgramState();
	}
	return instance;
}

/// <summary>
/// Initializes the ProgramState using provided instructions
/// </summary>
/// <param name="code">An array of Hex4digits composed of user instuctions</param>
/// <returns>If the instructions were successfully initialized</returns>

bool ProgramState::initializeState(std::vector<Hex4digit> instructions) {
	bool result = false;

	if (instructions.size() > 0) {
		MemoryHistorySpace pc = MemoryHistorySpace();
		pc.setMemoryLocation(0);
		//TODO this is probably a bit of a hack, might fix
		pc.getValue().setValue(&instructions[0].getHexChars()[0]);
		pcHistory.push_back(pc);

		memoryStateHistory.push_back(instructions);

		result = true;
	}

	return result;
}

void ProgramState::clearProgramState() {
	for (int i = 0; i < REGISTER_COUNT; i++) {
		registers[i].setValue(0);
	}

	memoryStateHistory.clear();
	pcHistory.clear();
}

/// <summary>
/// Creates a summary of the current program state
/// </summary>
/// <returns>The state summary as a string</returns>
std::string ProgramState::printableProgramState() {
	std::stringstream stateSummary;
	stateSummary << "Input: " << input.getString() << "\n";
	stateSummary << "Output: " << output.getString() << "\n";
	stateSummary << "PC: " << registers.back().getString() << "\n";

	if (!registers.empty()) {
		stateSummary << "PC: " << registers.back().getString() << "\n";
	}

	stateSummary << "Registers: ";
	for (int i = 0; i < registers.size(); i++) {
		stateSummary << registers[i].getString() << ", ";
	}
		
	stateSummary << "\n\n";

	stateSummary << "Next: \n";
	
	if (!memoryStateHistory.empty()) {
		std::vector<Hex4digit> lastState = memoryStateHistory.back();
		int numZeroHexDigits = 0;
		bool seenZeroValue = false;

		// This loop appends information about the next state to the report, ommiting zero blocks for readability
		for (int i = 0; i < lastState.size(); i++) {
			Hex4digit nextStateHex = lastState[i];
			if (nextStateHex.getValue() == 0) {
				numZeroHexDigits++;
				if (!seenZeroValue) {
					stateSummary <<"\nZero block starts at: " << i << "\n";
					seenZeroValue = true;
				}
				continue;
			}
			else if (seenZeroValue) {
				stateSummary << "\nZero block ends at: " << i-1 << "\n";
				seenZeroValue = false;
			}

			stateSummary << nextStateHex.getString() << " ";
		}
	}

	return stateSummary.str();
}

/// <summary>
/// 
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
Hex4digit ProgramState::getMemoryStateValue(int n) {
	return memoryStateHistory[0][n];
}

//Private Methods

/// <summary>
/// Fills out the remaining unused space of a user's instructions with zeroes 
/// </summary>
/// <param name="instructions">An array of Hex4digit instructions</param>
void ProgramState::fillOutMemory(std::vector<Hex4digit> instructions) {
	for (int i = instructions.size(); i < TOTAL_MEMORY_SPACES; i++) {
		instructions[i] = Hex4digit(0);
	}
}

ProgramState::ProgramState() :input(Hex4digit()), output(Hex4digit()), 
pcHistory(std::vector<MemoryHistorySpace>()), memoryStateHistory(std::vector<std::vector<Hex4digit>>(256)),registers(std::vector<Hex4digit>(REGISTER_COUNT)) {
}