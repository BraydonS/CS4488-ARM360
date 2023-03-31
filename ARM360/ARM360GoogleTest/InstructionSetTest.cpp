#include "pch.h"

#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/InstructionSet.h"

TEST(InstructionSet, incrementProgramCounter) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = state.registers[15].getValue() + 1;
	set.incrementProgramCounter(state);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}
TEST(InstructionSet, halt) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = -1;
	set.halt(state);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}
TEST(InstructionSet, add) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	state.registers[1].setValue('10');
	state.registers[2].setValue('2');
	char reg1 = '1';
	char reg2 = '2';
	char reg3 = '3';
	int expectedValue = 12;
	set.add(state, reg1, reg2, reg3);

	EXPECT_EQ(expectedValue, state.registers[3].getValue());
}
TEST(InstructionSet, subt) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	state.registers[1].setValue('10');
	state.registers[2].setValue('2');
	char reg1 = '1';
	char reg2 = '2';
	char reg3 = '3';
	int expectedValue = 8;
	set.add(state, reg1, reg2, reg3);

	EXPECT_EQ(expectedValue, state.registers[3].getValue());
}
TEST(InstructionSet, mult) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	state.registers[1].setValue('10');
	state.registers[2].setValue('2');
	char reg1 = '1';
	char reg2 = '2';
	char reg3 = '3';
	int expectedValue = 20;
	set.add(state, reg1, reg2, reg3);

	EXPECT_EQ(expectedValue, state.registers[3].getValue());
}
TEST(InstructionSet, intDivide) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	state.registers[1].setValue('10');
	state.registers[2].setValue('2');
	char reg1 = '1';
	char reg2 = '2';
	char reg3 = '3';
	int expectedValue = 5;
	set.add(state, reg1, reg2, reg3);

	EXPECT_EQ(expectedValue, state.registers[3].getValue());
}
TEST(InstructionSet, branch) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = 30;
	set.branch(state, 30);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}
TEST(InstructionSet, branchZero) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = 10;
	char reg = '1';
	state.registers[1].setValue(0);
	set.branchZero(state, reg, expectedValue);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}
TEST(InstructionSet, branchNeg) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = 10;
	char reg = '1';
	state.registers[1].setValue(-1);
	set.branchZero(state, reg, expectedValue);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}
TEST(InstructionSet, branchPos) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = 10;
	char reg = '1';
	state.registers[1].setValue(1);
	set.branchZero(state, reg, expectedValue);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}
TEST(InstructionSet, skip) {
	InstructionSet set = *new InstructionSet();
	ProgramState state = *ProgramState::getInstance();

	int expectedValue = state.registers[15].getValue() + 1;
	set.skip(state);

	EXPECT_EQ(expectedValue, state.registers[15].getValue());
}