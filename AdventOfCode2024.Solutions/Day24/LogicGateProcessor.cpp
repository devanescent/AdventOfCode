#include "LogicGateProcessor.h"
#include "CharDigitConverter.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day24
{
	std::pair<std::vector<LogicGate>, WireInputs> LogicGateProcessor::Process(std::vector<std::string> input)
	{
		WireInputs inputs;

		// Every wire name is three characters long:
		auto lineIt = input.begin();
		for (; !lineIt->empty(); ++lineIt)
		{
			inputs[lineIt->substr(0, 3)] = CharToDigit<int>(lineIt->back());
		}

		++lineIt;
		std::vector<LogicGate> gates;
		for (; lineIt != input.end(); ++lineIt)
		{
			std::istringstream iss(*lineIt);
			LogicGate gate;
			std::string gateTypeStr, arrow;

			iss >> gate.Input1 >> gateTypeStr >> gate.Input2 >> arrow >> gate.Output;
			if (gateTypeStr == "AND")
				gate.Type = LogicGateType::AND;
			else if (gateTypeStr == "OR")
				gate.Type = LogicGateType::OR;
			else if (gateTypeStr == "XOR")
				gate.Type = LogicGateType::XOR;

			gates.emplace_back(gate);
		}

		return std::make_pair(gates, inputs);
	}
}
