#pragma once
#include "InputProcessor.h"
#include "TowerProgram.h"

namespace AdventOfCode::Year2017::Day07
{
	class TowerProgramProcessor : public InputProcessorBase<TowerProgram>
	{
	public:
		std::vector<TowerProgram> Process(std::vector<std::string> input) override;
	};
}
