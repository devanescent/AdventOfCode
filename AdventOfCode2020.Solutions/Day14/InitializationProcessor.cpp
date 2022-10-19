#include "InitializationProcessor.h"
#include <algorithm>
#include <regex>

namespace AdventOfCode::Year2020::Day14
{
	std::vector<InitializationInstruction> InitializationProcessor::Process(std::vector<std::string> input)
	{
		std::vector<InitializationInstruction> instrs;

		// Each intruction either updates the bitmask or writes a value to memory:
		for (const std::string& line : input)
		{
			auto startsWith = [](const std::string& s, const std::string& prefix) -> bool { return s.rfind(prefix, 0) == 0; };

			std::regex instrPattern = std::regex("mem\\[([0-9]+)\\] = ([0-9]+)");
			std::smatch matches;

			if (startsWith(line, "mask"))
			{
				// Add "mask" instruction:
				instrs.emplace_back(line.substr(7));
			}
			else if (startsWith(line, "mem"))
			{
				// Number of matches == 3: the whole string plus the two capture groups
				if (std::regex_search(line, matches, instrPattern) && matches.size() == 3)
				{
					uint64_t addr = std::strtoull(matches[1].str().c_str(), nullptr, 10);
					uint64_t val = std::strtoull(matches[2].str().c_str(), nullptr, 10);
					instrs.emplace_back(addr, val);
				}
			}
		}
		
		return instrs;
	}
}

