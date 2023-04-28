#include "pch.h"
#include "../ARM360/headers/InstructionParser.h"
#include "../ARM360/headers/Orchestrator.h"
#include <unordered_map>
#include "gtest/gtest.h"

TEST(InstructionParser, getInstance) {
	InstructionParser* result1 = InstructionParser::getInstance();
	InstructionParser* result2 = InstructionParser::getInstance();

	EXPECT_EQ(result1, result2);
}

TEST(InstructionParser, getParser) {
	InstructionParser* parser = InstructionParser::getInstance();
	const std::type_info& type1 = typeid(parser->getParser());
	std::unordered_map map = std::unordered_map<std::string, std::string>();
	const std::type_info& type2 = typeid(map);

	EXPECT_EQ(type1, type2);
}