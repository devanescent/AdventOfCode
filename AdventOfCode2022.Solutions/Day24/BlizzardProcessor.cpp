#include "BlizzardProcessor.h"

namespace AdventOfCode::Year2022::Day24
{
	int Blizzard::XMax;
	int Blizzard::YMax;

	std::vector<Blizzard> BlizzardProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Blizzard> blizzards;

		Blizzard::YMax = input.size() - 2;
		Blizzard::XMax = input[0].size() - 2;

		// Ignore outer border during processing:
		for (auto y = 1; y < input.size() - 1; ++y)
		{
			for (auto x = 1; x < input[y].size() - 1; ++x)
			{
				switch (input[y][x])
				{
					case '>': blizzards.emplace_back(Direction::Right, Point<int>{ x,y }); break;
					case '<': blizzards.emplace_back(Direction::Left, Point<int>{ x, y }); break;
					case '^': blizzards.emplace_back(Direction::Up, Point<int>{ x, y }); break;
					case 'v': blizzards.emplace_back(Direction::Down, Point<int>{ x, y }); break;
				}
			}
		}

		return blizzards;
	}
}
