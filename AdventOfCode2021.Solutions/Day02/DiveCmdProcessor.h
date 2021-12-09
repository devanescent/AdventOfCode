#pragma once
#include "DiveCmd.h"
#include "InputProcessor.h"

namespace AdventOfCode::Year2021::Day02
{
	class DiveCmdProcessor : public InputProcessorBase<DiveCmd>
	{
	public:
		std::vector<DiveCmd> Process(std::vector<std::string> input) override;
	};
}
