#pragma once
#include <stack>
#include "InputProcessorWithContext.h"
#include "CraneStep.h"

namespace AdventOfCode::Year2022::Day05
{
	using Crate = char;
	using CrateStacks = std::vector<std::stack<Crate>>;

	class CraneStepProcessor : public InputProcessorWithContextBase<CraneStep, CrateStacks>
	{
	public:
		std::pair<std::vector<CraneStep>, CrateStacks> Process(std::vector<std::string> input) override;
	};
}
