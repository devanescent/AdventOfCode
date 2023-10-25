#pragma once
#include "InputProcessorWithContext.h"
#include "Blueprint.h"
#include "BlueprintInitializer.h"

namespace AdventOfCode::Year2017::Day25
{
	class BlueprintsProcessor : public InputProcessorWithContextBase<Blueprint, BlueprintInitializer>
	{
	public:
		std::pair<std::vector<Blueprint>, BlueprintInitializer> Process(std::vector<std::string> input) override;
	};
}
