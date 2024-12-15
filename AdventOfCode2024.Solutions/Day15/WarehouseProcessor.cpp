#include "WarehouseProcessor.h"

namespace AdventOfCode::Year2024::Day15
{
	std::pair<std::vector<Point<int>>, GridMap> WarehouseProcessor::Process(std::vector<std::string> input)
	{
		// Find empty line separating map and movements
		auto sepIt = std::find(input.begin(), input.end(), "");

		// Movements:
		std::vector<Point<int>> movements;
		auto movIt = sepIt + 1;
		while (movIt != input.end())
		{
			for (char c : *movIt)
			{
				switch (c)
				{
					case '^': movements.emplace_back(Point<int>::Up()); break;
					case '>': movements.emplace_back(Point<int>::Right()); break;
					case 'v': movements.emplace_back(Point<int>::Down()); break;
					case '<': movements.emplace_back(Point<int>::Left()); break;
				}
			}
			++movIt;
		}

		return std::make_pair(std::move(movements), GridMap(input.begin(), sepIt));
	}
}
