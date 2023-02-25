#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/ExecutorFacade.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/InstructionSet.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/ExecutorFacade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
	TEST_CLASS(ExecutorFacadeTest) {

public:

	TEST_METHOD(incrementMemoryIndexTest) {
	
	}

	TEST_METHOD(updatePCHistoryTest) {}

	TEST_METHOD(getMemoryStateIndexTest) {}

	TEST_METHOD(hasNextTest) {}

	TEST_METHOD(setProgramStateTest) {}

	TEST_METHOD(hasStateTest) {}

	TEST_METHOD(unrecognizedInstructionTest) {}

	TEST_METHOD(determineInstructionTest) {}

	TEST_METHOD(nextTest) {}

	TEST_METHOD(clearStateTest) {}

	TEST_METHOD(getLastExceptionMessageTest) {}

	};

}