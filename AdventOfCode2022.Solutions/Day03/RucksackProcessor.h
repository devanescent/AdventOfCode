#pragma once
#include "InputProcessor.h"
#include "Rucksack.h"

namespace AdventOfCode::Year2022::Day03
{
	class RucksackProcessor : public InputProcessorBase<Rucksack>
	{
	public:
		std::vector<Rucksack> Process(std::vector<std::string> input) override;
	};
}
