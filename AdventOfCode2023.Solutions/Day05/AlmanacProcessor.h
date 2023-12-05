#pragma once
#include "InputProcessorWithContext.h"
#include "SeedMapping.h"
#include "SeedList.h"

namespace AdventOfCode::Year2023::Day05
{
	class AlmanacProcessor : public InputProcessorWithContextBase<SeedMapping, std::vector<uint64_t>>
	{
	public:
		std::pair<std::vector<SeedMapping>, std::vector<uint64_t>> Process(std::vector<std::string> input) override;
	};
}
