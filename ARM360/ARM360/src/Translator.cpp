// Translator source file
// Autumn Clark
// 01-26-2023

#include "stdafx.h"
#include "Translator.h"
#include <iostream>
#include <regex>

// Private constructor for Singleton
// @param armFile string : The path to the ARM file to be loaded
Translator::Translator(std::string armFile) {
    setTranslatable(this->translate(armFile));
}

// Private methods

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
        std::string parsedFile = *this->parseFile(this->getArmFile());
        // convert to hex code
        std::vector<Hex4digit> hex4dCode;
        if (parsedFile.size() > 0) {
            hex4dCode = this->convertToHex(&parsedFile);
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
        //return std::vector<std::string> (begin(*arr), end(*arr));
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
    //return std::vector<std::string>(begin(*anotherArray), end(*anotherArray));
    return arr;
}

// Method that removes comments from a string of the form @Comment@
// @param line : A string
// @return string : The string without any comments
std::string Translator::removeComments(std::string line) {
    std::string lineCopy = line;
    while (lineCopy.find("@") > -1) {

        int firstIndex = lineCopy.find_first_of('@');


        if (firstIndex == lineCopy.find_last_of('@')) {
            this->setExceptionMessage("Error occurred parsing comments. Please check your comments.");
            // System.out.println(this.getExceptionMessage());
            return "";
        }
        if (firstIndex + 1 < lineCopy.length()) {
            int endIndex = lineCopy.find('@', firstIndex + 1);

            if (endIndex + 1 <= lineCopy.length()) {
                lineCopy = lineCopy.replace(firstIndex - 1, endIndex - firstIndex + 1, "");
            }

        }
    }
    //System.out.println("Comments parsed out.");
    return lineCopy;
}

std::string* Translator::parseInLineHexNumbers(std::string file[]) {
    //Stop compile error until implementation is written
    std::string test[3]{};
    return test;
    // Working on conversion
    /*
    int end = (*file).length();
    int start = 256; // max memory space

    if (end < 256) {
        std::string memory[] = initializeArray();
        Pattern pattern = Pattern.compile("[0-9]{4}");

        for (int i = 0; i < (*file).length(); i++) {
            std::string newLine = file[i].trim();
            Matcher matcher = pattern.matcher(newLine);
            if (matcher.find() && newLine.length() > 5) {

                std::string labelAddress = "m" + Integer.toHexString(start - 1);
                std::string number = matcher.group();

                memory[start - 1] = number;

                // replace number with memory location
                newLine = newLine.replaceAll(number, labelAddress);

                start--;
            }

            // set line instruction
            memory[i] = newLine;

        }
        return memory;
    }

    return file;
    */
}

std::string Translator::readFile(std::string file) {
    //Stop compile error until implementation is written
    return "Test";
}

std::string* Translator::parseFile(std::string armFile) {
    //Stop compile error until implementation is written
    std::string test[3]{};
    return test;
    //return std::vector<std::string>(begin(test), end(test));
}

void Translator::parseOutLabels(std::string file[]) {

}

std::string* Translator::initializeArray() {
    //Stop compile error until implementation is written
    std::string test[3]{};
    return test;
    //return std::vector<std::string>(begin(test), end(test));
}

void Translator::setLabels(std::string lineOfCode, std::string parsedFile[], int lineIndex) {

}


std::vector<Hex4digit> Translator::initializeHexMemory() {
    //Stop compile error until implementation is written
    return std::vector<Hex4digit>();
}

// Public methods
// 
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
    if (instancePtr == nullptr) {
        instancePtr = new Translator(armFile); // initialize translator
    }
    return *instancePtr;
}

// Method that loads the path of an ARM file
// @param armFile : string that contains the path of the ARM file to be loaded
void Translator::setArmFile(std::string armFile) {
    this->armFile = armFile;
}

// Method that sets the translated codeof the Translator to the provided code
// @param translatedCode : vector<Hex4digit> containing translated code
void Translator::setTranslatedCode(std::vector<Hex4digit> translatedCode){
    this->translatedCode = translatedCode;
}

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

// Method that returns the translated code in the Translator
// @return vector<Hex4digit> : The translated code
std::vector<Hex4digit> Translator::getTranslatedCode() {
    return this->translatedCode;
}

// Method that clears the loaded file and all traces of it from the Translator
void Translator::clearFile() {
    setArmFile("");
    setLoaded(false);
    setTranslatedCode(*(new std::vector<Hex4digit>));
    std::cout << "Translator: Cleared all files.";
}

std::string Translator::getExceptionMessage() {
    //Stop compile error until implementation is written
    return "Test";
}

void Translator::setExceptionMessage(std::string exceptionMessage) {

}

std::vector<Hex4digit> Translator::convertToHex(std::string parsedFile[]) {
    // Working on conversion
    //Stop compile error until implementation is written
    return std::vector<Hex4digit>();
    /*
    this->parseOutLabels(parsedFile);
    InstructionParser instructionParser = InstructionParser::getInstance();
    parsedFile = this->parseInLineHexNumbers(parsedFile);

    std::vector<Hex4digit> translatedFile = initializeHexMemory();

    for (int lineIndex = 0; lineIndex < (*parsedFile).length(); lineIndex++) {
        std::string line = parsedFile[lineIndex];
        StringBuilder builder = new StringBuilder();

        // remove trailing space
        line = line.trim();

        if (line.isEmpty()) {
            continue;
        }


        // split on each instruction
        for (String elem : line.split(" ")) {
            String instruction = "";
            if (!elem.isEmpty()) {
                instruction = instructionParser.getParser().get(elem);
            }

            // adds instruction code to string if it is valid
            // else append unknown instruction
            builder.append(Objects.requireNonNullElse(instruction, elem));
        }

        //            System.out.println("Line: "+line);
        //


        if (builder.length() > 4 && builder.charAt(0) != '-') {
            String exception = String.format("Instruction memory overflow occurred at Line %d. \n" +
                "Line: %s", lineIndex, builder);
            this.setExceptionMessage(exception);
            this.clearFile();
            // System.out.println(this.getExceptionMessage());
            return null;
        }
        else {
            int stop = 5;
            // not negative instruction
            if (builder.charAt(0) != '-') {
                stop = 4;
            }

            // stop at 4 if non-negative
            while (builder.length() < stop) {
                builder.append("0");
            }

        }

        //            System.out.println("After checking Translated instruct:"+builder);


        String lineOfCode = builder.toString();
        // check if line matches hex format
        if (lineOfCode.matches("^[-0-9a-f]+$")) {
            // create hex digit
            Hex4digit hex = new Hex4digit();
            hex.setValue(lineOfCode);
            translatedFile.set(lineIndex, hex); // adds hex code to list
        }
        else {
            String exception = String.format("Line %d contains unknown instructions.", lineIndex);
            this.setExceptionMessage(exception);
            this.clearFile();
            // System.out.println(this.getExceptionMessage());
            return null;
        }


    }
    // System.out.println("File successfully converted to hex code.");

    return translatedFile;
    */
}