#include "InputProvider.h"
#include <fstream>

std::vector<std::string> InputProvider::ReadLinesFromFile(const char* filename)
{
	std::vector<std::string> lines;

	// Open input file stream:
	std::ifstream inFile;
	inFile.open(filename, std::ios::in);

	// Read file line by line:
	for (std::string line; std::getline(inFile, line); )
	{
		lines.push_back(line);
	}

	// Close file and return content:
	inFile.close();
	return lines;
}
