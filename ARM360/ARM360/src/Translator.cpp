// Translator source file
// Autumn Clark
// 01-26-2023

#include "stdafx.h"
#include "Translator.h"

// Instance Variables

Translator* Translator::instancePtr;

/// <summary>
/// Private constructor for Singleton
/// </summary>
/// <param name="armFile">The path to the ARM file to be loaded</param>
Translator::Translator(std::string armFile) : fileMan(*(FileManager::getInstance())) {
    setTranslatable(this->translate(armFile));
}

// Private methods

/// <summary>
/// Method that reads the file, parses it, converts it to hexadecimal, and sets the translated code to the hexadecimal code
/// </summary>
/// <param name="armFile">The path to the ARM file to be translated</param>
/// <returns>true if the file was translated successfully, false otherwise</returns>
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

/// <summary>
/// Method that updates the bool loaded
/// </summary>
/// <param name="loaded">bool value to be set as the value for loaded</param>
void Translator::setLoaded(bool loaded) {
    this->loaded = loaded;
}

/// <summary>
/// Method that returns a new array sized one less than inputted, without the specified index
/// </summary>
/// <param name="arr">string[] the array to copy</param>
/// <param name="index">int the index of the element to remove from the array</param>
/// <returns>A string* to the string[] without the nth element</returns>
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

/// <summary>
/// Method that removes comments from a string of the form @Comment@
/// </summary>
/// <param name="line">A string</param>
/// <returns>The string without any comments</returns>
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

/// <summary>
/// Method that parses out hex numbers from a file
/// </summary>
/// <param name="file">A string[] representation of the file to be parsed from</param>
/// <returns>A string* to the string[] of all hex numbers</returns>
std::string* Translator::parseInLineHexNumbers(std::string file[]) {    
    int end = (*file).length();
    int start = 256; // max memory space

    if (end < 256) {
        std::string memory[256] = { "" };
        std::regex pattern("[0-9]{4}");

        for (int i = 0; i < (*file).length(); i++) {
            std::string newLine = file[i];
            Translator::trim(newLine);
            std::smatch m;
            std::regex_search(newLine, m, pattern);
            if (m.length() && newLine.length() > 5) {

                std::string labelAddress = "m" + Translator::convertToHexString(start - 1);
                std::string number = m[0];

                memory[start - 1] = number;

                // replace number with memory location
                newLine = std::regex_replace(newLine, std::regex(number), labelAddress);

                start--;
            }

            // set line instruction
            memory[i] = newLine;

        }
        return memory;
    }
    return file;
}

/// <summary>
/// Method that reads the specified file in
/// </summary>
/// <param name="file">The path of the file to be read in</param>
/// <returns>A string containing the text of the file</returns>
std::string Translator::readFile(std::string file) {
    return fileMan.readFile(file);
}

/// <summary>
/// Method that parses a file of "0x" and "#", then splits it on ";"
/// </summary>
/// <param name="armFile">The file to be parsed</param>
/// <returns>A string* to the string[] of the file split of ";"</returns>
std::string* Translator::parseFile(std::string armFile) {
    std::string noComments = Translator::removeComments(armFile);
    noComments = std::regex_replace(noComments, std::regex("0x"), "");
    noComments = std::regex_replace(noComments, std::regex("#"), "");

    if (noComments.empty()) {
        return  nullptr;
    }
    char delimitter = ';';
    size_t start = 0;
    size_t end = noComments.find(delimitter);
    std::string array[256];
    int i = 0;
    while (end >= 0) {
        array[i] = noComments.substr(start, end);
        start = end + 1;
        end = noComments.find(delimitter);
        i++;
    }
    return array;
}

/// <summary>
/// Method that parses out labels from a file
/// </summary>
/// <param name="file">A string[] representation of a file</param>
void Translator::parseOutLabels(std::string file[]) {
    for (int i = 0; i < (*file).length(); i++) {
        std::string line = file[i];
        if (line.find(":") >= 0) {
            // replace all label occurrence
            this->setLabels(std::regex_replace(line, std::regex("\\s"), ""), file, i);
        }
    }
}


void Translator::setLabels(std::string lineOfCode, std::string parsedFile[], int lineIndex) {
    std::string lineArray[256];
    char delimitter = ':';
    size_t start = 0;
    size_t end = lineOfCode.find(delimitter);
    int i = 0;
    while (end >= 0) {
        lineArray[i] = lineOfCode.substr(start, end);
        start = end + 1;
        end = lineOfCode.find(delimitter);
        i++;
    }

    // checks if label is defined on one line
    if (lineOfCode[lineOfCode.length() - 1] == ':') { // Checks if last char of string is ':'
        parsedFile = removeTheElement(parsedFile, lineIndex);
    }
    else {
        parsedFile[lineIndex] = std::regex_replace(*parsedFile, std::regex(lineArray[0] + ":"), "");
    }

    std::string labelAddress;
    if (lineIndex < 10) {
        labelAddress = "0" + Translator::convertToHexString(lineIndex);
    }
    else {
        labelAddress = Translator::convertToHexString(lineIndex);
    }

    for (int i = 0; i < (*parsedFile).length(); i++) {
        parsedFile[i] = std::regex_replace(parsedFile[i], std::regex(lineArray[0]), labelAddress);
    }
}

/// <summary>
/// Method that creates a vector of size 256, filled with Hex4digit objects
/// </summary>
/// <returns>A vector representing the memory</returns>
std::vector<Hex4digit> Translator::initializeHexMemory() {
    std::vector<Hex4digit> memory(256, Hex4digit());

    return memory;
}

/// <summary>
/// Method that converts a decimal number to its hexadecimal representation
/// </summary>
/// <param name="number">The number to convert, in base 10</param>
/// <returns>The number in base 16</returns>
std::string Translator::convertToHexString(int number) {
    // Create an iostream to write to
    std::ostringstream ss;
    // Change output base to hex, write number to stream, then change output base back to decmial
    ss << std::hex << number << std::dec;
    // Return the string representation of the stream
    return ss.str();
}

// Three methods for triming strings - found at https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
// trim from start (in place)
inline void Translator::ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}
// trim from end (in place)
inline void Translator::rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}
// trim from both ends (in place)
inline void Translator::trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}
// End of methods for triming strings - found at https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring

// Public methods

/// <summary>
/// Method that indicates whether the loaded file was translatable or not
/// </summary>
/// <returns>true if the file was able to be translated, false otherwise</returns>
bool Translator::isTranslatable() {
    return this->isFileTranslatable;
}

/// <summary>
/// Method that updates the bool isFileTranalatable
/// </summary>
/// <param name="translatable">bool value to be set as the value for isFileTranslatable</param>
void Translator::setTranslatable(bool translatable) {
    this->isFileTranslatable = translatable;
}

/// <summary>
/// Method that gets returns a reference to the the Singleton instance of the Translator
/// </summary>
/// <returns>The Translator object</returns>
Translator* Translator::getInstance(std::string armFile) {
    if (instancePtr == nullptr) {
        instancePtr = new Translator(armFile); // initialize translator
    }
    else { // This updates the armFile if there is already a Translator instance. Otherwise, the armFile is never updated.
        instancePtr->translate(armFile);
    }
    return instancePtr;
}

/// <summary>
/// Method that loads the path of an ARM file
/// </summary>
/// <param name="armFile">string that contains the path of the ARM file to be loaded</param>
void Translator::setArmFile(std::string armFile) {
    this->armFile = armFile;
}

/// <summary>
/// Method that sets the translated codeof the Translator to the provided code
/// </summary>
/// <param name="translatedCode">vector containing translated code</param>
void Translator::setTranslatedCode(std::vector<Hex4digit> translatedCode){
    this->translatedCode = translatedCode;
}

/// <summary>
/// Method that returns the path of the ARM file currently loaded
/// </summary>
/// <returns>The path of the loaded ARM file</returns>
std::string Translator::getArmFile() {
    return this->armFile;
}

/// <summary>
/// Method that indicates whether the Translator is loaded with a file or not
/// </summary>
/// <returns>true if the Translator has a file loaded, false otherwise</returns>
bool Translator::isLoaded() {
    return this->loaded;
}

/// <summary>
/// Method that returns the translated code in the Translator
/// </summary>
/// <returns>The translated code</returns>
std::vector<Hex4digit> Translator::getTranslatedCode() {
    return this->translatedCode;
}


/// <summary>
/// // Method that clears the loaded file and all traces of it from the Translator
/// </summary>
void Translator::clearFile() {
    setArmFile("");
    setLoaded(false);
    setTranslatedCode(*(new std::vector<Hex4digit>));
    std::cout << "Translator: Cleared all files.";
}

/// <summary>
/// Method that gets the current exception message
/// </summary>
/// <returns>The current exception message</returns>
std::string Translator::getExceptionMessage() {
    return this->exceptionMessage;
}

// Method that updates the exception message
// @param exceptionMessage : The message to be set

/// <summary>
/// Method that updates the exception message
/// </summary>
/// <param name="exceptionMessage">The message to be set</param>
void Translator::setExceptionMessage(std::string exceptionMessage) {
    this->exceptionMessage = exceptionMessage;
}

/// <summary>
/// Method that converts a string array into a vector of Hex4digit objects
/// </summary>
/// <param name="parsedFile">A string[] representation of the file</param>
/// <returns>A vector of converted Hex4digit objects</returns>
std::vector<Hex4digit> Translator::convertToHex(std::string parsedFile[]) {
    this->parseOutLabels(parsedFile);
    InstructionParser* instructionParser = InstructionParser::getInstance();
    parsedFile = this->parseInLineHexNumbers(parsedFile);

    std::vector<Hex4digit> translatedFile = initializeHexMemory();

    for (int lineIndex = 0; lineIndex < (*parsedFile).length(); lineIndex++) {
        std::string line = parsedFile[lineIndex];
        std::string builder;
        //StringBuilder builder = new StringBuilder();

        // remove trailing space
        Translator::trim(line);

        if (line.empty()) {
            continue;
        }


        // split on each instruction
        std::string instructions[256];
        char delimitter = ' ';
        size_t start = 0;
        size_t end = line.find(delimitter);
        int i = 0;
        while (end >= 0) {
            instructions[i] = line.substr(start, end);
            start = end + 1;
            end = line.find(delimitter);
            i++;
        }

        for (std::string elem : instructions) {
            std::string instruction = "";
            if (!elem.empty()) {
                instruction = instructionParser->getParser().at(elem);
            }

            // adds instruction code to string if it is valid
            // else append unknown instruction
            if (instruction != "") {
                builder.append(instruction);
            }
            else {
                builder.append(elem);
            }
        }

        //            System.out.println("Line: "+line);
        //


        if (builder.length() > 4 && builder[0] != '-') {
            std::string exception = "Instruction memory overflow occurred at Line " + std::to_string(lineIndex) + ". \n" +
                "Line: " + builder;
            this->setExceptionMessage(exception);
            this->clearFile();
            std::cout << this->getExceptionMessage() << std::endl;
            throw std::runtime_error("Memory overflow encountered.");
        }
        else {
            int stop = 5;
            // not negative instruction
            if (builder[0] != '-') {
                stop = 4;
            }

            // stop at 4 if non-negative
            while (builder.length() < stop) {
                builder.append("0");
            }

        }

        //            System.out.println("After checking Translated instruct:"+builder);


        std::string lineOfCode = builder;
        // check if line matches hex format
        if (std::regex_match(lineOfCode, std::regex("^[-0-9a-f]+$"))) {
            // create hex digit
            Hex4digit hex;
            hex.setValue(lineOfCode);
            translatedFile[lineIndex] = hex; // adds hex code to list
        }
        else {
            std::string exception = "Line " + std::to_string(lineIndex) + " contains unknown instructions.";
            this->setExceptionMessage(exception);
            this->clearFile();
            std::cout << this->getExceptionMessage() << std::endl;
            throw std::runtime_error("Unknown instructions found.");
        }

    }
    return translatedFile;
}