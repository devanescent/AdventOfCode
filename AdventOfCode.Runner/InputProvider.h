#pragma once
#include <vector>
#include <string>

// Reads input from file and provides it as list of strings
class InputProvider
{
public:
	std::vector<std::string> ReadLinesFromFile(const char* filename);
};

