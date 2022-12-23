#pragma once
#include "InputProcessor.h"
#include "Elf.h"

namespace AdventOfCode::Year2022::Day23
{
	class GroveProcessor : public InputProcessorBase<Elf>
	{
	public:
		std::vector<Elf> Process(std::vector<std::string> input) override;
	};
}
