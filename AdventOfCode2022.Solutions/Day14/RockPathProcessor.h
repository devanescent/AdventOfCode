#pragma once
#include "InputProcessor.h"
#include "RockPath.h"

namespace AdventOfCode::Year2022::Day14
{
	class RockPathProcessor : public InputProcessorBase<RockPath>
	{
	public:
		std::vector<RockPath> Process(std::vector<std::string> input) override;
	};
}
