#include "Day04_CampCleanup.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day04
{
	CampCleanup::CampCleanup() : DayT(4, "Camp Cleanup") { }

	uint64_t CampCleanup::ExecutePart1(std::vector<SectionAssignments> sectionAssignments)
	{
		return std::count_if(sectionAssignments.begin(), sectionAssignments.end(),
			[](const SectionAssignments& sectAssignments)
			{
				return sectAssignments.IsOneAssignmentFullyContained();
			});
	}

	uint64_t CampCleanup::ExecutePart2(std::vector<SectionAssignments> sectionAssignments)
	{
		return std::count_if(sectionAssignments.begin(), sectionAssignments.end(),
			[](const SectionAssignments& sectAssignments)
			{
				return sectAssignments.AssignmentsOverlap();
			});
	}
}
