// InstructionSet source file
// Autumn Clark
// 02-21-2023

#include "stdafx.h"
#include "InstructionSet.h"

/// <summary>
/// Method that increments the program counter by one
/// </summary>
/// <param name="state">A program state object</param>
void InstructionSet::incrementProgramCounter(ProgramState* state) {
	state->registers[15].setValue((state->registers[15].getValue() + 1));
}

/// <summary>
/// Method that halts the program
/// </summary>
/// <param name="state">A program state object</param>
void InstructionSet::halt(ProgramState* state) {
    state->registers[15].setValue(-1);
}

/// <summary>
/// Method that loads a specified Hex4Digit value into the specified register 
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="mem">The location of memory</param>
/// <param name="reg">The register to be loaded into</param>
/// <param name="index">An integer representation of the current index</param>
void InstructionSet::load(ProgramState* state, int mem, char reg, int index) {
    Hex4digit value = state->memoryStateHistory[(index)][(mem)];
    state->registers[Hex4digit::hexValue(reg)].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that

    incrementProgramCounter(state);
}

/// <summary>
/// Method that stores a specified Hex4Digit value into the specified register  
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="mem">The location of memory</param>
/// <param name="reg">The register to be loaded into</param>
/// <param name="index">An integer representation of the current index</param>
void InstructionSet::store(ProgramState* state, int mem, char reg, int index) {
    Hex4digit value = state->registers[Hex4digit::hexValue(reg)];
    state->memoryStateHistory[index][mem].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

/// <summary>
/// Method that adds the values of two registers together and stores the result in a third register 
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg1">The register containing the first value</param>
/// <param name="reg2">The register containing the second value</param>
/// <param name="reg3">The register to store the result in</param>
void InstructionSet::add(ProgramState* state, char reg1, char reg2, char reg3) {
    int result = (state->registers[Hex4digit::hexValue(reg1)].getValue() + state->registers[Hex4digit::hexValue(reg2)].getValue());
    state->registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}
 
/// <summary>
/// Method that subtracts the values of two registers together and stores the result in a third register
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg1">The register containing the first value</param>
/// <param name="reg2">The register containing the second value</param>
/// <param name="reg3">The register to store the result in</param>
void InstructionSet::subt(ProgramState* state, char reg1, char reg2, char reg3) {
    int result = (state->registers[Hex4digit::hexValue(reg1)].getValue() - state->registers[Hex4digit::hexValue(reg2)].getValue());
    state->registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}
 
/// <summary>
/// Method that multiplies the values of two registers together and stores the result in a third register
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg1">The register containing the first value</param>
/// <param name="reg2">The register containing the second value</param>
/// <param name="reg3">The register to store the result in</param>
void InstructionSet::mult(ProgramState* state, char reg1, char reg2, char reg3) {
    int result = (state->registers[Hex4digit::hexValue(reg1)].getValue() * state->registers[Hex4digit::hexValue(reg2)].getValue());
    state->registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}
 
/// <summary>
/// Method that divides the values of two registers together and stores the result in a third register
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg1">The register containing the first value</param>
/// <param name="reg2">The register containing the second value</param>
/// <param name="reg3">The register to store the result in</param>
void InstructionSet::intDivide(ProgramState* state, char reg1, char reg2, char reg3) {
    int result = (state->registers[Hex4digit::hexValue(reg1)].getValue() / state->registers[Hex4digit::hexValue(reg2)].getValue());
    state->registers[Hex4digit::hexValue(reg3)].setValue(result);
    incrementProgramCounter(state);
}

/// <summary>
/// Method that loads the contents of the tempory storage, form storeIndirect  
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="mem">The location of memory</param>
/// <param name="reg">The register to be loaded into</param>
/// <param name="index">An integer representation of the current index</param>
void InstructionSet::loadIndirect(ProgramState* state, int mem, char reg, int index) {
    Hex4digit address = state->memoryStateHistory[index][mem];
    Hex4digit value = state->memoryStateHistory[index][address.getValue()];
    state->registers[Hex4digit::hexValue(reg)].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

/// <summary>
/// Method that stores a specified Hex4Digit value into a tempory location, for retrival later 
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="mem">The location of memory</param>
/// <param name="reg">The register to be loaded into</param>
/// <param name="index">An integer representation of the current index</param>
void InstructionSet::storeIndirect(ProgramState* state, int mem, char reg, int index) {
    Hex4digit value = state->registers[Hex4digit::hexValue(reg)];
    Hex4digit address = state->memoryStateHistory[index][mem];
    state->memoryStateHistory[index][address.getValue()].setValue(&value.getHexChars()[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

/// <summary>
/// Method that changes the program counter to the specified memory index
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="mem">The location of memory to point to</param>
void InstructionSet::branch(ProgramState* state, int mem) {
    state->registers[15].setValue(mem);
}

/// <summary>
/// Method that changes the program counter to the specified memory index if the specified register is zero
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg">The register to check</param>
/// <param name="mem">The location of memory to point to</param>
void InstructionSet::branchZero(ProgramState* state, char reg, int mem) {
    if (state->registers[Hex4digit::hexValue(reg)].getValue() == 0) {
        state->registers[15].setValue(mem);
    }
    else {
        incrementProgramCounter(state);
    }
}

/// <summary>
/// Method that changes the program counter to the specified memory index if the specified register is negative
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg">The register to check</param>
/// <param name="mem">The location of memory to point to</param>
void InstructionSet::branchNeg(ProgramState* state, char reg, int mem) {
    if (state->registers[Hex4digit::hexValue(reg)].getValue() < 0) {
        state->registers[15].setValue(mem);
    }
    else {
        incrementProgramCounter(state);
    }
}

/// <summary>
/// Method that changes the program counter to the specified memory index if the specified register is positive
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg">The register to check</param>
/// <param name="mem">The location of memory to point to</param>
void InstructionSet::branchPos(ProgramState* state, char reg, int mem) {
    if (state->registers[Hex4digit::hexValue(reg)].getValue() >= 0) {
        state->registers[15].setValue(mem);
    }
    else {
        incrementProgramCounter(state);
    }
}

/// <summary>
/// Method that assigns the value of the input on program state to the specified register
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg">The register to be read from</param>
void InstructionSet::readInt(ProgramState* state, char reg) {
    state->registers[Hex4digit::hexValue(reg)].setValue(state->input.getValue());
    incrementProgramCounter(state);
}

/// <summary>
/// Method that writes the contents of the specified register to the program state's outout
/// </summary>
/// <param name="state">A program state object</param>
/// <param name="reg">The register to be read from</param>
void InstructionSet::writeInt(ProgramState* state, char reg) {
    state->output.setValue(&(state->registers[Hex4digit::hexValue(reg)].getHexChars())[0]); // Get pointer vector is using and pass that
    incrementProgramCounter(state);
}

/// <summary>
/// Method that skips to the next instruction
/// </summary>
/// <param name="state">A program state object</param>
void InstructionSet::skip(ProgramState* state) {
    incrementProgramCounter(state);
}