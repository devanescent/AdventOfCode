#pragma once
#include "InputProcessor.h"
#include "Valve.h"
#include <map>

namespace AdventOfCode::Year2022::Day16
{
	class ValveProcessor : public InputProcessorBase<Valve, std::map<std::string, Valve>>
	{
	public:
		std::map<std::string, Valve> Process(std::vector<std::string> input) override;
	};
}
