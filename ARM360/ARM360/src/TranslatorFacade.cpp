// TranslatorFacade source file
// Autumn Clark
// 01-26-2023

#include "TranslatorFacade.h"
#include "Translator.h"

// Method that loads a file into the Translator
// @param armFile : string containing the path to an ARM file to load
// @return bool : true if the file was loaded correctly, false otherwise
bool TranslatorFacade::loadFile(std::string armFile) {
	this->translator = Translator::getInstance(armFile);
	return this->translator.isLoaded();
}

// Method that clears the file currently in the Translator
void TranslatorFacade::clearFile() {
	this->translator.clearFile();
}

// Method that checks is the code given to the Translator could be translated
// @return bool : true if there is translated code, false otherwise
bool TranslatorFacade::isTranslatable() {
	return this->translator.isTranslatable();
}

/* 
//Can uncomment when Hex4digit has been defined

// Method that returns a vector<Hex4digit>, which is the translated code from the Translator
// @return vector<Hex4digit> : containing the translated code
std::vector<Hex4digit> TranslatorFacade::translateToMachine() {
	return this->translator.getTranslatedCode();
}
*/

// Method that gets the last exception message that was thrown by the Translator
// @return string : containing the last exception message
std::string TranslatorFacade::getLastExceptionMessage() {
	return this->translator.getExceptionMessage();
}