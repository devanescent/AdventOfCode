#include "Day10_HoofIt.h"
#include <stack>
#include <map>
#include <set>
#include "Point.h"
#include "CharDigitConverter.h"

namespace AdventOfCode::Year2024::Day10
{
	HoofIt::HoofIt() : Day(10, "Hoof It") { }

	uint64_t HoofIt::ExecutePart1(std::vector<std::string> input)
	{
		// Trail heads:
		std::vector<Point<int>> heads;

		auto mapWidth = input[0].size();
		auto mapHeight = input.size();

		for (int y = 0; y < mapHeight; ++y)
		{
			for (int x = 0; x < mapWidth; ++x)
			{
				if (input[y][x] == '0')
				{
					heads.emplace_back(x, y);
				}
			}
		}

		// List each trail end for each start position:
		std::map<Point<int>, std::set<Point<int>>> hikingTrails;

		for (const auto& head : heads)
		{
			// Find all trail paths from this trail head:
			std::stack<Point<int>> paths;
			paths.push(head);

			while (!paths.empty())
			{
				auto pos = paths.top();
				paths.pop();

				char height = input[pos.Y][pos.X];

				if (height == '9')
				{
					// End of trail reached:
					hikingTrails[head].insert(pos);
					continue;
				}

				// Find next possible path options
				auto nextOptions = pos.GetSurroundingPoints(false);
				for (const auto& n : nextOptions)
				{
					if (n.IsXBetween(0, mapWidth - 1) && n.IsYBetween(0, mapHeight - 1) && input[n.Y][n.X] == height + 1)
					{
						paths.push(n);
					}
				}
			}
		}

		// Score is number of trail ends reachable from the trail head:
		uint64_t score = 0;
		for (auto& [_, ends] : hikingTrails)
		{
			score += ends.size();
		}

		return score;
	}

	uint64_t HoofIt::ExecutePart2(std::vector<std::string> input)
	{
		// Start a list of possible paths:
		std::stack<Point<int>> paths;

		auto mapWidth = input[0].size();
		auto mapHeight = input.size();

		for (int y = 0; y < mapHeight; ++y)
		{
			for (int x = 0; x < mapWidth; ++x)
			{
				if (input[y][x] == '0')
				{
					paths.emplace(x, y);
				}
			}
		}

		uint64_t trailHeadScores = 0;

		while (!paths.empty())
		{
			auto pos = paths.top();
			paths.pop();

			char height = input[pos.Y][pos.X];

			if (height == '9')
			{
				// Count all paths found:
				++trailHeadScores;
				continue;
			}

			auto nextOptions = pos.GetSurroundingPoints(false);
			for (const auto& n : nextOptions)
			{
				if (n.IsXBetween(0, mapWidth - 1) && n.IsYBetween(0, mapHeight - 1) && input[n.Y][n.X] == height + 1)
				{
					paths.push(n);
				}
			}
		}

		return trailHeadScores;
	}
}
