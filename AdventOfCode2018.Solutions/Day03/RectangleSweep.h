#pragma once
#include "RectangleClaim.h"
#include <vector>

namespace AdventOfCode::Year2018::Day03
{
	struct LineSegment
	{
		LineSegment(int id, int start, int end) :
			ID(id), Start(start), End(end)
		{}

		int ID;
		int Start;
		int End;
		bool Overlapping = false;

		static bool CompareByStart(const LineSegment& a, const LineSegment& b)
		{
			return a.Start < b.Start;
		}

		static bool CompareByEnd(const LineSegment& a, const LineSegment& b)
		{
			return a.End < b.End;
		}
	};

	uint64_t SweepLines(std::vector<LineSegment>& lineSegments);
	uint64_t SweepClaims(std::vector<RectangleClaim>& claims);

}