#pragma once
#include "DayT.h"
#include "SectionAssignmentsProcessor.h"

namespace AdventOfCode::Year2022::Day04
{
	// ---------------------------------------------------------------------------
	// Day04: Camp Cleanup
	// ---------------------------------------------------------------------------
	class CampCleanup : public DayT<SectionAssignmentsProcessor>
	{
	public:
		CampCleanup();

	protected:
		uint64_t ExecutePart1(std::vector<SectionAssignments> sectionAssignments) override;
		uint64_t ExecutePart2(std::vector<SectionAssignments> sectionAssignments) override;
	};
}
