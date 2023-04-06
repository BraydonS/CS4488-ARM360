// Test file for class InstructionSet
// Autumn Clark

#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/InstructionSet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
	TEST_CLASS(InstructionSetTest) {

		InstructionSet set;
		ProgramState state = *ProgramState::getInstance();

		// Method that is run before every test
		TEST_METHOD_INITIALIZE(InstructionSetInit) {
			set = *new InstructionSet();
			state = *ProgramState::getInstance();
		}

		// Method that is run after every test
		TEST_METHOD_CLEANUP(InstructionSetCleanup) {
			delete &set;
			state.clearProgramState();
		}
		/*
		TEST_METHOD(incrementProgramCounter) {
			int expectedValue = state.registers[15].getValue() + 1;
			set.incrementProgramCounter(state);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		TEST_METHOD(halt) {
			int expectedValue = -1;
			set.halt(state);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		TEST_METHOD(load) {

		}
		TEST_METHOD(store) {

		}
		TEST_METHOD(add) {
			state.registers[1].setValue('10');
			state.registers[2].setValue('2');
			char reg1 = '1';
			char reg2 = '2';
			char reg3 = '3';
			int expectedValue = 12;
			set.add(state, reg1, reg2, reg3);
			Assert::AreEqual(expectedValue, state.registers[3].getValue());
		}
		TEST_METHOD(subt) {
			state.registers[1].setValue('10');
			state.registers[2].setValue('2');
			char reg1 = '1';
			char reg2 = '2';
			char reg3 = '3';
			int expectedValue = 8;
			set.add(state, reg1, reg2, reg3);
			Assert::AreEqual(expectedValue, state.registers[3].getValue());
		}
		TEST_METHOD(mult) {
			state.registers[1].setValue('10');
			state.registers[2].setValue('2');
			char reg1 = '1';
			char reg2 = '2';
			char reg3 = '3';
			int expectedValue = 20;
			set.add(state, reg1, reg2, reg3);
			Assert::AreEqual(expectedValue, state.registers[3].getValue());
		}
		TEST_METHOD(intDivide) {
			state.registers[1].setValue('10');
			state.registers[2].setValue('2');
			char reg1 = '1';
			char reg2 = '2';
			char reg3 = '3';
			int expectedValue = 5;
			set.add(state, reg1, reg2, reg3);
			Assert::AreEqual(expectedValue, state.registers[3].getValue());
		}
		TEST_METHOD(loadIndirect) {

		}
		TEST_METHOD(storeIndirect) {

		}
		TEST_METHOD(branch) {
			int expectedValue = 30;
			set.branch(state, 30);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		TEST_METHOD(branchZero) {
			int expectedValue = 10;
			char reg = '1';
			state.registers[1].setValue(0);
			set.branchZero(state, reg, expectedValue);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		TEST_METHOD(branchNeg) {
			int expectedValue = 10;
			char reg = '1';
			state.registers[1].setValue(-1);
			set.branchZero(state, reg, expectedValue);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		TEST_METHOD(branchPos) {
			int expectedValue = 10;
			char reg = '1';
			state.registers[1].setValue(1);
			set.branchZero(state, reg, expectedValue);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		TEST_METHOD(readInt) {
			
		}
		TEST_METHOD(writeInt) {

		}
		TEST_METHOD(skip) {
			int expectedValue = state.registers[15].getValue() + 1;
			set.skip(state);
			Assert::AreEqual(expectedValue, state.registers[15].getValue());
		}
		*/

		/*
		static void load(ProgramState state, int mem, char reg, int index);
		static void store(ProgramState state, int mem, char reg, int index);
		static void loadIndirect(ProgramState state, int mem, char reg, int index);
		static void storeIndirect(ProgramState state, int mem, char reg, int index);
		static void readInt(ProgramState state, char reg);
		static void writeInt(ProgramState state, char reg);
		*/
	};
}
