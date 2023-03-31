#include "pch.h"
#include "../ARM360/headers/InstructionParser.h"
#include "../ARM360/headers/Orchestrator.h"
#include <unordered_map>
#include "gtest/gtest.h"

TEST(InstructionParser, getInstance) {
	InstructionParser result1 = InstructionParser::getInstance();
	InstructionParser result2 = InstructionParser::getInstance();

	EXPECT_EQ(&result1, &result2);
}

TEST(InstructionParser, getParser) {
	InstructionParser parser = InstructionParser::getInstance();

	EXPECT_EQ(typeid(parser.getParser()).name(), "unordered_map");
}