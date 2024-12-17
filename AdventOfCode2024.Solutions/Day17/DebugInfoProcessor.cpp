#include "DebugInfoProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day17
{
	std::pair<std::vector<int>, Registers> DebugInfoProcessor::Process(std::vector<std::string> input)
	{
		// First three lines: register values
		Registers registers;
		registers.A = std::stoull(input[0].substr(12));
		registers.B = std::stoull(input[1].substr(12));
		registers.C = std::stoull(input[2].substr(12));

		// Last line: program
		std::vector<int> program;
		std::istringstream iss(input.back());
		
		std::string ignore;
		iss >> ignore;
		
		int val;
		char comma;
		while (iss >> val)
		{
			program.push_back(val);
			iss >> comma;
		}

		return std::make_pair(program, registers);
	}
}
