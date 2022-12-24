#pragma once
#include "InputProcessor.h"
#include "Blizzard.h"

namespace AdventOfCode::Year2022::Day24
{
	class BlizzardProcessor : public InputProcessorBase<Blizzard>
	{
	public:
		std::vector<Blizzard> Process(std::vector<std::string> input) override;
	};
}
