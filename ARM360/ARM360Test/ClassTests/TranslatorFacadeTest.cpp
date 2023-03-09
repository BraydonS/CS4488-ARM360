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
		bool loadFile(std::string armFile);
		void clearFile();
		bool isTranslatable();
		std::vector<Hex4digit> translateToMachine();
		std::string getLastExceptionMessage();
		*/
	};
}