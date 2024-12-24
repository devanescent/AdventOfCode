#pragma once
#include "InputProcessorWithContext.h"
#include "LogicGate.h"
#include <map>

namespace AdventOfCode::Year2024::Day24
{
	using WireInputs = std::map<std::string, int>;

	class LogicGateProcessor : public InputProcessorWithContextBase<LogicGate, WireInputs>
	{
	public:
		std::pair<std::vector<LogicGate>, WireInputs> Process(std::vector<std::string> input) override;
	};
}
