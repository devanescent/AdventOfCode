#pragma once
#include "InputProcessor.h"
#include "ClayVein.h"

namespace AdventOfCode::Year2018::Day17
{
	class ClayVeinProcessor : public InputProcessorBase<ClayVein>
	{
	public:
		std::vector<ClayVein> Process(std::vector<std::string> input) override;
	};
}