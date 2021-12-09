#pragma once
#include "InputProcessor.h"
#include "AnswerSet.h"

namespace AdventOfCode::Year2020::Day06
{
	class AnswerProcessor : public InputProcessorBase<AnswerSet>
	{
	public:
		std::vector<AnswerSet> Process(std::vector<std::string> input) override;
	};
}

