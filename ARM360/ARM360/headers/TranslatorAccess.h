// TranslatorAccess header file
// Autumn Clark
// 01-29-2023

// Will probably want to consoldate this into another class

#pragma once
#include <string>

class TranslatorAccess {
public:
	bool translateAndLoad(std::string path);
};