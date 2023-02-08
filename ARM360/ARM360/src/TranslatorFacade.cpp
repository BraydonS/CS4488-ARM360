// TranslatorFacade source file
// Autumn Clark
// 02-05-2023

#include "stdafx.h"
#include "TranslatorFacade.h"

// Default constructor
// Load field 'translator' with the Translator instance, given a null pointer -- given file later
TranslatorFacade::TranslatorFacade() : translator(Translator::getInstance(nullptr)) 
{}

// Method that loads a file into the translator
// @param armFile : string containing the path to a file
// @return bool : True if successfully loaded; false otherwise
bool TranslatorFacade::loadFile(std::string armFile) {
	TranslatorFacade::translator = Translator::getInstance(armFile);
	return TranslatorFacade::translator.isLoaded();
}

// Method that clears the file currently loaded in the translator
void TranslatorFacade::clearFile() {
	TranslatorFacade::translator.clearFile();
}

// Method that checks if the file loaed was able to be translated
// @return bool : True if translated successfully; false otherwise
bool TranslatorFacade::isTranslatable() {
	return TranslatorFacade::translator.isTranslatable();
}

// Method that translates the loaded file into machine code
// @return vector<Hex4digit> : The translated machine code
std::vector<Hex4digit> TranslatorFacade::translateToMachine() {
	return TranslatorFacade::translator.getTranslatedCode();
}

// Method that gets the last exception message generated from the translator
// @return string : The message of the exception
std::string TranslatorFacade::getLastExceptionMessage() {
	return TranslatorFacade::translator.getExceptionMessage();
}