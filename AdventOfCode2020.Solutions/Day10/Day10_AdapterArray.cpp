#include "Day10_AdapterArray.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day10 
{
	AdapterArray::AdapterArray() : DayT(10, "Adapter Array") {}

	uint64_t Day10::AdapterArray::ExecutePart1(std::vector<int> input)
	{
		// Wall adapter:
		input.push_back(0);

		// built-in adapter: max + 3:
		input.push_back(*(std::max_element(input.begin(), input.end())) + 3);

		// to use all adapters, they have to be used in ordered series:
		std::sort(input.begin(), input.end());

		// count differences of 1 and 3 joltages:
		int diff1 = 0;
		int diff3 = 0;
		for (int i = 1; i < (int)input.size(); ++i)
		{
			int diff = input[i] - input[i - 1];
			if (diff == 1)
				diff1++;
			else if (diff == 3)
				diff3++;
		}

		return diff1 * diff3;
	}

	// Recursively counts possible combinations of a (sorted) set of adapters
	int GetNumberOfCombinations(const std::vector<int>& nums, std::vector<int>::const_iterator it)
	{
		auto nextIt = it + 1;

		// Last adapter - end recursion:
		if (nextIt == nums.end())
			return 1;

		// Sum up possible combinations from "children" 
		// (= following adapters that can be used after the current one):
		int combinations = 0;
		while (nextIt != nums.end() && *nextIt - *it <= 3) // 3 = maximum possible difference between adapters
		{
			combinations += GetNumberOfCombinations(nums, nextIt);
			++nextIt;
		}

		return combinations;
	}

	uint64_t Day10::AdapterArray::ExecutePart2(std::vector<int> input)
	{
		// Wall adapter:
		input.push_back(0);

		// built-in adapter: max + 3:
		input.push_back(*(std::max_element(input.begin(), input.end())) + 3);

		// to use all adapters, they have to be used in ordered series:
		std::sort(input.begin(), input.end());

		// Split into smaller subsets where difference between two adapters is 3 
		// (meaning they have to be connected together and must always be used)
		std::vector<int> subset;
		uint64_t totalNumberOfCombinations = 1;

		for (size_t i = 1; i < input.size(); ++i)
		{
			subset.push_back(input[i - 1]);
			if (input[i] - input[i - 1] == 3)
			{
				// Find number of combinations for each subset:
				if (subset.size() > 2)
				{
					totalNumberOfCombinations *= GetNumberOfCombinations(subset, subset.begin());
				}

				subset.clear();
			}
		}
		return totalNumberOfCombinations;
	}
}