// Test file for class Orchestrator
// Autumn Clark

#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Orchestrator.h"
#include "../../ARM360/headers/ExecutorFacade.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/TranslatorFacade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360 {
	TEST_CLASS(OrchestratorTest) {

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
		static Orchestrator getInstance();
		std::string getError();
		bool next();
		void clearProgram();
		ProgramState getProgramState();
		void sendInput(char input[]);
		std::array<char,5> getOutput();
		bool translateAndLoad(std::string path);
		std::vector<char> convertToHexChars(short number);
		int convertToInt(char number[]);
		std::string loadFile(std::string path);
		*/
	};
}