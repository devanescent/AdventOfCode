#pragma once
#include <algorithm>
#include <vector>

namespace AdventOfCode::Year2023::Day11
{
	class SpaceExpansions
	{
	public:
		std::vector<int> ExpandedRows;
		std::vector<int> ExpandedCols;

		void ExpandGalaxy(Point<uint64_t>& galaxy, uint64_t expansionFactor) const
		{
			uint64_t xExpansions = std::count_if(
				ExpandedCols.begin(),
				ExpandedCols.end(),
				[&galaxy](int col) { return col < galaxy.X; });

			uint64_t yExpansions = std::count_if(
				ExpandedRows.begin(),
				ExpandedRows.end(),
				[&galaxy](int row) { return row < galaxy.Y; });

			galaxy = galaxy.MoveBy(xExpansions * (expansionFactor - 1), yExpansions * (expansionFactor - 1));
		}
	};
}
