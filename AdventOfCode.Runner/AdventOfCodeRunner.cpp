#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <format>
#include "SolutionFactory.h"

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
	// TODO: read from command line
	int pYear = 2022;
	int pDay = 1;

	// Solution of the given year / day:
	auto day = SolutionFactory().GetYear(pYear)->GetDay(pDay);

	// Read input and get results:
	auto lines = ReadLinesFromFile();
	auto res1 = day->GetResultOnPart1(lines);
	auto res2 = day->GetResultOnPart2(lines);

	// Pretty-print results to screen:
	std::cout
		<< "+----------------------------------------------------------------------+\n"
		<< std::format("|                         ADVENT OF CODE {:4}                          |\n", pYear)
		<< "+------+---------------------------+-----------------+-----------------+\n"
		<< "| Date | Name                      | Result (Part 1) | Result (Part 2) |\n"
		<< "+------+---------------------------+-----------------+-----------------+\n";

	std::cout << std::format("|  {:02}  | {:25} | {:15} | {:15} |\n", day->GetDayNo(), day->GetName(), res1, res2);
	std::cout << "+------+---------------------------+-----------------+-----------------+\n";

	// Wait for keypress (in particular, when debugger is running):
	std::cout << "\nPress enter to exit...\n";
	std::cin.ignore();
	return 0;
}

