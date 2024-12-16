#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <format>
#include <filesystem>
#include "SolutionFactory.h"
#include "toml.hpp"

using namespace AdventOfCode;

// ---------------------------------------------------------------------------
// ReadLinesFromFile: Process input file to string lines
// ---------------------------------------------------------------------------
std::vector<std::string> ReadLinesFromFile(std::ifstream& input)
{
	std::vector<std::string> lines;
	lines.reserve(1000);

	std::string line;
	while (std::getline(input, line))
		lines.push_back(line);

	return lines;
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	if (!std::filesystem::exists("appconfig.toml"))
	{
		std::cout << "Error: No config file (appconfig.toml) found in current / working directory\n";
		return -1;
	}

	// Read which year / day / part to run from config:
	auto appConfig = toml::parse_file("appconfig.toml");

	int year = appConfig["run"]["year"].value_or(2023);
	int day = appConfig["run"]["day"].value_or(1);
	int part = appConfig["run"]["part"].value_or(1);

	bool useCache = appConfig["caching"]["use_cache"].value_or(false);
	std::string cacheDirectory = appConfig["caching"]["cache_dir"].value_or("");

	// Solution of the given year / day:
	auto solution = SolutionFactory().GetYear(year)->GetDay(day);
	if (solution)
	{
		// Default input name:
		std::string inputFileName("Input.txt");

		// Cache file:
		std::string cacheFileName = std::format("Input_{}_{}.txt", year, day);
		auto cacheFileLocation = std::filesystem::path(cacheDirectory) / cacheFileName;

		if (useCache && !cacheDirectory.empty())
		{
			if (!std::filesystem::exists(cacheFileLocation))
			{
				std::cout << "No cached input available for " << year << "/" << day << "\n";
				return -1;
			}
			else
			{
				// Replace default input with cached input file:
				inputFileName = cacheFileLocation.string();
			}
		}
		else
		{
			if (!std::filesystem::exists("Input.txt"))
			{
				std::cout << "Error: No input file (Input.txt) found in current / working directory\n";
				return -1;
			}

			// Cache current input file for later use:
			if (!cacheDirectory.empty() && !std::filesystem::exists(cacheFileLocation))
				std::filesystem::copy("Input.txt", cacheFileLocation);
		}

		// Read input (or use cached input data):
		std::ifstream inputFile(inputFileName);
		auto lines = ReadLinesFromFile(inputFile);
		auto res = part == 1 ? solution->GetResultOnPart1(lines) : solution->GetResultOnPart2(lines);

		// Print results to screen:
		std::cout << "Day " << solution->GetDayNo() << " - " << solution->GetName() << "\n";
		std::cout << "--------------------------------------------------\n";
		std::cout << "Result (part " << part << "): " << res.ToString() << "\n\n\n";
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

