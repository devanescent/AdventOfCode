#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "SolutionFactory.h"
#include "toml.hpp"

using namespace AdventOfCode;

// ---------------------------------------------------------------------------
// ReadLinesFromFile: Process input file to string lines
// ---------------------------------------------------------------------------
std::vector<std::string> ReadLinesFromFile()
{
	std::vector<std::string> lines;
	lines.reserve(1000);

	std::ifstream inFile("Input.txt");
	std::string line;
	while (std::getline(inFile, line))
		lines.push_back(line);

	return lines;
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	// Read which year / day / part to run from config:
	auto appConfig = toml::parse_file("appconfig.toml");
	int year = appConfig["run"]["year"].value_or(2023);
	int day = appConfig["run"]["day"].value_or(1);
	int part = appConfig["run"]["part"].value_or(1);

	// Solution of the given year / day:
	auto solution = SolutionFactory().GetYear(year)->GetDay(day);
	if (solution)
	{
		// Read input and get results:
		auto lines = ReadLinesFromFile();
		auto res = part == 1 ? solution->GetResultOnPart1(lines) : solution->GetResultOnPart2(lines);

		// Print results to screen:
		std::cout << "Day " << solution->GetDayNo() << " - " << solution->GetName() << "\n";
		std::cout << "--------------------------------------------------\n";
		std::cout << "Result (part " << part << "): " << res << "\n\n\n";
	}
	else
	{
		std::cout << "No solution for this year / day\n";
	}
	

	// Wait for keypress (in particular, when debugger is running):
	std::cout << "\nPress enter to exit...\n";
	std::cin.ignore();
	return 0;
}

