#include "Day05_AlchemicalReduction.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day05
{
	AlchemicalReduction::AlchemicalReduction() : Day(5, "Alchemical Reduction")
	{}

	uint64_t AlchemicalReduction::ExecutePart1(const std::vector<std::string> input)
	{
		std::string polymer = input[0];
		bool hasReacted = false;

		do
		{
			// Initially, there is no reaction
			hasReacted = false;

			// Iterate the whole polymer
			auto reactBegin = polymer.begin();
			while (reactBegin < polymer.end() - 1)
			{
				// Compare a single unit with the next unit
				auto reactEnd = reactBegin + 1;

				// Check if the current pair reacts:
				if (std::abs(*reactBegin - *reactEnd) == 32)
				{
					hasReacted = true;

					// While possible, try to extend the reacting range:
					while (reactBegin != polymer.begin() && reactEnd != polymer.end() - 1 && 
						   std::abs(*(reactBegin - 1) - *(reactEnd + 1)) == 32)
					{
						reactBegin--;
						reactEnd++;
					}
				}

				// Reduce the polymer:
				if (hasReacted)
				{
					// Continue looking for reactions after the erased part:
					reactBegin = polymer.erase(reactBegin, reactEnd + 1);
					hasReacted = false;
				}
				else
				{
					// No reaction: check the next pair
					reactBegin++;
				}
			}
		} while (hasReacted); // While at least one reaction occured, recheck for any new possible combinations

		return polymer.length();
	}

	uint64_t AlchemicalReduction::ExecutePart2(const std::vector<std::string> input)
	{
		std::vector<uint64_t> reducedPolymerLengths;

		for (char unit = 'A'; unit <= 'Z'; ++unit)
		{
			std::string polymer = input[0];

			polymer.erase(std::remove_if(polymer.begin(), polymer.end(),
				[unit](char c) { return c == unit || c == unit + 32; } // Check for upper- or lowercase letters
			), polymer.end());

			reducedPolymerLengths.push_back(GetResultOnPart1(std::vector<std::string> { polymer }));
		}

		return *std::min_element(reducedPolymerLengths.begin(), reducedPolymerLengths.end());
	}
}
