// Orchestrator source file
// Autumn Clark
// 02-03-2023

#include "stdafx.h"
#include "Orchestrator.h"

// Instance variables

Orchestrator* Orchestrator::instancePtr;

/// <summary>
/// Private constructor to enforce Singleton pattern
/// </summary>
Orchestrator::Orchestrator() : state(*(ProgramState::getInstance())), translator(), executor(), fileManager(*(FileManager::getInstance())) {
    resetError();
}

/// <summary>
/// Method that resets the error
/// </summary>
void Orchestrator::resetError() {
    error = "Orchestrator: No Error.";
}


// Public methods

/// <summary>
/// Method that gets the Singleton instance of Orchestrator
/// </summary>
/// <returns>The only instance of Orchestrator</returns>
Orchestrator* Orchestrator::getInstance() {
        if (instancePtr == nullptr) {
            instancePtr = new Orchestrator();
        }
        return instancePtr;
}

/// <summary>
/// Method that gets the current error
/// </summary>
/// <returns>The current error message</returns>
std::string Orchestrator::getError() {
    return error;
}

/// <summary>
/// Method that advances the executor to the next instruction, if it exists
/// </summary>
/// <returns>True if the operation succeeded correctly; false otherwise</returns>
bool Orchestrator::next() {
    resetError();
    bool result = executor.hasState();
    if (result == false) {
        error = "Executor" + executor.getLastExceptionMessage();
        return result;
    }

    result = executor.hasNext();
    if (result == false) {
        error = "Executor" + executor.getLastExceptionMessage();
        return result;
    }

    result = executor.next();
    if (result == false) {
        error = "Executor" + executor.getLastExceptionMessage();
    }
    return result;
}

/// <summary>
/// Method that clears the program currently loaded
/// </summary>
void Orchestrator::clearProgram() {
    executor.clearState();
}

/// <summary>
/// Method that gets the ProgramState
/// </summary>
/// <returns>the current ProgramState</returns>
ProgramState Orchestrator::getProgramState() {
    return state;
}

/// <summary>
/// Method that initializes an input
/// </summary>
/// <param name="input">an array of char</param>
void Orchestrator::sendInput(char input[]) {
    state.input.setValue(input);
}

/// <summary>
/// Method that gets the result of the input
/// </summary>
/// <returns>The output of the input</returns>
std::array<char,5> Orchestrator::getOutput() {
    return state.output.getHexChars();
}

/// <summary>
/// Method that loads a file and translates it
/// </summary>
/// <param name="path">A string containing the path to a file</param>
/// <returns>True if the file was translated successfully; false otherwise</returns>
bool Orchestrator::translateAndLoad(std::string path) {
    resetError();
    bool result;

    result = translator.loadFile(path);
    if (result == false) {
        error = "Translator" + translator.getLastExceptionMessage();
        return result;
    }

    result = translator.isTranslatable();

    if (result == false) {
        error = "Translator" + translator.getLastExceptionMessage();
    }

    state.clearProgramState();
    std::vector<Hex4digit> code = translator.translateToMachine();

    // Create a temporary array of a fixed size, copy the contents of code into it, then pass the array to ProgramState

    // Set up the emulator
    state.initializeState(code);
    executor.setProgramState(state);
    translator.clearFile();

    return result;
}

/// <summary>
/// Method that converts a number to hexadecimal chars
/// </summary>
/// <param name="number">The number to be converted as a short</param>
/// <returns>A vector of hexidecimal chars</returns>
std::vector<char> Orchestrator::convertToHexChars(short number) {
    // Convert char array to vector, then return it
    std::array<char, 5> temp = HexadecimalConverter::decimalToHex(number);
    return std::vector<char>(temp.begin(), temp.end());
}

/// <summary>
/// Method that converts an array of char to ints
/// </summary>
/// <param name="number">An array of char</param>
/// <returns>The int representation of the input</returns>
int Orchestrator::convertToInt(char number[]) {
    return HexadecimalConverter::hexToDecimal(number);
}

/// <summary>
/// Method that loads a file
/// </summary>
/// <param name="path">A string containing the path to a file</param>
/// <returns>The file as a single string</returns>
std::string Orchestrator::loadFile(std::string path) {
    return fileManager.readFile(path);
}