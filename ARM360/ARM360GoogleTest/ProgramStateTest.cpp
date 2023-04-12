#include "pch.h"
#include "ProgramState/ProgramState.h"
#include "Hex4digit.h"
#include "MemoryHistorySpace.h"

class ProgramStateTests : public ::testing::Test {
protected:
    void SetUp() override {
        programState = ProgramState::getInstance();
    }

    void TearDown() override {
        programState->clearProgramState();
    }

    ProgramState* programState;
};

// Test initializeState() method with empty array of instructions
TEST_F(ProgramStateTests, InitializeState_WithEmptyArray_ReturnsFalse) {
    std::vector<Hex4digit> emptyInstructions(0);

    bool result = programState->initializeState(emptyInstructions);

    EXPECT_FALSE(result);
}

//Test initializeState() method with non-empty array of instructions
TEST_F(ProgramStateTests, InitializeState_WithNonEmptyArray_ReturnsTrue) {
    std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
    nonEmptyInstructions[0] = Hex4digit(0x0001);

    bool result = programState->initializeState(nonEmptyInstructions);

    EXPECT_TRUE(result);
}

// Test clearProgramState() method
TEST_F(ProgramStateTests, ClearProgramState_RegistersAndHistoryCleared) {
    std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
    nonEmptyInstructions[0] = Hex4digit(0x0001);
    programState->initializeState(nonEmptyInstructions);

    programState->clearProgramState();

    Hex4digit zeroHex = Hex4digit(0);

    EXPECT_TRUE(programState->memoryStateHistory.empty());
    EXPECT_EQ(zeroHex.getValue(), programState->registers[0].getValue());
    EXPECT_EQ(zeroHex.getValue(), programState->registers.back().getValue());
}

// Test printableProgramState() method with zero memory state
TEST_F(ProgramStateTests, PrintableProgramState_WithZeroMemoryState) {
    std::vector<Hex4digit> zeroInstructions(ProgramState::TOTAL_MEMORY_SPACES);
    programState->initializeState(zeroInstructions);

    std::string result = programState->printableProgramState();

    std::cout << result << std::endl;

    EXPECT_FALSE(result.find("Next:\n") != std::string::npos);
}

// Test printableProgramState() method with non-zero memory state
TEST_F(ProgramStateTests, PrintableProgramState_WithNonZeroMemoryState) {
    std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
    nonEmptyInstructions[0] = Hex4digit(0x0001);
    programState->initializeState(nonEmptyInstructions);

    std::string result = programState->printableProgramState();

    EXPECT_TRUE(result.find("Next:") != std::string::npos);
}

TEST_F(ProgramStateTests, getMemoryStateValue) {
    std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
    nonEmptyInstructions[0] = Hex4digit(0x0001);
    programState->initializeState(nonEmptyInstructions);

    Hex4digit testVal = Hex4digit(0x0001);

    EXPECT_EQ(programState->getMemoryStateValue(0).getValue(), testVal.getValue());
}

TEST_F(ProgramStateTests, CompareInstance) {
    ProgramState * ProgramStateTwo = ProgramState::getInstance();

    EXPECT_EQ(programState, ProgramStateTwo);
}