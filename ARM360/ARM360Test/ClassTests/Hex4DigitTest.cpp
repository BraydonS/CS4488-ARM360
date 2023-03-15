#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
	TEST_CLASS(Hex4DigitTest) {

		Hex4digit hex4Digit;
		HexadecimalConverter hexConv;
		public:

			// Object initalizaton before every test
			TEST_METHOD_INITIALIZE(Hex4DigitInit) {
				Hex4digit hex4Digit;
				HexadecimalConverter hexConv;
			}

			// Object deletion after every test
			TEST_METHOD_CLEANUP(Hex4DigitCleanup) {
				delete &hex4Digit;
				delete &hexConv;
			}

			TEST_METHOD(setValueIntTest) {
				hex4Digit.setValue(int(3));
				Assert::AreEqual(hexConv.decimalToHex(3)[1], hex4Digit.getFirst());
			}

			TEST_METHOD(setValueStringTest) {
				hex4Digit.setValue(std::string("4"));
				Assert::AreEqual(hexConv.decimalToHex(4)[1], hex4Digit.getFirst());
			}

			TEST_METHOD(setValueCharArrayTest) {
				std::array<char, 5> charArray = { "0" };
				hex4Digit.setValue(charArray);
				Assert::IsTrue(hexConv.decimalToHex(0) == hex4Digit.getHexChars());
			}

			TEST_METHOD(setFirstTest) {
				hex4Digit.setValue(std::string("4"));
				hex4Digit.setFirst(char('5'));
				Assert::AreEqual(hexConv.decimalToHex('5')[1], hex4Digit.getFirst());
			}

			TEST_METHOD(setSecondTest) {
				hex4Digit.setValue(std::string("4"));
				hex4Digit.setSecond(char('2'));
				Assert::AreEqual(hexConv.decimalToHex('2')[1], hex4Digit.getSecond());
			}

			TEST_METHOD(setThirdTest) {
				hex4Digit.setValue(std::string("4"));
				hex4Digit.setThird(char('3'));
				Assert::AreEqual(hexConv.decimalToHex('3')[1], hex4Digit.getThird());
			}

			TEST_METHOD(setFourthTest) {
				hex4Digit.setValue(std::string("4"));
				hex4Digit.setFourth(char('4'));
				Assert::AreEqual(hexConv.decimalToHex('4')[1], hex4Digit.getFourth());
			}

			TEST_METHOD(getValueTest) {
				std::array<char, 5> charArray = { "3" };
				hex4Digit.setValue(charArray);
				Assert::IsTrue(3 == hex4Digit.getValue());
			}

			TEST_METHOD(getHexCharsTest) {
				std::array<char, 5> array = {};
				Assert::IsTrue(array == hex4Digit.getHexChars());
			}

			TEST_METHOD(getSingedHexCharsTest) {
				std::array<char, 5> array = { '1' };
				hex4Digit.setValue(array);
				Assert::IsTrue(array == hex4Digit.getSignedHexChars());
			}

			TEST_METHOD(getStringTest) {
				std::string testString = "2";
				hex4Digit.setValue("2");
				Assert::AreEqual(testString, hex4Digit.getString());
			}

			TEST_METHOD(getMiddle2ValueTest) {
				hex4Digit.setValue("2112");
				Assert::AreEqual(11, hex4Digit.getMiddle2Value());
			}

			TEST_METHOD(getLast2ValueTest) {
				hex4Digit.setValue("0011");
				Assert::AreEqual(11, hex4Digit.getLast2Value());
			}

			TEST_METHOD(hexCharTest) {
				Assert::AreEqual('1', hex4Digit.hexChar(1));
			}

			TEST_METHOD(hexValueTest) {
				Assert::AreEqual(3, hex4Digit.hexValue('3'));
			}
	};
}