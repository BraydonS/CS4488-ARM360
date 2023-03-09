// Test file for class TranslatorFacade
// Autumn Clark

#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/TranslatorFacade.h"
#include "../../ARM360/headers/Hex4digit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360 {
	TEST_CLASS(TranslatorFacadeTest) {

		TranslatorFacade facade;

		// Method that is run before every test
		TEST_METHOD_INITIALIZE(TranslatorInit) {
			facade = TranslatorFacade();
		}

		// Method that is run after every test
		TEST_METHOD_CLEANUP(TranslatorCleanup) {
			delete &facade;
		}

		TEST_METHOD(loadFile) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(clearFile) {
			bool expectedResult = false;
			facade.clearFile();
			bool result = facade.isTranslatable();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(isTranslatable) {
			bool expectedResult = false;
			bool result = facade.isTranslatable();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(translateToMachine) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(getLastExceptionMessage) {
			std::string expectedMessage = "No Error";
			std::string result = facade.getLastExceptionMessage();
			
			Assert::AreEqual(expectedMessage, result);
		}

		/*
		* Methods left to test
		bool loadFile(std::string armFile);
		std::vector<Hex4digit> translateToMachine();
		*/
	};
}