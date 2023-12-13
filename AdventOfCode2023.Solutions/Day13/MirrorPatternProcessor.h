#pragma once
#include "InputProcessor.h"
#include "MirrorPattern.h"

namespace AdventOfCode::Year2023::Day13
{
	class MirrorPatternProcessor : public InputProcessorBase<MirrorPattern>
	{
	public:
		std::vector<MirrorPattern> Process(std::vector<std::string> input) override;
	};
}
