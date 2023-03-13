// Test file for class InstructionParser
// Autumn Clark

#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/InstructionParser.h"
#include <unordered_map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
	TEST_CLASS(InstructionParserTest) {

		InstructionParser parser = InstructionParser::getInstance();

		// Method that is run before every test
		TEST_METHOD_INITIALIZE(TranslatorInit) {
			parser = InstructionParser::getInstance();
		}

		// Method that is run after every test
		TEST_METHOD_CLEANUP(TranslatorCleanup) {
			delete& parser;
		}

		TEST_METHOD(getInstance) {
			InstructionParser result1 = InstructionParser::getInstance();
			InstructionParser result2 = InstructionParser::getInstance();

			//Assert::AreSame(result1, result2);
		}
		TEST_METHOD(getParser) {
			Assert::AreEqual(typeid(parser.getParser()).name(), "unordered_map");
		}
	};
}