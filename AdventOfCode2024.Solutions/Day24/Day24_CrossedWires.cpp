#include "Day24_CrossedWires.h"
#include <map>
#include <set>

namespace AdventOfCode::Year2024::Day24
{
	CrossedWires::CrossedWires() : DayTC(24, "Crossed Wires") { }

	int GetWireValue(const std::string& wire, const std::map<std::string, LogicGate>& outputs, WireInputs& knownInputs)
	{
		auto knownWire = knownInputs.find(wire);
		if (knownWire != knownInputs.end())
			return knownWire->second;
		else
		{
			auto gate = outputs.find(wire);
			if (gate == outputs.end())
				return 0;
			else
			{
				auto input1 = GetWireValue(gate->second.Input1, outputs, knownInputs);
				auto input2 = GetWireValue(gate->second.Input2, outputs, knownInputs);
				
				int outputValue = 0;
				switch (gate->second.Type)
				{
					case LogicGateType::AND:
						outputValue = (int)(input1 && input2);
						break;
					case LogicGateType::OR:
						outputValue = (int)(input1 || input2);
						break;
					case LogicGateType::XOR:
						outputValue = (int)(input1 != input2);
						break;
				}

				knownInputs[wire] = outputValue;
				return outputValue;
			}
		}
	}

	uint64_t CrossedWires::ExecutePart1(std::vector<LogicGate> logicGates, WireInputs inputs)
	{
		// Create a map of all output values, also keep a list of all output wires (starting with 'z'):
		std::map<std::string, LogicGate> outputMap;
		
		// std::set<> sorts output wires in correct order:
		std::set<std::string> zOutputs;

		for (const auto& gate : logicGates)
		{
			outputMap[gate.Output] = gate;
			if (gate.Output[0] == 'z')
				zOutputs.insert(gate.Output);
		}

		// Get output values:
		std::string binaryOutput;
		for (const auto& zWire : zOutputs)
			binaryOutput += std::to_string(GetWireValue(zWire, outputMap, inputs));

		// Change order to MSB first:
		std::reverse(binaryOutput.begin(), binaryOutput.end());

		// Convert to number:
		return std::stoull(binaryOutput, nullptr, 2);
	}

	std::string CrossedWires::ExecutePart2(std::vector<LogicGate> logicGates, WireInputs inputs)
	{
		return {};
	}
}
