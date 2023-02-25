// Translator header file
// Autumn Clark
// 01-26-2023

#pragma once
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <locale>
#include "FileManager/FileManager.h"
#include "Hex4digit.h"
#include "HexadecimalConvertor.h"
#include "MemoryHistorySpace.h"
#include "MockDataGenerator.h"
#include "ProgramState/ProgramState.h"
#include "InstructionParser.h"

class Translator {
private:
    // Instance variables
    std::string armFile;
    bool loaded;
    //Vectors can not be null, as null is different in C++; check if vector is empty, instead of checking for null
    std::vector<Hex4digit> translatedCode;
    FileManager fileMan;
    static Translator* instancePtr;
    std::string exceptionMessage = "No Error";
    bool isFileTranslatable = false;
    
    // Private constructor for SIngleton
    Translator(std::string armFile);
    Translator(const Translator&); // Used for dereferencing the instance pointer -- might be an issue that this is needed

    // Private methods
    bool translate(std::string armFile);
    void setLoaded(bool loaded);
    std::string* removeTheElement(std::string arr[], int index);
    std::string removeComments(std::string line);
    std::string* parseInLineHexNumbers(std::string file[]);
    std::string readFile(std::string file);
    std::string* parseFile(std::string armFile);
    void parseOutLabels(std::string file[]);
    void setLabels(std::string lineOfCode, std::string parsedFile[], int lineIndex);
    std::vector<Hex4digit> initializeHexMemory();
    std::string convertToHexString(int number);

    // Three methods for triming strings - found at https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
    static inline void ltrim(std::string& s);
    static inline void rtrim(std::string& s);
    static inline void trim(std::string& s);
    // End of methods for triming strings - found at https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring

public:
    // Public methods
    bool isTranslatable();
    void setTranslatable(bool translatable);
    static Translator getInstance(std::string armFile);
    void setArmFile(std::string armFile);
    void setTranslatedCode(std::vector<Hex4digit> translatedCode);
    std::string getArmFile();
    bool isLoaded();
    std::vector<Hex4digit> getTranslatedCode();
    void clearFile();
    std::string getExceptionMessage();
    void setExceptionMessage(std::string exceptionMessage);
    std::vector<Hex4digit> convertToHex(std::string parsedFile[]);

};
