#include "InitializationProcessor.h"
#include <algorithm>
#include <regex>

namespace AdventOfCode::Year2020::Day14
{
	std::pair<std::vector<InitializationInstruction>, InitializationContext> InitializationProcessor::Process(std::vector<std::string> input)
	{
		uint64_t bitmask_set = 0;
		uint64_t bitmask_clear = 0;

		std::vector<InitializationInstruction> instrs;

		if (!input.empty())
		{
			// setmask:
			std::string mask = input[0];
			std::replace(mask.begin(), mask.end(), 'X', '0');
			bitmask_set = std::strtoul(mask.c_str() + 7, nullptr, 2);	// +7: ignore the "mask = " part at the beginning

			// clearmask:
			mask = input[0];
			std::replace(mask.begin(), mask.end(), 'X', '1');
			bitmask_clear = std::strtoul(mask.c_str() + 7, nullptr, 2);

			// instructions:
			std::regex instrPattern = std::regex("mem\\[([0-9]+)\\] = ([0-9]+)");
			std::smatch matches;

			// Iterate instructions from end, because later instructions on the same memory address 
			// overwrite previous instructions (which therefore do not need to be processed)
			for (auto it = input.rbegin(); it != input.rend() - 1; ++it)
			{
				// Number of matches == 3: the whole string plus the two capture groups
				if (std::regex_search(*it, matches, instrPattern) && matches.size() == 3)
				{
					int addr = atoi(matches[1].str().c_str());
					int val = atoi(matches[2].str().c_str());

					// only add instruction if there is no instruction at this memory address yet:
					if (std::find_if(instrs.begin(), instrs.end(), [addr](const InitializationInstruction& ins) { return ins.GetAddress() == addr; }) == instrs.end())
						instrs.push_back(InitializationInstruction(addr, val));
				}
			}
		}
		
		return std::make_pair(instrs, InitializationContext(bitmask_set, bitmask_clear));
	}
}

