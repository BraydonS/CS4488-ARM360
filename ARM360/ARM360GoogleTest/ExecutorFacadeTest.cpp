#include "pch.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/ExecutorFacade.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/InstructionSet.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/MockDataGenerator.h"

ExecutorFacade EF;
ProgramState* PS = ProgramState::getInstance();
MockDataGenerator mockData;

// Object initalizaton before every test
void SetUp() {
	ExecutorFacade EF;
	ProgramState* ps = ProgramState::getInstance();
	MockDataGenerator mockData;
}

 // Object deletion after every test
void TearDown() {
	delete& EF;
	delete PS;
	delete& mockData;
}

// Supporting method to initalize the program state with some data.
ProgramState initalizeProgramState(char instruction) {
	std::vector<Hex4digit> instructions((ProgramState::TOTAL_MEMORY_SPACES));
	for (int i = 0; i < 3; i++) {
		instructions[i] = instruction;
	}
	PS->initializeState(instructions);
	return *PS;
}

// Test MemoryStateIndex is incremented by 1
TEST(ExecutorFacade, incrementMemoryIndexTest) {
	EF.incrementMemoryIndex();
	int currentMemoryStateIndex = EF.getMemoryStateIndex();
	EXPECT_EQ(currentMemoryStateIndex, 1);
}

TEST(ExecutorFacade, updatePCHistoryTest) {
}

// Tests to make sure the getMemoryStateIndex is successful
TEST(ExecutorFacade, getMemoryStateIndexTest) {
	EF.clearState();
	EXPECT_EQ(EF.getMemoryStateIndex(), 0);
}

TEST(ExecutorFacade, hasNextTestFalse) {
	PS->registers[15] = 999; // Large value to force execption.
	EXPECT_EQ(EF.getLastExceptionMessage(), "Program Counter tried to access memory out of bounds"); 
}

// Tests if the setProgramState method creates an empty program state history.
TEST(ExecutorFacade, setProgramStateTest) {
	EF.setProgramState(*PS);
	EXPECT_FALSE(EF.hasState());
}

// Tests to check if the current ProgramState is empty
TEST(ExecutorFacade, hasStateTestFalse) {
	PS->memoryStateHistory.clear();
	EXPECT_FALSE(EF.hasState());
}

// Test to make sure the EXCEPTIONMESSAGE updates after an invalid instruction.
// Done by Adding junk data to ps, calling next, then checking exepetion message
TEST(ExecutorFacade, unrecognizedInstructionTest) {
	char invalidChar = mockData.getJunkChar();
	initalizeProgramState(invalidChar);
	EF.next();

	EXPECT_EQ(EF.getLastExceptionMessage(), "Program Counter tried to access memory out of bounds");
}

// Test to check determineInstruction works properly
// A proper test would test every possible instruction(16 + invalid).
TEST(ExecutorFacade, determineInstructionTest) {
	initalizeProgramState('0');

	EF.next();

	Hex4digit haltInstruction = Hex4digit(-1);
	Hex4digit registerInstruction = PS->registers[15];
	char haltInstructionChar = haltInstruction.getFirst();
	char registerInstructionChar = registerInstruction.getFirst();

	EXPECT_TRUE(haltInstructionChar == registerInstructionChar);
}

// Test to check if next works by checking if it increments the memoryStateIndex properly.
TEST(ExecutorFacade, nextTest) {
	initalizeProgramState('0');
	EF.next();
	EXPECT_FALSE(EF.getMemoryStateIndex() == 1);
}

// Test that fills the program state with '0', then clears it and checks if the pcHistry is 0
TEST(ExecutorFacade, clearStateTest) {
	initalizeProgramState('0');
	EF.clearState();

	EXPECT_TRUE(PS->pcHistory.size() == 0);
}

// Test to check if a new Program State will return a "No Error" exeption message.
TEST(ExecutorFacade, getLastExceptionMessageTest) {
	EXPECT_TRUE(EF.getLastExceptionMessage().compare("No Error"));
}