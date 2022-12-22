#include "MonkeyMathProcessor.h"
#include <sstream>
#include <algorithm>

namespace AdventOfCode::Year2022::Day21
{
	std::map<std::string, YellingMonkey> MonkeyMathProcessor::Process(std::vector<std::string> input)
	{
		std::map<std::string, YellingMonkey> monkeys;

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			std::string monkeyName;

			iss >> monkeyName;
			monkeyName.pop_back(); // remove ":"

			YellingMonkey mm;
			iss >> mm.Operand1 >> mm.Operation >> mm.Operand2;

			// If only a single value is given, set result:
			if (std::all_of(mm.Operand1.begin(), mm.Operand1.end(), std::isdigit))
				mm.Result = stoull(mm.Operand1);

			monkeys.emplace(std::move(monkeyName), std::move(mm));
		}

		return monkeys;
	}
}
