#include "Day02_Dive.h"
#include <numeric>

namespace AdventOfCode::Year2021::Day02
{
	Dive::Dive() : DayT(2, "Dive!") {}

	uint64_t Dive::ExecutePart1(std::vector<DiveCmd> course)
	{
		// Calculate values of all commands together:
		DivePos initialPos;
		DivePos resultPos = std::accumulate(course.begin(), course.end(), initialPos,
			[](DivePos& pos, const DiveCmd& dCmd)
			{
				switch (dCmd.Dir)
				{
				// Forward: increase only horizontal position:
				case DiveCmdDirection::Forward:
					pos.HorizontalPosition += dCmd.Value;
					return pos;

				// Up / Down: decrease / increase depth:
				case DiveCmdDirection::Up:
					pos.Depth -= dCmd.Value;
					return pos;

				case DiveCmdDirection::Down:
					pos.Depth -= dCmd.Value;
					return pos;
				}

				return pos;
			}
		);

		// Get result from total horizontal position and depth:
		return static_cast<unsigned long long>(resultPos.HorizontalPosition) * resultPos.Depth;
	}

	uint64_t Dive::ExecutePart2(std::vector<DiveCmd> course)
	{
		DivePos initialPos;
		DivePos resultPos = std::accumulate(course.begin(), course.end(), initialPos,
			[](DivePos& pos, const DiveCmd& dCmd)
			{
				switch (dCmd.Dir)
				{
					// Forward: increase only horizontal position:
					case DiveCmdDirection::Forward:
						pos.HorizontalPosition += dCmd.Value;
						pos.Depth += pos.Aim * dCmd.Value;
						return pos;

					// Up / Down: decrease / increase depth:
					case DiveCmdDirection::Up:
						pos.Aim -= dCmd.Value;
						return pos;

					case DiveCmdDirection::Down:
						pos.Aim += dCmd.Value;
						return pos;
				}

				return pos;
			}
		);

		// Get result from total horizontal position and depth:
		return static_cast<unsigned long long>(resultPos.HorizontalPosition) * resultPos.Depth;
	}
}
