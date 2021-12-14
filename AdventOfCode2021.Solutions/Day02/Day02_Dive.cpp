#include "Day02_Dive.h"
#include <algorithm>

namespace AdventOfCode::Year2021::Day02
{
	Dive::Dive() : DayT(2, "Dive!") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t Dive::ExecutePart1(std::vector<DiveCmd> course)
	{
		// Use simple positioning:
		DivePos resultPos;
		ApplyCourse(course, resultPos);

		// Get result from total horizontal position and depth:
		return static_cast<uint64_t>(resultPos.HorizontalPosition) * resultPos.Depth;
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t Dive::ExecutePart2(std::vector<DiveCmd> course)
	{
		// Use extended positioning:
		DivePosEx resultPos;
		ApplyCourse(course, resultPos);

		// Get result from total horizontal position and depth:
		return static_cast<uint64_t>(resultPos.HorizontalPosition) * resultPos.Depth;
	}

	// ---------------------------------------------------------------------------
	// ApplyCourse
	// Apply all given commands to the passed initial position
	// ---------------------------------------------------------------------------
	void Dive::ApplyCourse(const std::vector<DiveCmd>& course, DivePos& initialPos)
	{
		// Apply all of the commands:
		std::for_each(course.cbegin(), course.cend(), [&initialPos](const DiveCmd& dCmd) { initialPos.ApplyDiveCmd(dCmd); });
	}
}
