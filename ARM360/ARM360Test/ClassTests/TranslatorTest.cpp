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

namespace ARM360Test {
	TEST_CLASS(TranslatorTest) {

		Translator tran = Translator::getInstance("Fake File");

		// Method that is run before every test
		TEST_METHOD_INITIALIZE(TranslatorInit) {
			tran = Translator::getInstance("Fake File");
		}

		// Method that is run after every test
		TEST_METHOD_CLEANUP(TranslatorCleanup) {
			delete& tran;
		}

		TEST_METHOD(isTranslatable) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(setTranslatable) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(getInstance) {
			Translator result1 = Translator::getInstance("Fake File");
			Translator result2 = Translator::getInstance("Fake File");

			Assert::AreSame(result1, result2);
		}
		TEST_METHOD(setArmFile) {
			std::string expectedResult = "New Fake File";
			tran.setArmFile("New Fake File");
			std::string result = tran.getArmFile();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(setTranslatedCode) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(getArmFile) {
			std::string expectedResult = "Fake File";
			std::string result = tran.getArmFile();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(isLoaded) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(getTranslatedCode) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(clearFile) {
			std::string expectedResult = "";
			tran.clearFile();
			std::string result = tran.getArmFile();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(getExceptionMessage) {
			std::string expectedResult = "No Error";
			std::string result = tran.getExceptionMessage();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(setExceptionMessage) {
			std::string expectedResult = "New message";
			tran.setExceptionMessage(expectedResult);
			std::string result = tran.getExceptionMessage();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(convertToHex) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}

        /*
        * Methods left to test
        bool isTranslatable();
        void setTranslatable(bool translatable);
        void setTranslatedCode(std::vector<Hex4digit> translatedCode);
        bool isLoaded();
        std::vector<Hex4digit> getTranslatedCode();
        std::vector<Hex4digit> convertToHex(std::string parsedFile[]);
        */
	};
}