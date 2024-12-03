#include "Day03_MullItOver.h"
#include <regex>

namespace AdventOfCode::Year2024::Day03
{
	MullItOver::MullItOver() : Day(3, "Mull It Over") { }

	const std::regex patternMul("mul\\((\\d{1,3})\\,(\\d{1,3})\\)");
	const std::regex patternDo("do\\(\\)");
	const std::regex patternDont("don't\\(\\)");


	uint64_t MullItOver::ExecutePart1(std::vector<std::string> program)
	{
		uint64_t result = 0;

		std::smatch matches;
		for (std::string& line : program)
		{
			// Find all "mul" patterns:
			while (std::regex_search(line, matches, patternMul))
			{
				auto m1 = std::stoull(matches[1].str());
				auto m2 = std::stoull(matches[2].str());
				result += m1 * m2;

				// Continue searching the rest of the line:
				line = matches.suffix();
			}
		}

		return result;
	}

	uint64_t MullItOver::ExecutePart2(std::vector<std::string> program)
	{
		// Current state of the program: is the "mul" instruction enabled
		bool isMulEnabled = true;

		// Parts of the program that are actually executed:
		std::vector<std::string> enabledProgram;

		std::smatch matches;
		for (std::string& line : program)
		{
			// Split each line into enabled and disabled parts:
			bool isMore = true;
			while(isMore)
			{
				if (isMulEnabled)
				{
					// search next "don't" instruction:
					if (std::regex_search(line, matches, patternDont))
					{
						enabledProgram.emplace_back(matches.prefix().str());
						line = matches.suffix().str();
						isMulEnabled = false;
					}
					else
					{
						// no more "don't" found: rest of the line is enabled
						enabledProgram.emplace_back(line);
						isMore = false;
					}
				}
				else
				{
					// search next "do" instruction:
					if (std::regex_search(line, matches, patternDo))
					{
						line = matches.suffix().str();
						isMulEnabled = true;
					}
					else
						isMore = false;
				}
			}
		}

		// Remaining (anabled) program works like part 1:
		return ExecutePart1(enabledProgram);
	}
}
