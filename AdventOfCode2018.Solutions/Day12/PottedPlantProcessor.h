#pragma once
#include "InputProcessorWithContext.h"
#include <deque>
#include <map>

namespace AdventOfCode::Year2018::Day12
{
	using Pot = char;
	using PotRow = std::string;
	using PotPattern = std::string;
	using PlantRules = std::map<PotPattern, bool, std::less<>>;

	class PottedPlantProcessor : public InputProcessorWithContextBase<Pot, PlantRules, PotRow>
	{
	public:
		std::pair<PotRow, PlantRules> Process(std::vector<std::string> input) override;
	};
}