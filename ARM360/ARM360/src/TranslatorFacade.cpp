// TranslatorFacade source file
// Autumn Clark
// 02-05-2023

#include "stdafx.h"
#include "TranslatorFacade.h"

/// <summary>
/// Default constructor
/// Load field 'translator' with the Translator instance, given a null pointer -- given file later
/// </summary>
TranslatorFacade::TranslatorFacade() : translator(Translator::getInstance(nullptr)) 
{}

/// <summary>
/// Method that loads a file into the translator
/// </summary>
/// <param name="armFile">string containing the path to a file</param>
/// <returns>True if successfully loaded; false otherwise</returns>
bool TranslatorFacade::loadFile(std::string armFile) {
	TranslatorFacade::translator = Translator::getInstance(armFile);
	return TranslatorFacade::translator->isLoaded();
}

/// <summary>
/// Method that clears the file currently loaded in the translator
/// </summary>
void TranslatorFacade::clearFile() {
	TranslatorFacade::translator->clearFile();
}

/// <summary>
/// Method that checks if the file loaed was able to be translated
/// </summary>
/// <returns>True if translated successfully; false otherwise</returns>
bool TranslatorFacade::isTranslatable() {
	return TranslatorFacade::translator->isTranslatable();
}

/// <summary>
/// Method that translates the loaded file into machine code
/// </summary>
/// <returns>The translated machine code</returns>
std::vector<Hex4digit> TranslatorFacade::translateToMachine() {
	return TranslatorFacade::translator->getTranslatedCode();
}

/// <summary>
/// Method that gets the last exception message generated from the translator
/// </summary>
/// <returns>The message of the exception</returns>
std::string TranslatorFacade::getLastExceptionMessage() {
	return TranslatorFacade::translator->getExceptionMessage();
}