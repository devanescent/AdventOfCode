#include "Day02_Dive.h"
#include <numeric>

namespace AdventOfCode::Year2021::Day02
{
	Dive::Dive() : DayT(2, "Dive!") {}

	uint64_t Dive::ExecutePart1(std::vector<DiveCmd> course)
	{
		// Calculate values of all commands together:
		DivePos resultPos = std::accumulate(course.begin(), course.end(), DivePos(),
			[](DivePos pos, const DiveCmd& dCmd)
			{
				switch (dCmd.Dir)
				{
				// Forward: increase only horizontal position:
				case DiveCmdDirection::Forward:
					return DivePos(pos.HorizontalPosition + dCmd.Value, pos.Depth);
					break;

				// Up / Down: decrease / increase depth:
				case DiveCmdDirection::Up:
					return DivePos(pos.HorizontalPosition, pos.Depth - dCmd.Value);
					break;
				case DiveCmdDirection::Down:
					return DivePos(pos.HorizontalPosition, pos.Depth + dCmd.Value);
					break;
				default:
					break;
				}

				return pos;
			});

		// Get result from total horizontal position and depth:
		return static_cast<unsigned long long>(resultPos.HorizontalPosition) * resultPos.Depth;
	}
}
