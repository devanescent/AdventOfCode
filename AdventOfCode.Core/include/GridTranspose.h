#pragma once
#include <vector>

namespace AdventOfCode
{
	template <typename T>
	std::vector<T> transpose(const std::vector<T>& grid)
	{
		if (grid.empty())
			return grid;

		auto gridHeight = grid.size();
		auto gridWidth = grid[0].size();

		std::vector<T> transposedGrid;
		for (auto col = 0; col < gridWidth; ++col)
		{
			T colToRow;
			for (auto row = 0; row < gridHeight; ++row)
				colToRow.push_back(grid[row][col]);

			transposedGrid.push_back(colToRow);
		}

		return transposedGrid;
	}
}