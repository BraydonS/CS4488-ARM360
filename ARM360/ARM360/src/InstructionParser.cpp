// InstructionParser source file
// Autumn Clark
// 02-21-2023

#include "stdafx.h"
#include "InstructionParser.h"

// Private methods

/// <summary>
/// Private constructor to enforce Singleton pattern
/// </summary>
InstructionParser::InstructionParser() {
    loadInstructions();
    loadRegisters();
    loadMemory();
}

/// <summary>
/// Method that loads instructions into the InstructionParser
/// </summary>
void InstructionParser::loadInstructions() {
    this->parser.insert("hlt", "0");
    this->parser.insert("ld", "1");
    this->parser.insert("st", "2");
    this->parser.insert("add", "3");
    this->parser.insert("sub", "4");
    this->parser.insert("mul", "5");
    this->parser.insert("div", "6");
    this->parser.insert("ldi", "7");
    this->parser.insert("sti", "8");
    this->parser.insert("br", "9");
    this->parser.insert("brz", "a");
    this->parser.insert("brn", "b");
    this->parser.insert("brp", "c");
    this->parser.insert("rd", "d");
    this->parser.insert("wr", "e");
    this->parser.insert("ldc", "f");
    this->parser.insert("s", "f000");
}

/// <summary>
/// Method that loads the registers into the InstructionParser
/// </summary>
void InstructionParser::loadRegisters() {
    for (int i = 0; i < 16; i++) {

        // loads quick notation into map
        std::string hexI = convertToHexString(i);
        this->parser.insert("r" + hexI, hexI);

        // loads hex address notation to map
        // this.parser.put("r0x"+hexI, hexI);
    }
    // load special register address
    this->parser.insert(std::string("fp"), convertToHexString(11));
    this->parser.insert(std::string("ip"), convertToHexString(12));
    this->parser.insert(std::string("sp"), convertToHexString(13));
    this->parser.insert(std::string("lr"), convertToHexString(14));
    this->parser.insert(std::string("pc"), convertToHexString(15));
}

/// <summary>
/// Method that loads the memory addresses into the InstructionParser
/// </summary>
void InstructionParser::loadMemory() {
    for (int i = 0; i < 16; i++) {

        for (int j = 0; j < 16; j++) {

            std::string hexI = convertToHexString(i);
            std::string hexJ = convertToHexString(j);

            // loads short address notation to map
            this->parser.insert("m" + hexI + hexJ, hexI + hexJ);

            // loads hex address notation to map
            // this.parser.put("m0x"+hexI+ hexJ, hexI+ hexJ);

        }
    }
}

/// <summary>
/// Method that converts a decimal number to its hexadecimal representation
/// </summary>
/// <param name="number">The number to convert, in base 10</param>
/// <returns>The number in base 16</returns>
std::string convertToHexString(int number) {
    // Create an iostream to write to
    std::ostringstream ss;
    // Change output base to hex, write number to stream, then change output base back to decmial
    ss << std::hex << number << std::dec;
    // Return the string representation of the stream
    return ss.str();
}

// Public methods

/// <summary>
/// Method that gets the Singleton instance of InstructionParser
/// </summary>
/// <returns>The only instance of InstructionParser</returns>
InstructionParser InstructionParser::getInstance() {
    if (instancePtr == nullptr) {
        instancePtr = new InstructionParser();
    }
    return *instancePtr;
}

/// <summary>
/// Method that gets the parser
/// </summary>
/// <returns>The InstructionParser's parser</returns>
std::unordered_map<std::string, std::string> InstructionParser::getParser() {
    return this->parser;
}