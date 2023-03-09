// Test file for class Translator
// Autumn Clark

#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Translator.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"
#include "../../ARM360/headers/MemoryHistorySpace.h"
#include "../../ARM360/headers/MockDataGenerator.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/InstructionParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360 {
	TEST_CLASS(TranslatorTest) {

		// Method that is run before every test
		TEST_METHOD_INITIALIZE(TranslatorInit) {

		}

		// Method that is run after every test
		TEST_METHOD_CLEANUP(TranslatorCleanup) {

		}

		TEST_METHOD(methodName) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}

        /*
        * Methods left to test
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
        */
	};
}