#pragma once
#include "InputProcessorWithContext.h"
#include "ShuttleLine.h"

namespace AdventOfCode::Year2020::Day13
{
	class ShuttleLineProcessor : public InputProcessorWithContextBase<ShuttleLine, int>
	{
	public:
		std::pair<std::vector<ShuttleLine>, int> Process(std::vector<std::string> input) override;
	};
}


