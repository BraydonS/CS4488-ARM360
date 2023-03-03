#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/ExecutorFacade.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/InstructionSet.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/MockDataGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
	TEST_CLASS(ExecutorFacadeTest) {

public:
	ExecutorFacade EF;
	ProgramState* PS = ProgramState::getInstance();
	MockDataGenerator mockData;

	// Object initalizaton before every test
	TEST_METHOD_INITIALIZE(ExecutorFacadeInit) {
		ExecutorFacade EF;
		ProgramState* ps = ProgramState::getInstance();
		MockDataGenerator mockData;
	}

	// Object deletion after every test
	TEST_METHOD_CLEANUP(ExecutorFacadeCleanup) {
		delete &EF;
		delete PS;
		delete &mockData;
	}

	// Test MemoryStateIndex is incremented by 1
	TEST_METHOD(incrementMemoryIndexTest) {
		EF.incrementMemoryIndex();
		int currentMemoryStateIndex = EF.getMemoryStateIndex();
		Assert::AreEqual(currentMemoryStateIndex, 1);
	}

	TEST_METHOD(updatePCHistoryTest) {
	}

	// Tests to make sure the getMemoryStateIndex is successful
	TEST_METHOD(getMemoryStateIndexTest) {
		Assert::AreEqual(EF.getMemoryStateIndex(), 0);
	}

	TEST_METHOD(hasNextTestFalse) {
		PS->registers[15] = 999; // Large value to force execption.
		Assert::IsFalse(EF.hasNext());
	}

	// Test to check if the next instruction actually exists.
	TEST_METHOD(hasNextTestTrue) {
		PS->registers[15] = PS->memoryStateHistory.at(EF.getMemoryStateIndex()).size() - 1;
		Assert::IsTrue(EF.hasNext());
	}

	// Tests if the setProgramState method creates an empty program state history.
	TEST_METHOD(setProgramStateTest) {
		EF.setProgramState(*PS);
		Assert::IsTrue(EF.hasState());
	}

	// Tests to check if the current ProgramState is empty
	TEST_METHOD(hasStateTestFalse) {
		PS->memoryStateHistory.clear();
		Assert::IsFalse(EF.hasState());
	}

	TEST_METHOD(hasStateTestTrue) {
		EF.setProgramState(*PS);
		Assert::IsTrue(EF.hasState());
	}

	// Test to make sure the EXCEPTIONMESSAGE updates after an invalid instruction.
	// Done by Adding junk data to ps, calling next, then checking exepetion message
	TEST_METHOD(unrecognizedInstructionTest) {
		char invalidChar = mockData.getJunkChar();
		initalizeProgramState(invalidChar);

		EF.next();
		std::string expectedError = "The given instruction was not recognized!";
		bool invalidMessage = expectedError.compare(EF.getLastExceptionMessage());
		
		Assert::IsTrue(invalidMessage);
	}

	// Test to check determineInstruction works properly
	// A proper test would test every possible instruction(16 + invalid).
	TEST_METHOD(determineInstructionTest) {
		initalizeProgramState('0');

		EF.next();

		Hex4digit haltInstruction = Hex4digit(-1);
		Hex4digit registerInstruction = PS->registers[15];
		char haltInstructionChar = haltInstruction.getFirst();
		char registerInstructionChar = registerInstruction.getFirst();

		Assert::IsTrue(haltInstructionChar == registerInstructionChar);
	}

	// Test to check if next works by checking if it increments the memoryStateIndex properly.
	TEST_METHOD(nextTest) {
		initalizeProgramState('0');
		EF.next();
		Assert::IsTrue(EF.getMemoryStateIndex() == 1);
	}

	// Test that fills the program state with '0', then clears it and checks if the pcHistry is 0
	TEST_METHOD(clearStateTest) {
		initalizeProgramState('0');
		EF.clearState();
		
		Assert::IsTrue(PS->pcHistory.size() == 0);
	}

	// Test to check if a new Program State will return a "No Error" exeption message.
	TEST_METHOD(getLastExceptionMessageTest) {
		Assert::IsTrue(EF.getLastExceptionMessage().compare("No Error"));
	}


	// Supporting method to initalize the program state with some data.
	ProgramState initalizeProgramState(char instruction) {
		std::array<Hex4digit, 256> instructions;
		for (int i = 0; i < 3; i++) {
			instructions[i] = instruction;
		}
		PS->initializeState(instructions);
		return *PS;
	}

	};

}