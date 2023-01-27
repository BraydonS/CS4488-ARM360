// Translator header file
// Autumn Clark
// 01-26-2023

#pragma once
#include <string>
#include <vector>
//#include "FileManager.h"
//#include "Hex4digit.h"

class Translator {
private:
    // Instance variables
    std::string armFile;
    bool loaded;
    //Vectors can not be null, as null is different in C++; check if vector is empty, instead of checking for null
    //std::vector<Hex4digit> translatedCode; //Can uncomment when Hex4digit has been defined
    //FileManager fileMan = FileManager.getInstance(); //Can uncomment when FileManager has been defined
    static Translator* instancePtr;
    std::string exceptionMessage = "No Error";
    bool isFileTranslatable = false;
    
    // Private constructor for SIngleton
    Translator(std::string armFile);

    // Private methods
    //bool translate(std::string armFile); // Uncomment when Hex4digit is defined
    void setLoaded(bool loaded);
    std::string* removeTheElement(std::string arr[], int index);
    std::string removeComments(std::string line);
    std::string* parseInLineHexNumbers(std::string file[]);
    std::string readFile(std::string file);
    std::string* parseFile(std::string armFile);
    void parseOutLabels(std::string file[]);
    std::string* initializeArray();
    void setLabels(std::string lineOfCode, std::string parsedFile[], int lineIndex);
    //std::vector<Hex4digit> initializeHexMemory(); //Can uncomment when Hex4digit has been defined

public:
    // Public methods
    bool isTranslatable();
    void setTranslatable(bool translatable);
    static Translator getInstance(std::string armFile);
    void setArmFile(std::string armFile);
    //void setTranslatedCode(std::vector<Hex4digit> translatedCode); //Can uncomment when Hex4digit has been defined
    std::string getArmFile();
    bool isLoaded();
    //std::vector<Hex4digit> getTranslatedCode();
    void clearFile();
    std::string getExceptionMessage();
    void setExceptionMessage(std::string exceptionMessage);
    //std::vector<Hex4digit> convertToHex(std::string parsedFile[]); //Can uncomment when Hex4digit has been defined

};
