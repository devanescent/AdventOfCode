#include "Day16_ChronalClassification.h"
#include <algorithm>
#include <map>
#include <set>

namespace AdventOfCode::Year2018::Day16
{
	ChronalClassification::ChronalClassification() : DayTC(16, "Chronal Classification") {}

	uint64_t ChronalClassification::ExecutePart1(std::vector<ComputationSample> samples, std::vector<Instruction>)
	{
		return std::count_if(samples.begin(), samples.end(), [](const auto& sample) { return sample.GetValidOpCodes().size() >= 3; });
	}

	uint64_t ChronalClassification::ExecutePart2(std::vector<ComputationSample> samples, std::vector<Instruction> program)
	{
		// Assigns possible opcodes for each opcode value:
		std::map<int, std::set<OpCode>> opCodeOptions;

		for (const auto& sample : samples)
		{
			int numOpCode = sample.GetNumericOpCode();

			// Valid opcodes for this sample:
			auto validOpCodes = sample.GetValidOpCodes();

			// If no samples have been evaluated for this opcode value yet, assign the set:
			if (opCodeOptions[numOpCode].empty())
				opCodeOptions[numOpCode] = validOpCodes;
			else if (validOpCodes != opCodeOptions[numOpCode])
			{
				// Otherwise, intersect with the current set of valid opcodes:
				auto currentValidOpCodes = opCodeOptions[numOpCode]; // make copy
				opCodeOptions[numOpCode].clear();
				std::set_intersection(
					currentValidOpCodes.begin(), currentValidOpCodes.end(),
					validOpCodes.begin(), validOpCodes.end(),
					std::inserter(opCodeOptions[numOpCode], opCodeOptions[numOpCode].end())
				);
			}
		}

		// Evaluate solutions: maps each integer value to an opcode:
		std::map<int, OpCode> opCodeSolutions;
		while (!opCodeOptions.empty())
		{
			// Find an entry that has only one possible opcode:
			auto solved = std::find_if(opCodeOptions.begin(), opCodeOptions.end(), [](const auto& entry) { return entry.second.size() == 1; });
			if (solved == opCodeOptions.end())
				return 0ull; // not solvable...

			// Remove this solution from all other sets that contain more than one solution:
			OpCode actualOpCode = *solved->second.begin();
			for (auto& entry : opCodeOptions)
			{
				if (entry.second.size() > 1)
					entry.second.erase(actualOpCode);
			}

			// Add to solution set and remove from option set
			opCodeSolutions[solved->first] = actualOpCode;
			opCodeOptions.erase(solved);
		}

		// Update each instruction in program with the corresponding opcode and execute:
		Register<4> reg;
		for (Instruction& instr : program)
		{
			instr.SetCorrectOpCode(opCodeSolutions);
			instr.ApplyToRegister(reg);
		}

		return reg[0];
	}
}