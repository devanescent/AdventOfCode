#include "Day10_HoofIt.h"
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include "Point.h"
#include "CharDigitConverter.h"

namespace AdventOfCode::Year2024::Day10
{
	HoofIt::HoofIt() : DayT(10, "Hoof It") { }

	std::map<Point<int>, std::vector<Point<int>>> FindAllTrails(const GridMap& map, const std::vector<Point<int>>& heads)
	{
		std::map<Point<int>, std::vector<Point<int>>> hikingTrails;
		for (const auto& head : heads)
		{
			// Find all trail paths from this trail head:
			std::stack<Point<int>> paths;
			paths.push(head);

			while (!paths.empty())
			{
				auto pos = paths.top();
				paths.pop();

				char height = map.Get(pos);
				if (height == '9')
				{
					// End of trail reached:
					hikingTrails[head].push_back(pos);
				}
				else
				{
					// Find next possible path options
					auto nextOptions = pos.GetSurroundingPoints(false);
					for (const auto& n : nextOptions)
					{
						if (map.Contains(n) && map.Get(n) == height + 1)
						{
							paths.push(n);
						}
					}
				}
			}
		}

		return hikingTrails;
	}

	uint64_t HoofIt::ExecutePart1(GridMap map)
	{
		// Trail heads:
		std::vector<Point<int>> heads;
		map.Find(std::back_inserter(heads), '0');

		// List each trail end for each start position:
		auto hikingTrails = FindAllTrails(map, heads);

		// Score is unique number of trail ends reachable from the trail head:
		uint64_t score = 0;
		for (auto& [_, ends] : hikingTrails)
		{
			// Count only unique ends:
			std::sort(ends.begin(), ends.end());
			auto uniqueEnds = std::distance(ends.begin(), std::unique(ends.begin(), ends.end()));

			score += (uint64_t)uniqueEnds;
		}

		return score;
	}

	uint64_t HoofIt::ExecutePart2(GridMap map)
	{
		// Trail heads:
		std::vector<Point<int>> heads;
		map.Find(std::back_inserter(heads), '0');

		// List each trail end for each start position:
		auto hikingTrails = FindAllTrails(map, heads);

		// Score is total number of trail ends reachable from the trail head:
		uint64_t score = 0;
		for (const auto& [_, ends] : hikingTrails)
			score += ends.size();

		return score;
	}
}
