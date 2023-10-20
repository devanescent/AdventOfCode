#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day14
{
	// ---------------------------------------------------------------------------
	// Day14: Disk Defragmentation
	// ---------------------------------------------------------------------------
	class DiskDefragmentation : public Day
	{
	public:
		DiskDefragmentation();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
