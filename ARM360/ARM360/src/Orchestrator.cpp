// Orchestrator source file
// Autumn Clark
// 02-03-2023

#include "stdafx.h"
#include "Orchestrator.h"

// Private constructor to enforce Singleton pattern
Orchestrator::Orchestrator() : state(ProgramState::getInstance()), translator(), executor(), fileManager(FileManager::getInstance()) {
    resetError();
}

// Method that resets the error
void Orchestrator::resetError() {
    error = "Orchestrator: No Error.";
}


// Public methods

// Method that gets the Singleton instance of Orchestrator
// @return Orchestrator : The only instance of Orchestrator
Orchestrator Orchestrator::getInstance() {
        if (instancePtr == nullptr) {
            instancePtr = new Orchestrator();
        }
        return *instancePtr;
}

// Method that gets the current error
// @return string : The current error message
std::string Orchestrator::getError() {
    return error;
}

// Method that 
// @return bool : True if the operation succeeded correctly; false otherwise
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

// Method that clears the program currently loaded
void Orchestrator::clearProgram() {
    executor.clearState();
}

// Method that gets the ProgramState
// @return ProgramState : the current ProgramState
ProgramState Orchestrator::getProgramState() {
    return state;
}

// Method that initializes an input
// @param input : an array of char
void Orchestrator::sendInput(char input[]) {
    state.input.setValue(input);
}

// Method that gets the result of the input
// @return vector<char> : The output of the input
std::vector<char> Orchestrator::getOutput() {
    return state.output.getHexChars();
}

// Method that loads a file and translates it
// @param path : A string containing the path to a file
// @return bool : True if the file was translated successfully; false otherwise
bool Orchestrator::translateAndLoad(std::string path) {
    resetError();
    boolean result;

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
    std::array<Hex4digit, 256> temp;
    std::copy(begin(code), end(code), temp);

    // Set up the emulator
    state.initializeState(temp);
    executor.setProgramState(state);
    translator.clearFile();

    return result;
}

// Method that converts a number to hexadecimal chars
// @param number : The number to be converted as a short
// @return vector<char> : A vector of hexidecimal chars
std::vector<char> Orchestrator::convertToHexChars(short number) {
    // Convert char array to vector, then return it
    std::array<char, 5> temp = HexadecimalConverter::decimalToHex(number);
    return std::vector<char>(temp.begin(), temp.end());
}

// Method that converts an array of char to ints
// @param number : An array of char
// @return int : The int representation of the input
int Orchestrator::convertToInt(char number[]) {
    return HexadecimalConverter::hexToDecimal(number);
}

// Method that loads a file
// @param path : A string containing the path to a file
// @return string : The file as a single string
std::string Orchestrator::loadFile(std::string path) {
    return fileManager.fileToString(path);
}