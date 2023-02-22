// InstructionSet source file
// Autumn Clark
// 02-21-2023

#include "stdafx.h"
#include "InstructionSet.h"

// Method that increments the program counter by one
// @param state : A program state object
void InstructionSet::incrementProgramCounter(ProgramState state) {
	state.registers[15].setValue((state.registers[15].getValue() + 1));
}

// Method that halts the program
// @param state : A program state object
void InstructionSet::halt(ProgramState state) {
    state.registers[15].setValue(-1);
}

// Method that loads a specified Hex4Digit value into the specified register 
// @param state : A program state object
// @param mem : The location of memory
// @param reg : The register to be loaded into
// @param index : An integer representation of the current index
void InstructionSet::load(ProgramState state, int mem, char reg, int index) {
    Hex4digit value = state.memoryStateHistory[(index)][(mem)];
    state.registers[Hex4digit::hexValue(reg)].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that

    incrementProgramCounter(state);
}

// Method that stores a specified Hex4Digit value into the specified register 
// @param state : A program state object
// @param mem : The location of memory
// @param reg : The register to be loaded into
// @param index : An integer representation of the current index
void InstructionSet::store(ProgramState state, int mem, char reg, int index) {
    Hex4digit value = state.registers[Hex4digit::hexValue(reg)];
    state.memoryStateHistory[index][mem].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

// Method that adds the values of two registers together and stores the result in a third register 
// @param state : A program state object
// @param reg1 : The register containing the first value
// @param reg2 : The register containing the second value
// @param reg3 : The register to store the result in
void InstructionSet::add(ProgramState state, char reg1, char reg2, char reg3) {
    int result = (state.registers[Hex4digit::hexValue(reg1)].getValue() + state.registers[Hex4digit::hexValue(reg2)].getValue());
    state.registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}

// Method that subtracts the values of two registers together and stores the result in a third register 
// @param state : A program state object
// @param reg1 : The register containing the first value
// @param reg2 : The register containing the second value
// @param reg3 : The register to store the result in
void InstructionSet::subt(ProgramState state, char reg1, char reg2, char reg3) {
    int result = (state.registers[Hex4digit::hexValue(reg1)].getValue() - state.registers[Hex4digit::hexValue(reg2)].getValue());
    state.registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}

// Method that multiplies the values of two registers together and stores the result in a third register 
// @param state : A program state object
// @param reg1 : The register containing the first value
// @param reg2 : The register containing the second value
// @param reg3 : The register to store the result in
void InstructionSet::mult(ProgramState state, char reg1, char reg2, char reg3) {
    int result = (state.registers[Hex4digit::hexValue(reg1)].getValue() * state.registers[Hex4digit::hexValue(reg2)].getValue());
    state.registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}

// Method that divides the values of two registers together and stores the result in a third register 
// @param state : A program state object
// @param reg1 : The register containing the first value
// @param reg2 : The register containing the second value
// @param reg3 : The register to store the result in
void InstructionSet::intDivide(ProgramState state, char reg1, char reg2, char reg3) {
    int result = (state.registers[Hex4digit::hexValue(reg1)].getValue() / state.registers[Hex4digit::hexValue(reg2)].getValue());
    state.registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}

// Method that loads the contents of the tempory storage, form storeIndirect
// @param state : A program state object
// @param mem : The location of memory
// @param reg : The register to be loaded into
// @param index : An integer representation of the current index
void InstructionSet::loadIndirect(ProgramState state, int mem, char reg, int index) {
    Hex4digit address = state.memoryStateHistory[index][mem];
    Hex4digit value = state.memoryStateHistory[index][address.getValue()];
    state.registers[Hex4digit::hexValue(reg)].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

// Method that stores a specified Hex4Digit value into a tempory location, for retrival later
// @param state : A program state object
// @param mem : The location of memory
// @param reg : The register to be loaded from
// @param index : An integer representation of the current index
void InstructionSet::storeIndirect(ProgramState state, int mem, char reg, int index) {
    Hex4digit value = state.registers[Hex4digit::hexValue(reg)];
    Hex4digit address = state.memoryStateHistory[index][mem];
    state.memoryStateHistory[index][address.getValue()].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

// Method that changes the program counter to the specified memory index
// @param state : A program state object
// @param mem : The location of memory to point to
void InstructionSet::branch(ProgramState state, int mem) {
    state.registers[15].setValue(mem);
}

// Method that changes the program counter to the specified memory index if the specified register is zero
// @param state : A program state object
// @param mem : The location of memory to point to
// @param reg : The register to check
void InstructionSet::branchZero(ProgramState state, char reg, int mem) {
    if (state.registers[Hex4digit::hexValue(reg)].getValue() == 0) {
        state.registers[15].setValue(mem);
    }
    else {
        incrementProgramCounter(state);
    }
}

// Method that changes the program counter to the specified memory index if the specified register is negative
// @param state : A program state object
// @param mem : The location of memory to point to
// @param reg : The register to check
void InstructionSet::branchNeg(ProgramState state, char reg, int mem) {
    if (state.registers[Hex4digit::hexValue(reg)].getValue() < 0) {
        state.registers[15].setValue(mem);
    }
    else {
        incrementProgramCounter(state);
    }
}

// Method that changes the program counter to the specified memory index if the specified register is positive
// @param state : A program state object
// @param mem : The location of memory to point to
// @param reg : The register to check
void InstructionSet::branchPos(ProgramState state, char reg, int mem) {
    if (state.registers[Hex4digit::hexValue(reg)].getValue() >= 0) {
        state.registers[15].setValue(mem);
    }
    else {
        incrementProgramCounter(state);
    }
}

// Method that assigns the value of the input on program state to the specified register
// @param state : A program state object
// @param reg : The register to be read from
void InstructionSet::readInt(ProgramState state, char reg) {
    state.registers[Hex4digit::hexValue(reg)].setValue(state.input.getValue());
    incrementProgramCounter(state);
}

// Method that writes the contents of the specified register to the program state's outout
// @param state : A program state object
// @param reg : The register to be read from
void InstructionSet::writeInt(ProgramState state, char reg) {
    state.output.setValue(&(state.registers[Hex4digit::hexValue(reg)].getHexChars())[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

// Method that skips to the next instruction
// @param state : A program state object
void InstructionSet::skip(ProgramState state) {
    incrementProgramCounter(state);
}