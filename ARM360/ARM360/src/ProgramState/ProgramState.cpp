#include "stdafx.h"
#include "Hex4Digit.h"
#include "MemoryHistorySpace.h"
#include <string>
#include <sstream>

/// <summary>
/// The ProgramState singleton is a data class operated on by the executor, which stores the machine state in a vector of state arrays
/// </summary>
/// <version>
/// 0.1
/// </version>
/// <author>
/// Traae Bloxham, transpiled and updated by Braydon Spaulding
/// </author>

class ProgramState {

public:
	/// <summary>
	/// Memory size is currently static, could be potentially be passed into constructor in future
	/// </summary>
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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="code">An array of Hex4digits composed of user instuctions</param>
	/// <returns>If the instructions were successfully initialized</returns>

	bool initializeState(std::array<Hex4digit,256> instructions) {
		bool result = false;

		if ((!instructions.empty()) && (instructions.size() > 0)) {
			MemoryHistorySpace pc = MemoryHistorySpace();
			pc.memoryLocation = 0;
			pc.value.setValue(instructions[0].getHexChars());
			pcHistory.push_back(pc);

			fillOutMemory(instructions);
			memoryStateHistory.push_back(instructions);

			result = true;
		}

		return result;
	}

	void clearProgramState() {
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
	std::string printableProgramState() {
		std::stringstream stateSummary;
		stateSummary << "Input: " << input.getString() << "\n";
		stateSummary << "Output: " << output.getString() << "\n";
		stateSummary << "PC: " << registers.back().getString() << "\n";
		stateSummary << "Registers: ";

		for (int i = 0; i < registers.size(); i++) {
			stateSummary << registers[i].getString() << ", ";
		}
		
		stateSummary << "\n\n";

		stateSummary << "Next: \n";
		
		std::array<Hex4digit,256> lastState = memoryStateHistory.back();
		int numZeroHexDigits = 0;
		bool seenZeroValue = false;

		// This loop appends information about the next state to the report, ommiting zero blocks for readability
		for (int i = 0; lastState.size(); i++) {
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

		return stateSummary.str();
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="n"></param>
	/// <returns></returns>
	Hex4digit getMemoryStateValue(int n) {
		return memoryStateHistory[0][n];
	}

private:
	constexpr static int REGISTER_COUNT = 16;

	static ProgramState* emulationState;

	/// <summary>
	/// Fills out the remaining unused space of a user's instructions with zeroes 
	/// </summary>
	/// <param name="instructions">An array of Hex4digit instructions</param>
	void fillOutMemory(std::array<Hex4digit,256> instructions) {
		for (int i = instructions.size(); i < TOTAL_MEMORY_SPACES; i++) {
			instructions[i] = Hex4digit(0);
		}
	}

	ProgramState() {

		for (int i = 0; i < REGISTER_COUNT; i++) {
			registers[i] = (Hex4digit());
		}

		input = Hex4digit();
		output = Hex4digit();
		pcHistory = std::vector<MemoryHistorySpace>();
		memoryStateHistory = std::vector<std::array<Hex4digit, TOTAL_MEMORY_SPACES>>();
	}
};