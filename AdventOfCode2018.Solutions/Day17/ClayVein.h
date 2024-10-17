#pragma once
#include "Range.h"

namespace AdventOfCode::Year2018::Day17
{
	struct ClayVein
	{
		ClayVein(int x1, int x2, int y1, int y2) :
			XRange(x1, x2), YRange(y1, y2)
		{ }

		Range<int> XRange;
		Range<int> YRange;
	};
}