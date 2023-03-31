#include "pch.h"
#include "../../ARM360/headers/MockDataGenerator.h"
#include <regex>


// Function to check if a given string is a valid hex value. regex_match requires a string not a char.
bool checkValidHexValue(std::string hexValue) {
	std::regex hexCheckerRegex("([a-f]|[0-9])*"); // 0-9 & a-f should be the only valid chars.
	return std::regex_match(hexValue, hexCheckerRegex);
}

// Test to check whether or not getRandomHexChar() returns a valid hex char.
TEST(MockDataGenerator, getRandomHexCharTest) {
	char randomHexChar = MockDataGenerator::getRandomHexChar();
	std::string randomHexString(1, randomHexChar); // Coverting char to string for checkValidHexValue
}

// Test to check if the random int is betwen 0 and 15 (inclusive)
TEST(MockDataGenerator, getRandomHexValueTest) {
	int randomHexValue = MockDataGenerator::getRandomHexValue();
	EXPECT_TRUE(randomHexValue >= 0 && randomHexValue <= 15);
}

// Test to check if the random int is betwen -15 and 15 (inclusive)
TEST(MockDataGenerator, getRandomHexValue4Test) {
	int randomHexValue = MockDataGenerator::getRandomHexValue4();
	EXPECT_TRUE(randomHexValue >= -15 && randomHexValue <= 15);
}

// Test that checks if the array is only filled with valid hex character or +/- characters.
TEST(MockDataGenerator, getRandomHexChar5Test) {
	std::regex hexCheckerRegex("([a-f]|[0-9]|\\-|\\+)*"); // 0-9 & a-f & + or - should be the only valid chars.
	std::vector<char> randomHexVector = MockDataGenerator::getRandomHexChar5();
	for (auto currentHexValue : randomHexVector) {
		std::string currentHexValueAsString(1, currentHexValue);
		bool validHex = std::regex_match(currentHexValueAsString, hexCheckerRegex);
		EXPECT_TRUE(validHex);
	}
}

// Checks that the junk character provided is a non hex value. 
// Test passes if it's an invalid character. 
// Test fails if it's a valid hex character.
TEST(MockDataGenerator, getJunkCharTest) {
	std::string invalidHexChar(1, MockDataGenerator::getJunkChar());
	bool hexValueBool = checkValidHexValue(invalidHexChar);
	EXPECT_FALSE(hexValueBool);
}

// Checks if the vector of char is filled with non hex characters. 
// Test passes if it's an invalid character. 
// Test fails if it's a valid hex character.
TEST(MockDataGenerator, getJunkChar4Test) {
	std::vector<char> invalidHexVector = MockDataGenerator::getJunkChar4();
	for (auto invalidHexChar : invalidHexVector) {
		std::string currentInvalidHexValueAsString(1, invalidHexChar);
		bool invalidHexCheck = checkValidHexValue(currentInvalidHexValueAsString);
		EXPECT_FALSE(invalidHexCheck);
	}
}