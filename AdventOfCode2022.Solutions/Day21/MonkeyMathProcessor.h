#pragma once
#include "InputProcessor.h"
#include "YellingMonkey.h"
#include <map>

namespace AdventOfCode::Year2022::Day21
{
	class MonkeyMathProcessor : public InputProcessorBase<YellingMonkey, std::map<std::string, YellingMonkey>>
	{
	public:
		std::map<std::string, YellingMonkey> Process(std::vector<std::string> input) override;
	};
}
