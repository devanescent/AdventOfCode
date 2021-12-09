#include "CubeProcessor.h"

namespace AdventOfCode::Year2020::Day17
{
	std::vector<CubeCoords> CubeProcessor::Process(std::vector<std::string> input)
	{
		std::vector<CubeCoords> activeCubes;

		for (int y = 0; y < static_cast<int>(input.size()); ++y)
		{
			for (int x = 0; x < static_cast<int>(input[y].length()); ++x)
			{
				if (input[y][x] == '#')
					activeCubes.push_back(CubeCoords(x, y, 0));
			}
		}

		return activeCubes;
	}
}


