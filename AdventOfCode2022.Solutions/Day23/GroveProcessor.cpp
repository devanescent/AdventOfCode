#include "GroveProcessor.h"

namespace AdventOfCode::Year2022::Day23
{
	std::vector<Elf> GroveProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Elf> elves;

		for (auto y = 0; y < input.size(); ++y)
		{
			for (auto x = 0; x < input[y].size(); ++x)
			{
				if (input[y][x] == '#')
					elves.emplace_back(x, y);
			}
		}

		return elves;
	}
}
