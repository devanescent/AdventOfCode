#include "GridComputingClusterProcessor.h"

namespace AdventOfCode::Year2017::Day22
{
	std::pair<std::vector<Point<int>>, Point<int>>  GridComputingClusterProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<Point<int>>, Point<int>> result;
		std::vector<Point<int>>& infectedNodes = result.first;

		for (int y = 0; y < input.size(); ++y)
		{
			for (int x = 0; x < input[y].size(); ++x)
			{
				if (input[y][x] == '#')
					infectedNodes.emplace_back(x, y);
			}
		}

		Point<int>& initialPos = result.second;
		initialPos.X = input[0].size() / 2;
		initialPos.Y = input.size() / 2;

		return result;
	}
}
