#pragma once
#include "InputProcessorWithContext.h"
#include "PottedPlants.h"
#include <deque>
#include <map>

namespace AdventOfCode::Year2018::Day12
{
	class PottedPlantProcessor : public InputProcessorWithContextBase<PottedPlant, std::map<std::string, bool>, std::deque<PottedPlant>>
	{
	public:
		std::pair<std::deque<PottedPlant>, std::map<std::string, bool>> Process(std::vector<std::string> input) override;
	};
}