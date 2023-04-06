// InstructionSet header file
// Autumn Clark
// 01-27-2023

#pragma once
#include <string>
#include "ProgramState/ProgramState.h"
#include "Hex4digit.h"

class InstructionSet {
public:
	// Public methods
	
	static void incrementProgramCounter(ProgramState* state);
	static void halt(ProgramState* state);
	static void load(ProgramState* state, int mem, char reg, int index);
	static void store(ProgramState* state, int mem, char reg, int index);
	static void add(ProgramState* state, char reg1, char reg2, char reg3);
	static void subt(ProgramState* state, char reg1, char reg2, char reg3);
	static void mult(ProgramState* state, char reg1, char reg2, char reg3);
	static void intDivide(ProgramState* state, char reg1, char reg2, char reg3);
	static void loadIndirect(ProgramState* state, int mem, char reg, int index);
	static void storeIndirect(ProgramState* state, int mem, char reg, int index);
	static void branch(ProgramState* state, int mem);
	static void branchZero(ProgramState* state, char reg, int mem);
	static void branchNeg(ProgramState* state, char reg, int mem);
	static void branchPos(ProgramState* state, char reg, int mem);
	static void readInt(ProgramState* state, char reg);
	static void writeInt(ProgramState* state, char reg);
	static void skip(ProgramState* state);
};
