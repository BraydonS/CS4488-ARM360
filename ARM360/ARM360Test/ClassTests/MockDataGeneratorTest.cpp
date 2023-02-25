#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/MockDataGenerator.h"
#include <regex>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
	TEST_CLASS(MockDataGeneratorTest) {

public:

	TEST_METHOD(getRandomHexCharTest) {
		char randomHexChar = MockDataGenerator::getRandomHexChar();
		std::string randomHexString(1, randomHexChar);
		std::regex hexCheckerRegex("([a-f]|[0-9])*");
		bool matchFound = std::regex_match(randomHexString, hexCheckerRegex);
		Assert::IsTrue(matchFound);
	}

	TEST_METHOD(getRandomHexValueTest) {}

	TEST_METHOD(getRandomHexValue4Test) {}

	TEST_METHOD(getRandomHexChar5Test) {}

	TEST_METHOD(getJunkCharTest) {}

	TEST_METHOD(getJunkChar4Test) {}

	};
}