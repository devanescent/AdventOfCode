#pragma once
#include "Range.h"
#include "Point.h"
#include <set>
#include <vector>

namespace AdventOfCode::Year2022::Day22
{
	class JungleMap
	{
	public:
		std::vector<Range<int>> XBounds; // Valid area on each row
		std::vector<Range<int>> YBounds; // Valid area on each column

		std::set<Point<int>> Walls;

		JungleMap(size_t height, size_t width) :
			XBounds(height, Range<int>{-1, 0}), YBounds(width, Range<int>{-1, 0})
		{}
	};
}
