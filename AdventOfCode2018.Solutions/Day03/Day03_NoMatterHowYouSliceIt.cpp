#include "Day03_NoMatterHowYouSliceIt.h"
#include "RectangleSweep.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day03
{
	NoMatterHowYouSliceIt::NoMatterHowYouSliceIt() : DayT(3, "No matter how you slice it")
	{}

	uint64_t NoMatterHowYouSliceIt::ExecutePart1(std::vector<RectangleClaim> claims)
	{
		return SweepClaims(claims);
	}

	uint64_t NoMatterHowYouSliceIt::ExecutePart2(std::vector<RectangleClaim> claims)
	{
		SweepClaims(claims);
		auto nonOverlapping = std::find_if(claims.begin(), claims.end(), [](const RectangleClaim& rc)
		{
			return !rc.Overlapping;
		});

		return nonOverlapping->ID();
	}
}
