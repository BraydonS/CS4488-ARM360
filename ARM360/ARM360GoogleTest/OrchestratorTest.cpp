#include "pch.h"

#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Orchestrator.h"
#include "../../ARM360/headers/ExecutorFacade.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/TranslatorFacade.h"

#include <unordered_map>
#include "gtest/gtest.h"

TEST(Orchestrator, getInstance) {
	Orchestrator* result1 = Orchestrator::getInstance();
	Orchestrator* result2 = Orchestrator::getInstance();

	EXPECT_EQ(result1, result2);
}

TEST(Orchestrator, getError) {
	Orchestrator* obj = Orchestrator::getInstance();

	std::string expectedResult = "Orchestrator: No Error.";
	std::string result = obj->getError();

	EXPECT_EQ(expectedResult, result);
}
TEST(Orchestrator, next) {
	Orchestrator* obj = Orchestrator::getInstance();

	bool expectedResult = false;
	bool result = obj->next();

	EXPECT_EQ(expectedResult, result);
}
TEST(Orchestrator, clearProgram) {
	Orchestrator* obj = Orchestrator::getInstance();

	obj->clearProgram();
	int expectedResult = 0;
	int result = ProgramState::getInstance()->registers[15].getValue();

	EXPECT_EQ(expectedResult, result);
}
TEST(Orchestrator, getProgramState) {
	Orchestrator* obj = Orchestrator::getInstance();

	ProgramState* expectedResult = ProgramState::getInstance();
	ProgramState* result = obj->getProgramState();

	EXPECT_EQ(expectedResult, result);
}