#include "Day08_IHeardYouLikeRegisters.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2017::Day08
{
	IHeardYouLikeRegisters::IHeardYouLikeRegisters() : DayT(8, "I Heard You Like Registers") { }

	uint64_t IHeardYouLikeRegisters::ExecutePart1(std::vector<RegisterInstruction> instructions)
	{
		std::map<std::string, int> registers;

		// Execute instructions:
		for (const auto& instr : instructions)
		{
			if (instr.CheckCondition(registers[instr.CompRegName]))
			{
				switch (instr.Modification)
				{
					case RegisterModification::Increase:
						registers[instr.Name] += instr.Value;
						break;
					case RegisterModification::Decrease:
						registers[instr.Name] -= instr.Value;
						break;
				}
			}
		}

		// Find largest value:
		auto maxRegIt = std::max_element(registers.begin(), registers.end(),
			[](const std::pair<const std::string, int>& reg1, const std::pair<const std::string, int>& reg2)
			{
				// Compare register values:
				return reg1.second < reg2.second;
			});

		return maxRegIt->second;
	}

	uint64_t IHeardYouLikeRegisters::ExecutePart2(std::vector<RegisterInstruction> instructions)
	{
		std::map<std::string, int> registers;
		uint64_t maxRegValue = 0;

		// Execute instructions:
		for (const auto& instr : instructions)
		{
			if (instr.CheckCondition(registers[instr.CompRegName]))
			{
				switch (instr.Modification)
				{
				case RegisterModification::Increase:
					registers[instr.Name] += instr.Value;
					break;
				case RegisterModification::Decrease:
					registers[instr.Name] -= instr.Value;
					break;
				}

				// Keep track of largest value:
				auto maxRegIt = std::max_element(registers.begin(), registers.end(),
					[](const std::pair<const std::string, int>& reg1, const std::pair<const std::string, int>& reg2)
					{
						// Compare register values:
						return reg1.second < reg2.second;
					});

				maxRegValue = std::max(maxRegValue, (uint64_t)maxRegIt->second);
			}
		}

		return maxRegValue;
	}
}
