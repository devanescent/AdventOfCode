#include "Day14_ChocolateCharts.h"
#include <algorithm>
#include <stack>
#include <sstream>

namespace AdventOfCode::Year2018::Day14
{
	ChocolateCharts::ChocolateCharts() : Day(14, "Chocolate Charts") {}

	uint64_t ChocolateCharts::GetResultOnPart1(const std::vector<std::string> input)
	{
		std::istringstream iss(input[0]);
		uint64_t requiredNumberOfRecipes;
		iss >> requiredNumberOfRecipes;

		// Initial configuration:
		std::vector<uint8_t> scores{ 3,7 };
		auto elf1 = 0;
		auto elf2 = 1;

		// Find next ten scores after the required number of recipes:
		while (scores.size() < requiredNumberOfRecipes + 10)
		{
			// New recipes score:
			uint8_t newScore = scores[elf1] + scores[elf2];

			// Add score as digits to the scoreboard:
			// This gets digits from back-to-front, so push to temporary stack to reverse afterwards:
			std::stack<uint8_t> digits;
			do
			{
				uint8_t digit = newScore % 10;
				digits.push(newScore % 10);
				newScore /= 10;
			} while (newScore > 0);

			// Pop stack to add to the scoreboard in correct order:
			while (!digits.empty())
			{
				scores.push_back(digits.top());
				digits.pop();
			}

			// Select a new recipe:
			elf1 = (elf1 + scores[elf1] + 1) % scores.size();
			elf2 = (elf2 + scores[elf2] + 1) % scores.size();
		}

		
		// Build number from last ten scores on scoreboard:
		uint64_t next10RecipesScore = 0;
		for (int i = static_cast<int>(requiredNumberOfRecipes), d = 9; i < requiredNumberOfRecipes + 10; ++i, --d)
		{
			next10RecipesScore += static_cast<uint64_t>(scores[i] * pow(10, d));
		}

		// TODO: Leading zeros not visible in result number!
		return next10RecipesScore;
	}


	uint64_t ChocolateCharts::GetResultOnPart2(const std::vector<std::string> input)
	{
		const std::string& sequence = input[0];

		// Initial configuration:
		std::vector<uint8_t> scores{ 3,7 };
		auto elf1 = 0;
		auto elf2 = 1;

		// Add recipes until the reuqired sequence has been found:
		bool foundSequence = false;
		while (!foundSequence)
		{
			// New recipes score:
			uint8_t newScore = scores[elf1] + scores[elf2];

			// Add score as digits to the scoreboard:
			// This gets digits from back-to-front, so push to temporary stack to reverse afterwards:
			std::stack<uint8_t> digits;
			do
			{
				uint8_t digit = newScore % 10;
				digits.push(newScore % 10);
				newScore /= 10;
			} while (newScore > 0);

			// Pop stack to add to the scoreboard in correct order:
			while (!digits.empty())
			{
				scores.push_back(digits.top());
				digits.pop();

				// CHeck after each added digit if the scoreboard ends in the required sequence:
				if (scores.size() >= sequence.length())
				{
					foundSequence = std::mismatch(sequence.rbegin(), sequence.rend(), scores.rbegin(),
						[](const char& c, const uint8_t& score) { return score == c - '0'; }
					).first == sequence.rend();

					if (foundSequence) 
						break; // do not add any more digits if sequence has been found
				}
			}

			if (!foundSequence)
			{
				// Select a new recipe and continue:
				elf1 = (elf1 + scores[elf1] + 1) % scores.size();
				elf2 = (elf2 + scores[elf2] + 1) % scores.size();
			}
		}

		return scores.size() - sequence.length();
	}
}