#include "Day13_PointOfIncidence.h"
#include <numeric>

namespace AdventOfCode::Year2023::Day13
{
	PointOfIncidence::PointOfIncidence() : DayT(13, "Point of Incidence") { }

	uint64_t PointOfIncidence::ExecutePart1(std::vector<MirrorPattern> mirrorPatterns)
	{
		return std::accumulate(mirrorPatterns.begin(), mirrorPatterns.end(), 0ull,
			[](uint64_t sum, const MirrorPattern& pattern)
			{
				int cols, rows;

				if (pattern.FindVerticalMirror(0, cols))
					return sum + cols;
				else if (pattern.FindHorizontalMirror(0, rows))
					return sum + rows * 100;
				else
					return sum;
			});
	}

	uint64_t PointOfIncidence::ExecutePart2(std::vector<MirrorPattern> mirrorPatterns)
	{
		return std::accumulate(mirrorPatterns.begin(), mirrorPatterns.end(), 0ull,
			[](uint64_t sum, const MirrorPattern& pattern)
			{
				int cols, rows;

				if (pattern.FindVerticalMirror(1, cols))
					return sum + cols;
				else if (pattern.FindHorizontalMirror(1, rows))
					return sum + rows * 100;
				else
					return sum;
			});
	}
}
