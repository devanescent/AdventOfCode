#pragma once
#include "InputProcessor.h"
#include "Army.h"

namespace AdventOfCode::Year2018::Day24
{
	class ArmyProcessor : public InputProcessorBase<Army>
	{
	public:
		std::vector<Army> Process(std::vector<std::string> input) override;
	};
}