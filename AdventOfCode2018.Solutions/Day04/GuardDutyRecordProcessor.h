#pragma once
#include "InputProcessor.h"
#include "GuardDutyRecord.h"
#include <memory>

namespace AdventOfCode::Year2018::Day04
{
	class GuardDutyRecordProcessor : public InputProcessorBase<std::unique_ptr<GuardDutyRecord>>
	{
	public:
		std::vector<std::unique_ptr<GuardDutyRecord>> Process(std::vector<std::string> input) override;
	};
}

