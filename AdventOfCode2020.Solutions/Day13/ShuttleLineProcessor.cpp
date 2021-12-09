#include "ShuttleLineProcessor.h"
#include "Utils.h"

namespace AdventOfCode::Year2020::Day13
{
	std::pair<std::vector<ShuttleLine>, int> ShuttleLineProcessor::Process(std::vector<std::string> input)
	{
		std::vector<ShuttleLine> availableLines;
		int timestamp = 0;

		if (!input.empty())
		{
			// first line: contains the earliest departure timestamp
			timestamp = atoi(input[0].c_str());

			// second line: contains all bus lines, separated by ','; lines unavailable will be marked by 'x'
			availableLines = SplitLine<ShuttleLine>(input[1], ',', 
				[](const std::string& line) { return ShuttleLine(atoi(line.c_str())); },
				[](const std::string& line) { return line.compare("x") != 0; });
		}

		return std::make_pair(availableLines, timestamp);
	}
}

