#include "GalaxyMapProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2023::Day11
{
	std::pair<std::vector<Point<uint64_t>>, SpaceExpansions> GalaxyMapProcessor::Process(std::vector<std::string> input)
	{
		SpaceExpansions expansions;

		// Empty cols:
		for (int col = 0; col < input[0].size(); ++col)
		{
			bool isEmptyCol = std::all_of(input.begin(), input.end(),
				[col](const std::string& row) { return row[col] == '.'; });

			if (isEmptyCol)
				expansions.ExpandedCols.push_back(col);
		}

		// Empty rows:
		for (int row = 0; row < input.size(); ++row)
		{
			bool isEmptyRow = std::all_of(input[row].begin(), input[row].end(),
				[](char c) { return c == '.'; });

			if (isEmptyRow)
				expansions.ExpandedRows.push_back(row);
		}
		
		// Find galaxies:
		std::vector<Point<uint64_t>> galaxies;

		for (int y = 0; y < input.size(); ++y)
		{
			for (int x = 0; x < input[y].size(); ++x)
			{
				if (input[y][x] == '#')
					galaxies.emplace_back(x, y);
			}
		}

		return std::make_pair(galaxies, expansions);
	}
}
