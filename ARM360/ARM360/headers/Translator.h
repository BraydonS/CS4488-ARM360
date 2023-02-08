// Translator header file
// Autumn Clark
// 01-26-2023

#pragma once
#include <string>
#include <vector>
#include "FileManager/FileManager.h"
#include "Hex4digit.h"
#include "HexadecimalConvertor.h"
#include "MemoryHistorySpace.h"
#include "MockDataGenerator.h"
#include "ProgramState/ProgramState.h"

class Translator {
private:
    // Instance variables
    std::string armFile;
    bool loaded;
    //Vectors can not be null, as null is different in C++; check if vector is empty, instead of checking for null
    std::vector<Hex4digit> translatedCode;
    FileManager fileMan = FileManager::getInstance();
    static Translator* instancePtr;
    std::string exceptionMessage = "No Error";
    bool isFileTranslatable = false;
    
    // Private constructor for SIngleton
    Translator(std::string armFile);

    // Private methods
    bool translate(std::string armFile);
    void setLoaded(bool loaded);
    std::vector<std::string> removeTheElement(std::string arr[], int index);
    std::string removeComments(std::string line);
    std::vector<std::string> parseInLineHexNumbers(std::string file[]);
    std::string readFile(std::string file);
    std::vector<std::string> parseFile(std::string armFile);
    void parseOutLabels(std::string file[]);
    std::vector<std::string> initializeArray();
    void setLabels(std::string lineOfCode, std::string parsedFile[], int lineIndex);
    std::vector<Hex4digit> initializeHexMemory();

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
