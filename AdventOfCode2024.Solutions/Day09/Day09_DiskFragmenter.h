#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Disk Fragmenter
	// ---------------------------------------------------------------------------
	class DiskFragmenter : public Day<>
	{
	public:
		DiskFragmenter();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
