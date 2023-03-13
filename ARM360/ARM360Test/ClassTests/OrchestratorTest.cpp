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

namespace ARM360Test {
	TEST_CLASS(OrchestratorTest) {

		Orchestrator obj = Orchestrator::getInstance();

		// Method that is run before every test
		TEST_METHOD_INITIALIZE(TranslatorInit) {
			obj = Orchestrator::getInstance();
		}

		// Method that is run after every test
		TEST_METHOD_CLEANUP(TranslatorCleanup) {
			obj.clearProgram();
			delete& obj;
		}

		TEST_METHOD(getInstance) {
			Orchestrator result1 = Orchestrator::getInstance();
			Orchestrator result2 = Orchestrator::getInstance();

			Assert::AreSame(result1, result2);
		}
		TEST_METHOD(getError) {
			std::string expectedResult = "Orchestrator: No Error.";
			std::string result = obj.getError();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(next) {
			bool expectedResult = false;
			bool result = obj.next();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(clearProgram) {
			obj.clearProgram();
			int expectedResult = 0;
			int result = ProgramState::getInstance()->registers[15].getValue();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(getProgramState) {
			ProgramState expectedResult = *ProgramState::getInstance();
			ProgramState result = obj.getProgramState();

			Assert::AreSame(expectedResult, result);
		}
		TEST_METHOD(sendInput) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(getOutput) {
			std::array<char, 5> expectedResult = { 0 };
			std::array<char, 5> result = obj.getOutput();

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(translateAndLoad) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(convertToHexChars) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(convertToInt) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}
		TEST_METHOD(loadFile) {
			int expectedValue = -1;
			int valueToCheck = -1;
			Assert::AreEqual(expectedValue, valueToCheck);
		}

		/*
		* Methods left to test
		void sendInput(char input[]);
		bool translateAndLoad(std::string path);
		std::vector<char> convertToHexChars(short number);
		int convertToInt(char number[]);
		std::string loadFile(std::string path);
		*/
	};
}