#include "pch.h"

#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/TranslatorFacade.h"
#include "../../ARM360/headers/Hex4digit.h"

TEST(TranslatorFacade, clearFile) {
	TranslatorFacade facade = TranslatorFacade();

	bool expectedResult = false;
	facade.clearFile();
	bool result = facade.isTranslatable();

	EXPECT_EQ(expectedResult, result);
}
TEST(TranslatorFacade, isTranslatable) {
	TranslatorFacade facade = TranslatorFacade();

	bool expectedResult = false;
	bool result = facade.isTranslatable();

	EXPECT_EQ(expectedResult, result);
}
TEST(TranslatorFacade, getLastExceptionMessage) {
	TranslatorFacade facade = TranslatorFacade();

	std::string expectedMessage = "No Error";
	std::string result = facade.getLastExceptionMessage();

	EXPECT_EQ(expectedMessage, result);
}