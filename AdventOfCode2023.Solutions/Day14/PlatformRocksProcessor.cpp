#include "PlatformRocksProcessor.h"
#include "Point.h"

namespace AdventOfCode::Year2023::Day14
{
	std::pair<std::vector<Rock>, Platform> PlatformRocksProcessor::Process(std::vector<std::string> input)
	{
		Platform platform;
		platform.Height = input.size();
		platform.Width = input[0].length();
		
		std::vector<Rock> rocks;

		for (int y = 0; y < input.size(); ++y)
		{
			for (int x = 0; x < input[y].length(); ++x)
			{
				if (input[y][x] != '.')
				{
					rocks.emplace_back(
						Point<int>{ x,y }, 
						input[y][x] == '#' ? RockType::Cube : RockType::Round
					);
				}
			}
		}

		return std::make_pair(rocks, platform);
	}
}
