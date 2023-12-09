#pragma once
#include "InputProcessor.h"
#include "ValueHistory.h"

namespace AdventOfCode::Year2023::Day09
{
	class ValueHistoryProcessor : public InputProcessorBase<ValueHistory>
	{
	public:
		std::vector<ValueHistory> Process(std::vector<std::string> input) override;
	};
}
