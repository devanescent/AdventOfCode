#pragma once
#include "InputProcessor.h"
#include "RaceRecord.h"

namespace AdventOfCode::Year2023::Day06
{
	class RaceRecordsProcessor : public InputProcessorBase<RaceRecord>
	{
	public:
		std::vector<RaceRecord> Process(std::vector<std::string> input) override;
	};
}
