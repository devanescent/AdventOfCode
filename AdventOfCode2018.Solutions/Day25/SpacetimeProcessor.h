#pragma once
#include "InputProcessor.h"
#include "SpacetimeFixpoint.h"

namespace AdventOfCode::Year2018::Day25
{
	class SpacetimeProcessor : public InputProcessorBase<SpacetimeFixpoint>
	{
	public:
		std::vector<SpacetimeFixpoint> Process(std::vector<std::string> input) override;
	};
}