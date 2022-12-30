#pragma once
#include "InputProcessor.h"
#include "Blueprint.h"

namespace AdventOfCode::Year2022::Day19
{
	class BlueprintProcessor : public InputProcessorBase<Blueprint>
	{
	public:
		std::vector<Blueprint> Process(std::vector<std::string> input) override;
	};
}
