#include "pch.h"

#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Translator.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"
#include "../../ARM360/headers/MemoryHistorySpace.h"
#include "../../ARM360/headers/MockDataGenerator.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/InstructionParser.h"


TEST(Translator, getInstance) {
	Translator* result1 = Translator::getInstance("Fake File");
	Translator* result2 = Translator::getInstance("Fake File");

	EXPECT_EQ(&result1, &result2);
}
TEST(Translator, setArmFile) {
	Translator* tran = Translator::getInstance("Fake File");

	std::string expectedResult = "New Fake File";
	tran->setArmFile("New Fake File");
	std::string result = tran->getArmFile();

	EXPECT_EQ(expectedResult, result);
}
TEST(Translator, getArmFile) {
	Translator* tran = Translator::getInstance("Fake File");
	tran->setArmFile("Fake File");

	std::string expectedResult = "Fake File";
	std::string result = tran->getArmFile();

	EXPECT_EQ(expectedResult, result);
}
TEST(Translator, clearFile) {
	Translator* tran = Translator::getInstance("Fake File");

	std::string expectedResult = "";
	tran->clearFile();
	std::string result = tran->getArmFile();

	EXPECT_EQ(expectedResult, result);
}
TEST(Translator, getExceptionMessage) {
	Translator* tran = Translator::getInstance("Fake File");

	std::string expectedResult = "No Error";
	std::string result = tran->getExceptionMessage();

	EXPECT_EQ(expectedResult, result);
}
TEST(Translator, setExceptionMessage) {
	Translator* tran = Translator::getInstance("Fake File");

	std::string expectedResult = "New message";
	tran->setExceptionMessage(expectedResult);
	std::string result = tran->getExceptionMessage();

	EXPECT_EQ(expectedResult, result);
}