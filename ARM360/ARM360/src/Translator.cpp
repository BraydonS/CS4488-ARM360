// Translator source file
// Autumn Clark
// 01-26-2023

#include "Translator.h"
#include <iostream>

// Private constructor for SIngleton
// @param armFile string : The path to the ARM file to be loaded
Translator::Translator(std::string armFile) {
    setTranslatable(this->translate(armFile));
}

// Private methods
/*
// Method that reads the file, parses it, converts it to hexadecimal, and sets the translated code to the hexadecimal code
// @param armFile string : The path to the ARM file to be translated
// @return bool : true if the file was translated successfully, false otherwise
bool Translator::translate(std::string armFile) {
    this->setArmFile(this->readFile(armFile));
    // Check and set if file is read successfully
    this->setLoaded(this->getArmFile().length() > 0);

    // Translate if loaded
    if (this->isLoaded()) {
        // Parse Arm-file for hex conversion
        std::vector<std::string> parsedFile = this->parseFile(this->getArmFile());
        // convert to hex code
        std::vector<Hex4digit> hex4dCode;
        if (parsedFile.size() > 0) {
            hex4dCode = this->convertToHex(parsedFile);
        }


        // if lines don't exceed memory space
        if (hex4dCode.size() > 0 && hex4dCode.size() <= 256) {
            this->setTranslatedCode(hex4dCode);
            return this->getTranslatedCode().size() > 0;

        }
        else {
            this->setExceptionMessage("System Memory overflow, Lines exceed 256.");
            std::cout << this->getExceptionMessage();
            //System.out.println(this.getExceptionMessage());
            return false;
        }
    }
    return false;
}
*/

// Method that updates the bool loaded
// @param loaded : bool value to be set as the value for loaded
void Translator::setLoaded(bool loaded) {
    this->loaded = loaded;
}

// Method that returns a new array sized one less than inputted, without the specified index
// @param arr : string[] the array to copy
// @param index : int the index of the element to remove from the array
std::string* Translator::removeTheElement(std::string arr[], int index) {
    // If the array is empty or the index is not in array range
    // return the original array
    if (arr->size() == 0 || index < 0 || index >= arr->size()) {
        return arr;
    }

    // Create another array of size one less
    std::string* anotherArray = new std::string[arr->length() - 1]{};

    // Copy the elements except the index
    // from original array to the other array
    for (int i = 0, k = 0; i < arr->length(); i++) {

        // if the index is
        // the removal element index
        if (i == index) {
            continue;
        }

        // if the index is not
        // the removal element index
        anotherArray[k++] = arr[i];
    }

    // return the resultant array
    return anotherArray;
}

std::string Translator::removeComments(std::string line) {

}

std::string* Translator::parseInLineHexNumbers(std::string file[]) {

}

std::string Translator::readFile(std::string file) {

}

std::string* Translator::parseFile(std::string armFile) {

}

void Translator::parseOutLabels(std::string file[]) {

}

std::string* Translator::initializeArray() {

}

void Translator::setLabels(std::string lineOfCode, std::string parsedFile[], int lineIndex) {

}

/* 
//Can uncomment when Hex4digit has been defined
//std::vector<Hex4digit> Translator::initializeHexMemory() {

}
*/

// Public methods
// Method that indicates whether the loaded file was translatable or not
// @return bool : true if the file was able to be translated, false otherwise
bool Translator::isTranslatable() {
    return this->isFileTranslatable;
}

// Method that updates the bool isFileTranalatable
// @param translatable : bool value to be set as the value for isFileTranslatable
void Translator::setTranslatable(bool translatable) {
    this->isFileTranslatable = translatable;
}

// Method that gets returns a reference to the the Singleton instance of the Translator
// @return Translator : The Translator object
Translator Translator::getInstance(std::string armFile) {
    if (instancePtr == NULL) {
        instancePtr = new Translator(armFile); // initialize translator
    }
    else {
        (*instancePtr).translate(armFile); // if translate new arm file
    }
    return *instancePtr;
}

// Method that loads the path of an ARM file
// @param armFile : string that contains the path of the ARM file to be loaded
void Translator::setArmFile(std::string armFile) {
    this->armFile = armFile;
}

/*
//Can uncomment when Hex4digit has been defined

// Method that sets the translated codeof the Translator to the provided code
// @param translatedCode : vector<Hex4digit> containing translated code
//void Translator::setTranslatedCode(std::vector<Hex4digit> translatedCode){
    this->translatedCode = translatedCode;
}
*/

// Method that returns the path of the ARM file currently loaded
// @return string : The path of the loaded ARM file
std::string Translator::getArmFile() {
    return this->armFile;
}

// Method that indicates whether the Translator is loaded with a file or not
// @return bool : true if the Translator has a file loaded, false otherwise
bool Translator::isLoaded() {
    return this->loaded;
}

/*
//Can uncomment when Hex4digit has been defined
// Method that returns the translated code in the Translator
// @return vector<Hex4digit> : The translated code
//std::vector<Hex4digit> Translator::getTranslatedCode() {
    return this->translatedCode;
}
*/

// Method that clears the loaded file and all traces of it from the Translator
// -----has a part that needs to be unommented once Hex4digit has been defined-----
void Translator::clearFile() {
    setArmFile("");
    setLoaded(false);
    //setTranslatedCode(new std::vector<Hex4digit>);
    std::cout << "Translator: Cleared all files.";
}

std::string Translator::getExceptionMessage() {

}

void Translator::setExceptionMessage(std::string exceptionMessage) {

}

/*
* //Can uncomment when Hex4digit has been defined
//std::vector<Hex4digit> Translator::convertToHex(std::string* parsedFile[]) {

}
*/