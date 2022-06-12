#pragma once
#include "InputProcessor.h"
#include "RectangleClaim.h"

namespace AdventOfCode::Year2018::Day03
{
	class RectangleClaimProcessor : public InputProcessorBase<RectangleClaim>
	{
	public:
		std::vector<RectangleClaim> Process(std::vector<std::string> input) override;
	};
}

