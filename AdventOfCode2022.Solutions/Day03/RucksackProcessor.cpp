#include "RucksackProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day03
{
	std::vector<Rucksack> RucksackProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Rucksack> rucksacks;
		rucksacks.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(rucksacks),
			[](const std::string& line) { return Rucksack(line.begin(), line.end()); }
		);

		return rucksacks;
	}
}
