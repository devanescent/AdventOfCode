#include "NavInstructionProcessor.h"

namespace AdventOfCode::Year2020::Day12
{
	std::vector<NavInstruction> NavInstructionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<NavInstruction> navInstrs;

		for (const std::string& line : input)
		{
			int value = atoi(line.c_str() + 1);

			switch (line[0])
			{
				case 'N': navInstrs.push_back(NavInstruction(NavDirection::N, value)); break;
				case 'E': navInstrs.push_back(NavInstruction(NavDirection::E, value)); break;
				case 'S': navInstrs.push_back(NavInstruction(NavDirection::S, value)); break;
				case 'W': navInstrs.push_back(NavInstruction(NavDirection::W, value)); break;
				case 'L': navInstrs.push_back(NavInstruction(NavDirection::L, value)); break;
				case 'R': navInstrs.push_back(NavInstruction(NavDirection::R, value)); break;
				case 'F': navInstrs.push_back(NavInstruction(NavDirection::F, value)); break;
			}
		}

		return navInstrs;
	}
}

