#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day14
{
	// ---------------------------------------------------------------------------
	// Day14: Disk Defragmentation
	// ---------------------------------------------------------------------------
	class DiskDefragmentation : public Day<>
	{
	public:
		DiskDefragmentation();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
